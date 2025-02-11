#pragma once
#include <iostream>
#include <regex>
#include <string>
#include <cmath>
#include <iomanip>
#include <limits>

class ScalarConverter
{
public:
  static void convert(const std::string &str);

private:
  ScalarConverter() = delete;
  ScalarConverter(const ScalarConverter &origin) = delete;
  ScalarConverter &operator=(const ScalarConverter &origin) = delete;
  ~ScalarConverter() = delete;

  static void convertFromInt(const std::string &str);
  static void convertFromFloat(const std::string &str);
  static void convertFromDouble(const std::string &str);
  static void convertFromChar(const std::string &str);
  static void printValues();

  static char c;
  static int i;
  static float f;
  static double d;
};