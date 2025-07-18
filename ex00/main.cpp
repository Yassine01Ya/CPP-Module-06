#include "ScalarConverter.hpp"

int main(int c, char **v)
{
    if (c == 2)
    {
        ScalarConverter::convert(v[1]);
        return 0;
    }
    else
        std::cout << "bad argumments [Usage: ]\n"
                  << v[0] << " [string to convert]\n";
    return 1;
}