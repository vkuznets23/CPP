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

#include <iostream>
#include <string>
#include "ScalarConverter.hpp"

int main()
{
    // Test Case 1: Single Character
    std::cout << "[Test 1] Character input: 'a'\n";
    ScalarConverter::convert("a"); // Should print 'char: 'a''

    // Test Case 2: Integer Input
    std::cout << "[Test 2] Integer input: '42'\n";
    ScalarConverter::convert("42"); // Should print 'int: 42', 'char: *', 'float: 42.0f', 'double: 42.0'

    // Test Case 3: Floating Point Input (with 'f' suffix)
    std::cout << "[Test 3] Floating point input: '4.2f'\n";
    ScalarConverter::convert("4.2f"); // Should print 'int: 4', 'char: Non displayable', 'float: 4.2f', 'double: 4.2'

    // Test Case 4: Double Input
    std::cout << "[Test 4] Double input: '42.5'\n";
    ScalarConverter::convert("42.5"); // Should print 'int: 42', 'char: *', 'float: 42.5f', 'double: 42.5'

    // Test Case 5: Non-printable Character (e.g., ASCII 0)
    std::cout << "[Test 5] Non-displayable character input: '\x00'\n";
    ScalarConverter::convert("\x00"); // Should print 'char: impossible', 'int: 0', 'float: 0.0f', 'double: 0.0'

    // Test Case 6: Special float values 'inf' and '-inf'
    std::cout << "[Test 6] Special float value: 'inff'\n";
    ScalarConverter::convert("inff"); // Should print 'float: inff', 'double: inf'

    std::cout << "[Test 7] Special float value: '-inff'\n";
    ScalarConverter::convert("-inff"); // Should print 'float: -inff', 'double: -inf'

    std::cout << "[Test 8] Special float value: '+inff'\n";
    ScalarConverter::convert("+inff"); // Should print 'float: +inff', 'double: +inf'

    // Test Case 7: NaN (Not a Number)
    std::cout << "[Test 9] Special NaN value: 'nan'\n";
    ScalarConverter::convert("nan"); // Should print 'float: nanf', 'double: nan'

    // Test Case 8: Invalid input, which is not convertible
    std::cout << "[Test 10] Invalid input: 'Hello'\n";
    ScalarConverter::convert("Hello"); // Should print 'char: impossible', 'int: impossible', 'float: impossible', 'double: impossible'

    // Test Case 9: Edge case with a very large number
    std::cout << "[Test 11] Edge case with large float: '1e308'\n";
    ScalarConverter::convert("1e308"); // Should print 'char: impossible', 'int: impossible', 'float: impossible', 'double: 1e+308'

    // Test Case 10: Valid float with large exponent (scientific notation)
    std::cout << "[Test 12] Valid float with large exponent: '1.234e5'\n";
    ScalarConverter::convert("1.234e5"); // Should print 'int: 123400', 'char: Non displayable', 'float: 123400.0f', 'double: 123400.0'

    // Test Case 11: Large negative number
    std::cout << "[Test 13] Negative number: '-1234567'\n";
    ScalarConverter::convert("-1234567"); // Should print 'int: -1234567', 'char: impossible', 'float: -1234567.0f', 'double: -1234567.0'

    // Test Case 12: Edge case: very small float that is too small to represent
    std::cout << "[Test 14] Very small float: '1.0e-40f'\n";
    ScalarConverter::convert("1.0e-40f"); // Should print 'int: 0', 'char: Non displayable', 'float: 1.0e-40f', 'double: 1.0e-40'

    return 0;
}
