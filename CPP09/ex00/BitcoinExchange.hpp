/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuznets <vkuznets@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 07:57:54 by viktoria          #+#    #+#             */
/*   Updated: 2025/03/25 10:30:01 by vkuznets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <ctime>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <regex>
#include <sstream>

class BitcoinExchange
{
  private:
    std::map<std::string, float> _csvData;
    void _loadExchangeRates();

  public:
    BitcoinExchange();
    BitcoinExchange(BitcoinExchange const &src);
    BitcoinExchange &operator=(BitcoinExchange const &src);
    ~BitcoinExchange();

    void performExchange(std::string path);
    void validateInputLine(std::string line);
    std::string trimSpaces(std::string str);
    void validateDate(std::string date);
    void validateValue(float *value, std::string stringFloatValue);
};