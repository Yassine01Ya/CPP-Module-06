#pragma once
#include <iostream>
#include <string>
#include <cmath>
#include <climits>
#include <limits>
#include <iomanip>
// #include <iostream>

class ScalarConverter
{
private:
    ScalarConverter();
    ScalarConverter(const ScalarConverter &sc);
    ScalarConverter &operator=(const ScalarConverter &sc);
    ~ScalarConverter();

public:
    static void convert(std::string _string);
};
