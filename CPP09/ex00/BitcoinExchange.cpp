/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuznets <vkuznets@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 07:57:55 by viktoria          #+#    #+#             */
/*   Updated: 2025/03/25 10:30:58 by vkuznets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
    _loadExchangeRates();
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &src) : _csvData(src._csvData)
{
}

BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange const &src)
{
    if (this != &src)
    {
        _csvData.clear();
        _csvData = src._csvData;
    }
    return *this;
}

BitcoinExchange::~BitcoinExchange()
{
}

void BitcoinExchange::_loadExchangeRates()
{
    std::ifstream infile("data.csv");
    if (!infile)
        throw std::runtime_error("failed to open file: data.csv");

    std::string line;
    if (!std::getline(infile, line) || line != "date,exchange_rate")
        throw std::runtime_error("first line is not: date,exchange_rate");
    while (std::getline(infile, line))
    {
        try
        {
            std::string date;
            float rate;
            std::stringstream streamLine(line);
            getline(streamLine, date, ',');
            BitcoinExchange::validateDate(date);
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

void BitcoinExchange::validateInputLine(std::string line)
{
    // \d{4} - 4 digits
    // - - Matches a literal hyphen (-)
    // \s* → Matches zero or more whitespace characters
    // \| → Matches a literal pipe (|)
    // -? → Matches an optional minus sign
    // \d+ → Matches one or more digits
    // \. → Literal decimal point (.)

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

void BitcoinExchange::validateDate(std::string date)
{
    std::istringstream streamDate(date);
    std::tm tm = {};

    // Uses std::get_time to parse date into tm using the format "YYYY-MM-DD"
    streamDate >> std::get_time(&tm, "%Y-%m-%d");
    if (streamDate.fail())
        throw std::runtime_error("not a valid date: " + date);

    // Convert std::tm Struct to time_t to validate Impossible Dates
    // cos if an invalid day is given to std::tm structure, it rolls over instead of failing
    tm.tm_isdst = -1;
    time_t timeCheck = std::mktime(&tm);
    if (timeCheck == -1)
        throw std::runtime_error("not a valid date: " + date);

    // ensures that the input exactly matches the valid formatted date after conversion and normalization
    char buffer[11];
    std::strftime(buffer, sizeof(buffer), "%Y-%m-%d", &tm);
    if (date != buffer)
        throw std::runtime_error("not a valid date: " + date);
}

void BitcoinExchange::validateValue(float *value, std::string stringFloatValue)
{
    *value = stof(stringFloatValue);

    if (*value < 0 || *value > 1000)
        throw std::runtime_error("not a valid value: " + stringFloatValue + ", value must be in range from 0 to 1000");
}

void BitcoinExchange::performExchange(std::string path)
{
    // Open the Input File
    std::ifstream infile(path);
    if (!infile)
        throw std::runtime_error("failed to open file: " + path);

    std::string line;
    // Validate the Header Line
    if (!std::getline(infile, line) || line != "date | value")
        throw std::runtime_error("first line is not: date | value");

    // Read and Process Each Line
    while (std::getline(infile, line))
    {
        try
        {
            // Extract and Clean Up Data
            BitcoinExchange::validateInputLine(line);
            std::string date;
            float value;
            std::string stringFloatValue;
            std::stringstream streamLine(line);

            getline(streamLine, date, '|');
            date = trimSpaces(date);
            getline(streamLine, stringFloatValue);
            stringFloatValue = trimSpaces(stringFloatValue);

            // Validate the Date and Value
            BitcoinExchange::validateDate(date);
            BitcoinExchange::validateValue(&value, stringFloatValue);

            // Find the Exchange Rate
            std::map<std::string, float>::iterator i = _csvData.find(date);
            // Case 1: Exact Match Found
            if (i != _csvData.end())
                std::cout << date << " => " << value << " = " << (i->second * value) << std::endl;
            // Case 2: No Exact Match - Find the Closest Date
            else
            {
                // lower_bound(date) finds the first date that is not less than the given date
                std::map<std::string, float>::iterator j = _csvData.lower_bound(date);

                // Case 2A: Closest Date is the Earliest in Data
                if (j == _csvData.begin())
                {
                    std::cout << "No closest lower date found for: " << date
                              << " - closest upper date exchange is: " << j->first << " => " << value << " = "
                              << (j->second * value) << std::endl;
                }
                // Case 2B: Find the Closest Past Date
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