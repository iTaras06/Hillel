// Calculating the sum of the digits of a number entered by the user
#include <iostream>

int main()
{
    unsigned int value = 0;
    std::cout << "Enter positive integer: ";
    std::cin >> value;
    unsigned int sum = 0;
    while (value)
    {
        sum += value % 10;
        value /= 10;
    }
    std::cout << "Sum of the digits of the number: " << sum << std::endl;
}
