#pragma once
#include <iostream>

class Calculator
{
private:
    int result = 0;

public:
    void setResult(int startValue);

    int getResult() const;

    Calculator& calculate(const int& value, const char& operation);

    Calculator& operator+(int value);

    Calculator& operator-(int value);

    Calculator& operator/(int value);

    Calculator& operator*(int value);

    void print();

};

class calculatorException : public std::exception
{
public:
    virtual const char* what() const noexcept
    {
        return "My custom exception";
    }
};

class invalidArgument : public calculatorException
{

};

class invalidOp : public calculatorException
{

};
