/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viktoria <viktoria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 07:57:55 by viktoria          #+#    #+#             */
/*   Updated: 2025/03/24 11:39:05 by viktoria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() { _readCSV(); }

BitcoinExchange::BitcoinExchange(BitcoinExchange const &src) : _csvData(src._csvData) {}

BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange const &src)
{
    if (this != &src)
    {
        _csvData.clear();
        _csvData = src._csvData;
    }
    return *this;
}

BitcoinExchange::~BitcoinExchange() {}

void BitcoinExchange::_readCSV()
{
    std::ifstream infile("data.csv");
    if (!infile)
        throw std::runtime_error("failed to open file: data.csv");
    std::string line;
    if (!std::getline(infile, line) || line != "date,exchange_rate")
        throw std::runtime_error("invalid database file: first line is not: date,exchange_rate");
    while (std::getline(infile, line))
    {
        try
        {
            std::string date;
            float rate;
            std::stringstream streamLine(line);
            getline(streamLine, date, ',');
            BitcoinExchange::checkInputFileValidDate(date);
            streamLine >> rate;
            _csvData.insert({date, rate});
        }
        catch (std::exception &e)
        {
            _csvData.clear();
            throw std::runtime_error("database loading failed: " + std::string(e.what()));
        }
    }
    infile.close();
}

void BitcoinExchange::checkInputFileLine(std::string line)
{
    std::regex lineFormat(R"(\d{4}-\d{2}-\d{2}\s*\|\s*-?\d+(\.\d+)?)");
    if (!std::regex_match(line, lineFormat))
    {
        throw std::runtime_error("bad input: " + line);
    }
}

std::string BitcoinExchange::trimSpaces(std::string str)
{
    size_t first = str.find_first_not_of(" ");
    if (first == std::string::npos)
        return "";
    size_t last = str.find_last_not_of(" ");
    return (str.substr(first, (last - first + 1)));
}

void BitcoinExchange::checkInputFileValidDate(std::string date)
{
    std::istringstream streamDate(date);
    std::tm tm = {};
    streamDate >> std::get_time(&tm, "%Y-%m-%d");
    if (streamDate.fail())
        throw std::runtime_error("not a valid date: " + date);
    tm.tm_isdst = -1;
    time_t timeCheck = std::mktime(&tm);
    if (timeCheck == -1)
        throw std::runtime_error("not a valid date: " + date);
    char buffer[11];
    std::strftime(buffer, sizeof(buffer), "%Y-%m-%d", &tm);
    if (date != buffer)
        throw std::runtime_error("not a valid date: " + date);
}

void BitcoinExchange::checkInputFileValidValue(float *value, std::string stringFloatValue)
{
    *value = stof(stringFloatValue);
    if (*value < 0 || *value > 1000)
        throw std::runtime_error("not a valid value: " + stringFloatValue + ", value must be in range 0 / 1000");
}

void BitcoinExchange::performExchange(std::string path)
{
    std::ifstream infile(path);
    if (!infile)
        throw std::runtime_error("failed to open file: " + path);
    std::string line;
    if (!std::getline(infile, line) || line != "date | value")
        throw std::runtime_error("invalid input file: first line is not: date | value");
    while (std::getline(infile, line))
    {
        try
        {
            BitcoinExchange::checkInputFileLine(line);
            std::string date;
            float value;
            std::string stringFloatValue;
            std::stringstream streamLine(line);
            getline(streamLine, date, '|');
            date = trimSpaces(date);
            getline(streamLine, stringFloatValue);
            stringFloatValue = trimSpaces(stringFloatValue);
            BitcoinExchange::checkInputFileValidDate(date);
            BitcoinExchange::checkInputFileValidValue(&value, stringFloatValue);
            std::map<std::string, float>::iterator i = _csvData.find(date);
            if (i != _csvData.end())
                std::cout << date << " => " << value << " = " << (i->second * value) << std::endl;
            else
            {
                std::map<std::string, float>::iterator j = _csvData.lower_bound(date);
                if (j == _csvData.begin())
                {
                    std::cout << "Warning: no closest lower date found for: " << date << " - closest upper date exchange is: "
                              << j->first << " => " << value << " = " << (j->second * value) << std::endl;
                }
                else
                {
                    --j;
                    std::string closestLowerDate = j->first;
                    std::cout << closestLowerDate << " => " << value << " = " << (j->second * value) << std::endl;
                }
            }
        }
        catch (std::exception &e)
        {
            std::cout << "Error in input file: " << e.what() << std::endl;
        }
    }
    infile.close();
}