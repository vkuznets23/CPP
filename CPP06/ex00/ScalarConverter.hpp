#pragma once
#include <iostream>
#include <regex>
#include <string>
#include <cmath>
#include <iomanip>
#include <limits>

// should be abstract sxo we cannot instaniate it
class ScalarConverter
{
public:
  static void convert(const std::string &str);

private:
  ScalarConverter() = default;
  ScalarConverter(const ScalarConverter &origin) = default;
  ScalarConverter &operator=(const ScalarConverter &origin) = default;
  ~ScalarConverter() = default;
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