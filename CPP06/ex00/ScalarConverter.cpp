/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuznets <vkuznets@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 09:44:00 by vkuznets          #+#    #+#             */
/*   Updated: 2025/02/12 13:19:53 by vkuznets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

char ScalarConverter::c;
int ScalarConverter::i;
float ScalarConverter::f;
double ScalarConverter::d;

void ScalarConverter::convert(const std::string &str)
{
    // define patterns for different number types
    std::regex int_("[-\\+]?\\d+");
    std::regex float_("[-\\+]?\\d+\\.\\d*f|\\d*\\.\\d+f");
    std::regex double_("[-\\+]?\\d+\\.\\d*|\\d*\\.\\d+");

    if (std::regex_match(str, int_))
        convertFromInt(str);
    else if (str.length() == 1)
        convertFromChar(str);
    else if (str == "inff" || str == "+inff" || str == "-inff" || std::regex_match(str, float_))
        convertFromFloat(str);
    else if (str == "inf" || str == "+inf" || str == "-inf" || std::regex_match(str, double_))
        convertFromDouble(str);
    else
    {
        // undisplayble
        std::cout << "char: impossible\n"
                  << "int: impossible\n";
        std::cout << (str == "nan" ? "float: nanf\ndouble: nan\n" : "float: impossible\ndouble: impossible\n");
    }
}
