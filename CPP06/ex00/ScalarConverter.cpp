#include "ScalarConverter.hpp"

char ScalarConverter::c;
int ScalarConverter::i;
float ScalarConverter::f;
double ScalarConverter::d;

void ScalarConverter::convert(const std::string &str)
{
    std::regex int_(R"(^[-+]?\d+$)");
    std::regex float_("^[-+]?\\d*\\.\\d+$");
    std::regex double_("^[-+]?\\d*\\.\\d+([eE][-+]?\\d+)?$");

    if (std::regex_match(str, int_))
    {
        convertFromInt(str);
    }
    else if (str == "inff" || str == "-inff" || str == "+inff" || std::regex_match(str, float_))
    {
        convertFromFloat(str);
    }
    else if (str == "inf" || str == "-inf" || str == "+inf" || std::regex_match(str, double_))
    {
        convertFromDouble(str);
    }
    else if (str.length() == 1)
    {
        convertFromChar(str);
    }
    else
    {
        std::cout << "Error: " << str << " is not a valid float, double, or char." << std::endl;
    }
}

void ScalarConverter::convertFromInt(const std::string &str)
{
    try
    {
        i = std::stoi(str);
        f = i;
        d = i;
        // ASCII values conversion, if fails its -1
        c = i >= 0 && i <= 127 ? static_cast<char>(i) : -1;
        printValues();
    }
    catch (std::out_of_range &e)
    {
        convertFromFloat(str);
    }
}

void ScalarConverter::convertFromFloat(const std::string &str)
{
}