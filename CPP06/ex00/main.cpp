/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuznets <vkuznets@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 09:44:11 by vkuznets          #+#    #+#             */
/*   Updated: 2025/02/12 13:20:14 by vkuznets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

// int main(int argc, char **argv)
// {
//     if (argc != 2)
//     {
//         std::cerr << "Usage: " << argv[0] << " <literal>\n";
//         return 1;
//     }

//     std::string input = argv[1];
//     ScalarConverter::convert(input);

//     return 0;
// }

void checkint()
{
    std::cout << "INTEGERS" << std::endl;
    ScalarConverter::convert("42"); // Integer within valid range
    std::cout << "__________________" << std::endl;
    ScalarConverter::convert("-42"); // Negative integer
    std::cout << "__________________" << std::endl;
    ScalarConverter::convert("0"); // Zero
    std::cout << "__________________" << std::endl;
    ScalarConverter::convert("2147483647"); // Maximum integer
    std::cout << "__________________" << std::endl;
    ScalarConverter::convert("2147483648"); // Overflow
    std::cout << "__________________" << std::endl;
    ScalarConverter::convert("-2147483648"); // Minimum integer
    std::cout << "__________________" << std::endl;
    ScalarConverter::convert("-2147483650"); // Overflow !!!
}

void checkchar()
{
    std::cout << "CHAR" << std::endl;
    ScalarConverter::convert("a"); // Single character
    std::cout << "__________________" << std::endl;
    ScalarConverter::convert("b"); // Another character
    std::cout << "__________________" << std::endl;
    ScalarConverter::convert("z"); // Edge case with a valid character
    std::cout << "__________________" << std::endl;
    ScalarConverter::convert("\n"); // Non-displayable character (newline)
    std::cout << "__________________" << std::endl;
    ScalarConverter::convert(" "); // Space (valid but whitespace)
}

void checkfloat()
{
    std::cout << "FLOAT" << std::endl;
    ScalarConverter::convert("42.0f"); // Simple float
    std::cout << "__________________" << std::endl;
    ScalarConverter::convert("-42.0f"); // Negative float
    std::cout << "__________________" << std::endl;
    ScalarConverter::convert("0.0f"); // Zero float
    std::cout << "__________________" << std::endl;
    ScalarConverter::convert("3.14f"); // Pi approximation
    std::cout << "__________________" << std::endl;
    ScalarConverter::convert("1.5e2f"); // Scientific notation
    std::cout << "__________________" << std::endl;
    ScalarConverter::convert("inff"); // Special case: infinity (float)
    std::cout << "__________________" << std::endl;
    ScalarConverter::convert("+inff"); // Special case: positive infinity (float)
    std::cout << "__________________" << std::endl;
    ScalarConverter::convert("-inff"); // Special case: negative infinity (float)
    std::cout << "__________________" << std::endl;
    ScalarConverter::convert("nanf"); // Special case: NaN (float)
}

void checkdouble()
{
    std::cout << "DOUBLE" << std::endl;
    ScalarConverter::convert("42.0"); // Simple double
    std::cout << "__________________" << std::endl;
    ScalarConverter::convert("-42.0"); // Negative double
    std::cout << "__________________" << std::endl;
    ScalarConverter::convert("0.0"); // Zero double
    std::cout << "__________________" << std::endl;
    ScalarConverter::convert("3.14159"); // Pi approximation as double
    std::cout << "__________________" << std::endl;
    ScalarConverter::convert("1.5e2"); // Scientific notation (double)
    std::cout << "__________________" << std::endl;
    ScalarConverter::convert("inf"); // Special case: infinity (double)
    std::cout << "__________________" << std::endl;
    ScalarConverter::convert("+inf"); // Special case: positive infinity (double)
    std::cout << "__________________" << std::endl;
    ScalarConverter::convert("-inf"); // Special case: negative infinity (double)
    std::cout << "__________________" << std::endl;
    ScalarConverter::convert("nan"); // Special case: NaN (double)
}

void checkInvalidInputs()
{
    std::cout << "INVALID INPUTS" << std::endl;
    ScalarConverter::convert("abc"); // Invalid string
    std::cout << "__________________" << std::endl;
    ScalarConverter::convert(" "); // Invalid space input
    std::cout << "__________________" << std::endl;
    ScalarConverter::convert("NaN"); // Invalid string input (case-sensitive)
    std::cout << "__________________" << std::endl;
    ScalarConverter::convert("infinity"); // Invalid, should not be recognized as float/double
    std::cout << "__________________" << std::endl;
    ScalarConverter::convert("123abc"); // Invalid integer with letters
    std::cout << "__________________" << std::endl;
    ScalarConverter::convert("f"); // Invalid char input
    std::cout << "__________________" << std::endl;
    ScalarConverter::convert("$$$"); // Invalid non-numeric string
}

void checkCharLimits()
{
    std::cout << "CHAR LIMIT" << std::endl;
    ScalarConverter::convert("127"); // Upper limit for char (ASCII)
    std::cout << "__________________" << std::endl;
    ScalarConverter::convert("128"); // Just over the char limit (should be impossible)
    std::cout << "__________________" << std::endl;
    ScalarConverter::convert("-1"); // Char lower bound (invalid)
}

int main()
{
    // Float is not so precise with big numbers do it get 2147483648 (not 7)
    // 3.1 or 3.9 => 3 (cos it just removes fractional part)
    checkint();
    checkchar();
    checkfloat();
    checkdouble();
    checkInvalidInputs();
    checkCharLimits();
}