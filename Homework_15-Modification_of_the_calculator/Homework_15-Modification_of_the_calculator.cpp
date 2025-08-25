#include <iostream>

class Calculator
{
public:
    void setResult(int startValue)
    {
        result = startValue;
    }
    int getResult() const
    {
        return result;
    }

    Calculator& calculate(const int& value, const char& operation)
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

    Calculator& operator+(int value)
    {
        result += value;
        return *this;
    }
    Calculator& operator-(int value)
    {
        result -= value;
        return *this;
    }
    Calculator& operator/(int value)
    {
        result /= value;
        return *this;
    }
    Calculator& operator*(int value)
    {
        result *= value;
        return *this;
    }

    void print()
    {
        std::cout << result << "\n\n";
    }

private:
    int result = 0;
};

int main()
{
    Calculator my_calc;
    my_calc.calculate(2, '+').calculate(4, '-').calculate(5, '*').calculate(10, '/').getResult();
    my_calc.print();

    my_calc + 3;
    my_calc.print();

    my_calc - 4;
    my_calc.print();

    my_calc * 5;
    my_calc.print();

    my_calc / 10;
    my_calc.print();
}
