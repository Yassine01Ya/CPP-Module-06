#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::ScalarConverter(const ScalarConverter &sc)
{
    (void)sc;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &sc)
{
    (void)sc;
    return *this;
}

ScalarConverter::~ScalarConverter()
{
}

static void ConvertChar(std::string _string)
{
    std::cout << "-------------------------------";
    std::cout << "\nFrom ConvertChar Function. \n";
    std::cout << "-----------------------------\n";
    if (std::isprint(_string[0]) && std::isdigit(_string[0]) == 0)
    {
        std::cout << "char: " << _string[0] << "\n";
        std::cout << "int: " << static_cast<int>(_string[0]) << "\n";
        std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(_string[0]) << "f\n";
        std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(_string[0]) << "\n";
    }
    else
    {
        std::cout << "char: " << "Non displayable" << "\n";
        std::cout << "int: " << atoi(_string.c_str()) << "\n";
        std::cout << "float: " << std::fixed << std::setprecision(1) << atof(_string.c_str()) << "f\n";
        std::cout << "double: " << std::fixed << std::setprecision(1) << atof(_string.c_str()) << "\n";
    }
}

static void ConvertInt(std::string _string)
{
    std::cout << "-------------------------------";
    std::cout << "\nFrom ConvertInt Function. \n";
    std::cout << "-----------------------------\n";
    double _result = strtod(_string.c_str(), NULL);
    if (_result <= INT_MAX && _result >= INT_MIN)
    {
        if (_result >= 32 && _result <= 126)
            std::cout << "char: " << static_cast<char>(_result) << "\n";
        else if (_result <= 31 || _result >= 127)
            std::cout << "char: Non Printable\n";
        std::cout << "int: " << static_cast<int>(_result) << "\n";
    }
    else
    {
        std::cout << "char: impossible\n";
        if (_result == -INFINITY || _result == INFINITY || _string == "nanf")
            std::cout << "int: impossible\n";
        else
            std::cout << "int: Overflow\n";
    }
    std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(_result) << "f\n";
    std::cout << "double: " << std::fixed << std::setprecision(1) << _result << '\n';
}

static void ConvertFloat(std::string _string)
{
    std::cout << "--------------------------------";
    std::cout << "\nFrom ConvertFloat Function. \n";
    std::cout << "------------------------------\n";
    double _result = strtod(_string.c_str(), NULL);
    if (_result <= INT_MAX && _result >= INT_MIN)
    {
        if (_result >= 32 && _result <= 126)
            std::cout << "char: " << static_cast<char>(_result) << '\n';
        else if (_result <= 31 || _result >= 127)
            std::cout << "char: Non Printable\n";
        std::cout << "int: " << static_cast<int>(_result) << '\n';
    }
    else
    {
        std::cout << "char: impossible\n";
        if (_result == -INFINITY || _result == INFINITY || _string == "nanf")
            std::cout << "int: impossible\n";
        else
            std::cout << "int: Overflow\n";
    }
    std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(_result) << "f\n";
    std::cout << "double: " << std::fixed << std::setprecision(1) << _result << '\n';
}

static void ConvertDouble(std::string _string)
{
    std::cout << "---------------------------------";
    std::cout << "\nFrom ConvertDouble Function. \n";
    std::cout << "-------------------------------\n";
    double _result = strtod(_string.c_str(), NULL);
    if (_result <= INT_MAX && _result >= INT_MIN)
    {
        if (_result >= 32 && _result <= 126)
            std::cout << "char: " << static_cast<char>(_result) << '\n';
        else if (_result <= 31 || _result >= 127)
            std::cout << "char: Non Printable\n";
        std::cout << "int: " << static_cast<int>(_result) << '\n';
    }
    else
    {
        std::cout << "char: impossible\n";
        if (_result == -INFINITY || _result == INFINITY || _string == "nan")
            std::cout << "int: impossible\n";
        else
            std::cout << "int: Overflow\n";
    }
    std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(_result) << "f\n";
    std::cout << "double: " << std::fixed << std::setprecision(1) << _result << '\n';
}
static void stringParser(std::string _string)
{
    size_t i = 0;
    bool has_dot = false;
    for (; i < _string.length(); i++)
    {
        if ((_string[i] == '-' || _string[i] == '+'))
        {
            if (i != 0)
            {
                std::cout << "Bad String Input.\n";
                return;
            }
        }
        else if (_string[i] == '.' && i > 0 && std::isdigit(_string[i - 1]))
        {
            if (has_dot)
            {
                std::cout << "Bad String Input.\n";
                return;
            }
            has_dot = true;
        }
        else if (std::isdigit(_string[i]) == 0)
            break;
    }
    if (i != _string.length())
    {
        if (_string == "inf" || _string == "+inf" || _string == "-inf" || _string == "nan")
        {
            // std::cout << "1\n";
            ConvertDouble(_string);
        }
        else if (_string == "inff" || _string == "+inff" || _string == "-inff" || _string == "nanf")
        {
            // std::cout << "2\n";
            ConvertFloat(_string);
        }
        else if (_string[i] == 'f' && i == _string.length() - 1 && i > 0 && std::isdigit(_string[i - 1]))
        {
            // std::cout << "3\n";
            ConvertFloat(_string);
        }
        else
        {
            std::cout << "Bad String Input.\n";
            // std::cout << "4\n";
        }
    }
    else
    {
        std::cout << "i = " << i << std::endl;
        if (i == 0 || std::isdigit(_string[i - 1]) == 0)
            std::cout << "Bad String Input.\n";
        else if (has_dot)
            ConvertDouble(_string);
        else
            ConvertInt(_string);
    }
}

void ScalarConverter::convert(std::string _string)
{
    if (_string.empty())
        std::cout << "Empty string input\n";
    if (_string.length() == 1)
        ConvertChar(_string);
    else
        stringParser(_string);
}
