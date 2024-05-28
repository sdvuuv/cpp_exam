#ifndef PARABOLA_H
#define PARABOLA_H
#include "../function.h"
#include <iostream>

class Function;

class Parabola : public Function
{
private:
    double value, h, k;

public:
    Parabola(double aVal, double hVal, double kVal);

    double evaluate(double x) const override;
    void displayResult(double x, double y) const override;
    double findMinimum(double a, double b) const override;
    double findMaximum(double a, double b) const override;
    double integrate(double a, double b) const override;
    double differentiate(double x) const override;
};

#endif