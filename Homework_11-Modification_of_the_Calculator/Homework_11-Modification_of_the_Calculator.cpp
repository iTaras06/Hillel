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

int calculate(const char* operation1, const int* a1, const int* b1)
{
    if (operation1 && a1 && b1)
    {
        return calculate(*operation1, *a1, *b1);
    }
}

int& process_a_By(int& first, const int by, const char op)
{
    first = calculate(op, first, by);
    return first;
}

int main()
{
    int* a1 = new int;
    int* b1 = new int;
    char* operation1 = new char;

    int a2 = 0;
    int b2 = 0;
    char operation2 = 0;

    std::cout << "Enter the first number: ";
    std::cin >> *a1;
    std::cout << "Enter the second number: ";
    std::cin >> *b1;
    std::cout << "Enter the + , - , * or / symbol: ";
    std::cin >> *operation1;

    int result = calculate(operation1, a1, b1);
    std::cout << result;

    delete a1;
    delete b1;
    delete operation1;
    a1 = nullptr;
    b1 = nullptr;
    operation1 = nullptr;

    std::cout << "\n\nEnter the first number: ";
    std::cin >> a2;
    std::cout << "Enter the second number: ";
    std::cin >> b2;
    std::cout << "Enter the + , - , * or / symbol: ";
    std::cin >> operation2;

    int res = process_a_By(a2, b2, operation2);
    std::cout << "\nResult of modification: " << res << std::endl;
}
