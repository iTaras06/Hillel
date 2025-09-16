#include "Header.h"

void Calculator::setResult(int startValue)
{
    result = startValue;
}

int Calculator::getResult() const
{
    return result;
}


Calculator& Calculator::calculate(const int& value, const char& operation)
{
    switch (operation)
    {
    case '+':
        result += value;
        break;
    case '-':
        result -= value;
        break;
    case '*':
        result *= value;
        break;
    case '/':
        result /= value;
        break;
    default:
        break;
    }

    return *this;
}

Calculator& Calculator::operator+(int value)
{
    result += value;
    return *this;
}

Calculator& Calculator::operator-(int value)
{
    result -= value;
    return *this;
}

Calculator& Calculator::operator/(int value)
{
    result /= value;
    return *this;
}

Calculator& Calculator::operator*(int value)
{
    result *= value;
    return *this;
}

void Calculator::print()
{
    std::cout << result << "\n";
}

