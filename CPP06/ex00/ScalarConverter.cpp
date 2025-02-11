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
        std::cout << (str == "nan" ? "float: nanf\ndouble: nan\n"
                                   : "float: impossible\ndouble: impossible\n");
    }
}

void ScalarConverter::convertFromInt(const std::string &str)
{
    try
    {
        i = std::stoi(str); // string to integer
        c = i >= 0 && i <= 127 ? static_cast<char>(i) : -1;
        f = i;
        d = i;
        printValues();
    }
    catch (std::out_of_range &e)
    {
        // if number is too big for int but its still good for double and float
        convertFromFloat(str);
    }
}

void ScalarConverter::convertFromChar(const std::string &str)
{
    c = str[0];
    i = c;
    f = c;
    d = c;
    printValues();
}

void ScalarConverter::convertFromFloat(const std::string &str)
{
    try
    {
        f = std::stof(str); // str to float
        d = f;

        // check for overflow
        if ((d > 0.0 && d - std::numeric_limits<int>::max() >= 1.0) ||
            (d < 0.0 && d - std::numeric_limits<int>::min() <= -1.0))
        {
            c = -1;
            i = 1001;
        }
        else
        {
            i = static_cast<int>(f);
            // is it in the char scope?
            c = i >= 0 && i <= 127 ? static_cast<char>(i) : -1;
        }
        printValues();
    }
    catch (std::out_of_range &e)
    {
        // in case if its too big for float but good for double
        convertFromDouble(str);
    }
}

void ScalarConverter::convertFromDouble(const std::string &str)
{
    try
    {
        d = std::stod(str);

        // overflow for float and check if its +inf or -inf
        if (!std::isinf(d) &&
            ((d > 0.0 && d - std::numeric_limits<float>::max() >= 1.0) ||
             (d < 0.0 && d - std::numeric_limits<float>::lowest() <= -1.0)))
        {
            c = -1;
            i = 1000;
            f = std::numeric_limits<float>::max();
        }
        else if ((d > 0.0f && d - std::numeric_limits<int>::max() >= 1.0) ||
                 (d < 0.0f && d - std::numeric_limits<int>::min() <= -1.0))
        {
            c = -1;
            i = 1000;
            f = static_cast<float>(d);
        }
        else
        {
            i = static_cast<int>(d);
            f = static_cast<float>(d);
            c = i >= 0 && i <= 127 ? static_cast<char>(i) : -1;
        }
        printValues();
    }
    catch (std::out_of_range &e)
    {
        std::cout << "char: impossible\n"
                  << "int: impossible\n"
                  << "float: impossible\n"
                  << "double: impossible\n";
    }
}

void ScalarConverter::printValues()
{
    if (std::isprint(c))
    {
        std::cout << "char: '" << c << "'\n";
    }
    else
    {
        std::cout << "char: "
                  << (i >= 0 && i <= 127 ? "Non displayable" : "impossible") << std::endl;
    }
    if ((d > 0.0 && d - std::numeric_limits<int>::max() >= 1.0) ||
        (d < 0.0 && d - std::numeric_limits<int>::min() <= -1.0))
    {
        std::cout << "int: impossible\n";
    }
    else
    {
        std::cout << "int: " << i << '\n';
    }
    if (!std::isinf(d) &&
        ((d > 0.0 && d - std::numeric_limits<float>::max() >= 1.0) ||
         (d < 0.0 && d - std::numeric_limits<float>::lowest() <= -1.0)))
    {
        std::cout << "float: impossible\n";
    }
    else
    {
        std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f\n";
    }
    std::cout << "double: " << std::fixed << std::setprecision(1) << d << '\n';
}
