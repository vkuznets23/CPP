/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viktoria <viktoria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 10:31:53 by viktoria          #+#    #+#             */
/*   Updated: 2025/03/11 13:07:01 by viktoria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

const float BitcoinExchange::MIN_VALUE = 0.0f;
const float BitcoinExchange::MAX_VALUE = 1000.0f;
const int BitcoinExchange::BASE_YEAR = 1900;
const int BitcoinExchange::MONTH_OFFSET = 1;
const int BitcoinExchange::DEFAULT_HOUR = 1;
const int BitcoinExchange::DEFAULT_MINUTE = 0;
const int BitcoinExchange::DEFAULT_SECOND = 0;

BitcoinExchange::BitcoinExchange() {}
BitcoinExchange::BitcoinExchange(const BitcoinExchange &o) : _DB(o._DB) {}
// BitcoinExchange::BitcoinExchange(const BitcoinExchange &o) {}
BitcoinExchange::~BitcoinExchange() {}

float BitcoinExchange::validateExchangeValue(std::string &str_value, bool isExchangeRate)
{
    float res = std::stof(str_value);

    if (isExchangeRate && (res < MIN_VALUE || res > MAX_VALUE))
        throw std::runtime_error("Invalid value: " + str_value + ". Must be in range " + std::to_string(MIN_VALUE) + " to " + std::to_string(MAX_VALUE) + ".");

    return res;
}

void BitcoinExchange::parseDate(const std::string &dateString, struct tm &date)
{
    std::stringstream dateStream(dateString);
    char separator;
    dateStream >> date.tm_year >> separator >> date.tm_mon >> separator >> date.tm_mday;

    date.tm_year -= BASE_YEAR;
    date.tm_mon -= MONTH_OFFSET;
    date.tm_hour = DEFAULT_HOUR;
    date.tm_min = DEFAULT_MINUTE;
    date.tm_sec = DEFAULT_SECOND;
}

void BitcoinExchange::normalizeDate(const struct tm &date, struct tm &normalizedDate)
{
    normalizedDate = date;
    mktime(&normalizedDate);
}

bool BitcoinExchange::isInvalidDate(const struct tm &date, const struct tm &normalizedDate)
{
    return date.tm_year != normalizedDate.tm_year || date.tm_mon != normalizedDate.tm_mon || date.tm_mday != normalizedDate.tm_mday;
}

void BitcoinExchange::validateDateFormat(std::string &dateString)
{
    struct tm date, normalizedDate;

    parseDate(dateString, date);
    normalizeDate(date, normalizedDate);

    if (isInvalidDate(date, normalizedDate))
        throw std::runtime_error("Invalid date: " + dateString);
}

void BitcoinExchange::printExchangeRates()
{
    for (std::map<std::string, float>::const_iterator itr = _DB.begin(); itr != _DB.end(); itr++)
        std::cout << itr->first << " " << itr->second << std::endl;
}

void BitcoinExchange::loadExchangeRates()
{
    std::string line, date, str_rate;
    float rate;

    std::ifstream inputFile("./data.csv");
    if (!inputFile.is_open())
        throw(std::runtime_error("Couldn't load rates file"));
    if (!std::getline(inputFile, line) || line != "date,exchange_rate")
        throw(std::runtime_error("Invalid rates file"));

    while (std::getline(inputFile, line))
    {
        try
        {
            tie(date, str_rate) = BitcoinExchange::splitLine(line, ",");
            BitcoinExchange::validateDateFormat(date);
            rate = BitcoinExchange::validateExchangeValue(str_rate, false);
            _DB.insert(std::make_pair(date, rate));
        }
        catch (std::exception &e)
        {
            std::cerr << "Error in rates file: " << e.what() << std::endl;
        }
    }
}

void BitcoinExchange::exchange(const char *toExchange)
{
    std::string line, date, closest_date, str_quantity;
    float quantity;
    std::map<std::string, float>::iterator itr;

    std::ifstream inputFile(toExchange);
    if (!inputFile.is_open())
        throw(std::runtime_error("Couldn't load exchange file"));
    if (!std::getline(inputFile, line) || line != "date | value")
        throw(std::runtime_error("Invalid exchange file"));

    while (std::getline(inputFile, line))
    {
        try
        {
            tie(date, str_quantity) = BitcoinExchange::splitLine(line, " | ");
            BitcoinExchange::validateDateFormat(date);
            quantity = BitcoinExchange::validateExchangeValue(str_quantity, true);
            if (_DB.find(date) == _DB.end())
            {
                itr = _DB.lower_bound(date);
                closest_date = (itr == _DB.begin()) ? itr->first : std::prev(itr)->first;
            }
            else
                closest_date = date;
            std::cout << date << " => " << quantity << " = " << quantity * _DB[closest_date] << std::endl;
        }
        catch (std::exception &e)
        {
            std::cerr << "Error in exchange file: " << e.what() << std::endl;
        }
    }
}

std::tuple<std::string, std::string> BitcoinExchange::splitLine(std::string line, std::string delimiter)
{
    std::string left, right;
    size_t delim_pos;

    if (!line.empty())
        delim_pos = line.find(delimiter);

    if (line.empty() || delim_pos == std::string::npos)
        throw(std::runtime_error("Invalid line: \"" + line + "\""));

    left = line.substr(0, delim_pos);
    delim_pos += delimiter.length();
    right = line.substr(delim_pos, line.length() - delim_pos);

    if (left.empty() || right.empty())
        throw std::runtime_error("lineSplit: empty left or right part");

    return std::make_tuple(left, right);
}
