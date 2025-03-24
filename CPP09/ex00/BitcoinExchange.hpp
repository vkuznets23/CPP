/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viktoria <viktoria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 07:57:54 by viktoria          #+#    #+#             */
/*   Updated: 2025/03/24 11:38:48 by viktoria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <map>
#include <fstream>
#include <sstream>
#include <regex>
#include <iomanip>
#include <ctime>

class BitcoinExchange
{
private:
    std::map<std::string, float> _csvData;
    void _readCSV();

public:
    BitcoinExchange();
    BitcoinExchange(BitcoinExchange const &src);
    BitcoinExchange &operator=(BitcoinExchange const &src);
    ~BitcoinExchange();

    void performExchange(std::string path);
    void checkInputFileLine(std::string line);
    std::string trimSpaces(std::string str);
    void checkInputFileValidDate(std::string date);
    void checkInputFileValidValue(float *value, std::string stringFloatValue);
};