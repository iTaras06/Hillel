#include <iostream>

int calculate(char operation, const int a, const int b)
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
            std::cout << "Error, the second number mustn't be ";
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

int main()
{
    int a = 0;
    int b = 0;
    char operation = 0;
    std::cout << "Enter the first number: ";
    std::cin >> a;
    std::cout << "Enter the second number: ";
    std::cin >> b;
    std::cout << "Enter the + , - , * or / symbol: ";
    std::cin >> operation;
    int result = calculate(operation, a, b);
    std::cout << result;
}
