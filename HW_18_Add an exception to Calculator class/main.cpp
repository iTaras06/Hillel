#include <iostream>
#include "Header.h"

int calculateExcep(int f, int s, char op)
{
    if (op != '+' || op != '/')
    {
        throw invalidOp();
    }

    if (op == '+')
    {
        return f + s;
    }

    if (op == '/')
    {
        if (s == 0)
        {
            throw invalidArgument();
        }
        return f / s;
    }
    return 0;
}


int main()
{
    Calculator my_calc;

    my_calc.calculate(2, '+').calculate(4, '-').calculate(5, '*').calculate(10, '/').getResult();
    my_calc.print();

    Calculator my_calc2;

    my_calc2 + 2;
    my_calc2.print();

    my_calc2 - 4;
    my_calc2.print();

    my_calc2 * 5;
    my_calc2.print();

    my_calc2 / 10;
    my_calc2.print();


    int res = 0;

    try
    {
        res = calculateExcep(10, 0, '/');
        res = calculateExcep(10, 10, '-');
        res = calculateExcep(10, 10, '+');
    }
    catch (const invalidArgument& ops)
    {
        std::cout << "Caught calculatorException: invalid argument" << std::endl;
    }

    catch (const calculatorException& ops)
    {
        std::cout << "Caught calculatorException" << std::endl;
    }
    catch (...) {}

    std::cout << std::endl;

    Calculator my_calc3;
    my_calc3.setResult(10);
    my_calc3.print();

    try 
    {
        my_calc3.calculate(0, '/');
    }
    catch (const calculatorException& ex) 
    {
        std::cout << "Caught calculatorException" << std::endl;
    }

    try
    {
	    my_calc3.calculate(5, '%');
    }
    catch (const invalidOp& ex)
    {
        std::cout << "Caught invalidOp exception" << std::endl;
    }
    return 0;
}
