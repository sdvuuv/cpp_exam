#ifndef EXPONENT_H
#define EXPONENT_H
#include "../function.h"
#include <iostream>
class Function;
class Exponent : public Function
{
private:
    double value;

public:
    Exponent(double aVal);

    double evaluate(double x) const override;
    void displayResult(double x, double y) const override;
    double findMinimum(double a, double b) const override;
    double findMaximum(double a, double b) const override;
    double integrate(double a, double b) const override; // Интегрирование
    double differentiate(double x) const override;
};

#endif
