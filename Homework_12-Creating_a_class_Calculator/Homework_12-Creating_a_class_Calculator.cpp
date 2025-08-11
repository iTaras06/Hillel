#include <iostream>

class Calculator
{
public:
    int calculate(int a, int b, char operation)
    {
        int result = 0;
        if (operation == '+')
        {
            result = a + b;
        }
        if (operation == '/')
        {
            if (b == 0)
            {
                std::cout << "Error, the second number mustn't be 0";
                return 0;
            }
            else
                result = a / b;
        }
        if (operation == '-')
        {
            result = a - b;
        }
        if (operation == '*')
        {
            result = a * b;
        }
        return result;
    }
    int calculate(int* a, int* b, char* operation)
    {
        if (a && b && operation)
        {
            return calculate(*a, *b, *operation);
        }
    }
};

int main()
{
    int a = 10;
    int b = 20;
    char operation = '-';
    Calculator calculator;
    int result = calculator.calculate(a, b, operation);
    std::cout << result;
}
