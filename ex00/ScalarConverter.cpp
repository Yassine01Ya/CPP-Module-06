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
    if (std::isprint(_string[0]) && std::isdigit(_string[0]) == 0)
    {
        std::cout << "char: " << _string[0] << "\n";
        std::cout << "int: " << static_cast<int>(_string[0]) << "\n";
        std::cout << "float: " << static_cast<float>(_string[0]) << "f\n";
        std::cout << "double: " << static_cast<double>(_string[0]) << "\n";
    }
    else
    {
        std::cout << "char: " << "Non displayable" << "\n";
        std::cout << "int: " << atoi(_string.c_str()) << "\n";
        std::cout << "float: " << atof(_string.c_str()) << "f\n";
        std::cout << "double: " << atof(_string.c_str()) << "\n";
    }
}

static void ConvertInt(std::string _string)
{
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
        if (_result == -INFINITY || _result == INFINITY || _string == "nanf")
            std::cout << "int: Please enter valid number\n";
        else
            std::cout << "int: Overflow\n";
    }
    std::cout << "float: " << std::fixed << std::setprecision(2) << static_cast<float>(_result) << "f\n";
    std::cout << "double: " << std::fixed << std::setprecision(2) << _result << '\n';
}

static void ConvertFloat(std::string _string)
{
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
        if (_result == -INFINITY || _result == INFINITY || _string == "nanf")
            std::cout << "int: Please enter valid number\n";
        else
            std::cout << "int: Overflow\n";
    }
    std::cout << "float: " << std::fixed << std::setprecision(2) << static_cast<float>(_result) << "f\n";
    std::cout << "double: " << std::fixed << std::setprecision(2) << _result << '\n';
}

static void ConvertDouble(std::string _string)
{
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
        if (_result == -INFINITY || _result == INFINITY || _string == "nanf")
            std::cout << "int: Please enter valid number\n";
        else
            std::cout << "int: Overflow\n";
    }
    std::cout << "float: " << std::fixed << std::setprecision(2) << static_cast<float>(_result) << "f\n";
    std::cout << "double: " << std::fixed << std::setprecision(2) << _result << '\n';
}
static void stringParser(std::string _string)
{
    size_t i = 0;
    bool is_dot = false;
    for (; i < _string.length(); i++)
    {
        if ((_string[i] == '-' || _string[i] == '+'))
        {
            if (i != 0)
            {
                std::cout << "1Bad string input\n";
                return;
            }
            else if (_string[i] == '.' && i < 0 && std::isdigit(_string[i - 1]))
            {
                if (is_dot)
                {
                    std::cout << "2Bad string input\n";
                    return;
                }
                is_dot = true;
            }
            else if (std::isdigit(_string[i]) == 0)
                break;
        }
    }
    if (i != _string.length())
    {
        if (_string == "inff" || _string == "+inff" || _string == "-inff" || _string == "nanf")
            ConvertFloat(_string);
        else if (_string == "inf" || _string == "+inf" || _string == "-inf" || _string == "nan")
            ConvertDouble(_string);
        else if (_string[i] == 'f' && i == _string.length() - 1 && i > 0 && std::isdigit(_string[i - 1]))
            ConvertFloat(_string);
        else
            std::cout << "3Bad string input\n";
    }
    else
    {
        if (i == 0 || std::isdigit(_string[i - 1]) == 0)
            std::cout << "Bad string input\n";
        else if (is_dot)
            ConvertDouble(_string);
        else
            ConvertInt(_string);
    }
}

void ScalarConverter::convert(std::string _string)
{
    if (_string.empty())
        std::cout << "Empty string input\n";
    else if (_string.length() == 1)
        ConvertChar(_string);
    else
        stringParser(_string);
}