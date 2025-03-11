/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viktoria <viktoria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 10:26:47 by viktoria          #+#    #+#             */
/*   Updated: 2025/03/11 12:44:54 by viktoria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <map>
#include <stdexcept>
#include <ctime>
#include <tuple>

class BitcoinExchange
{
private:
    static const float MIN_VALUE;
    static const float MAX_VALUE;
    static const int BASE_YEAR;
    static const int MONTH_OFFSET;
    static const int DEFAULT_HOUR;
    static const int DEFAULT_MINUTE;
    static const int DEFAULT_SECOND;
    std::map<std::string, float> _DB;
    float validateExchangeValue(std::string &str_value, bool isExchangeRate);
    void parseDate(const std::string &dateString, struct tm &date);
    void normalizeDate(const struct tm &date, struct tm &normalizedDate);
    bool isInvalidDate(const struct tm &date, const struct tm &normalizedDate);
    void validateDateFormat(std::string &dateString);
    std::tuple<std::string, std::string> splitLine(std::string line, std::string delimiter);

public:
    BitcoinExchange();
    BitcoinExchange(const BitcoinExchange &o);
    BitcoinExchange &operator=(const BitcoinExchange &o);
    ~BitcoinExchange();

    void loadExchangeRates();
    void exchange(const char *toExchange);
    void printExchangeRates();
};