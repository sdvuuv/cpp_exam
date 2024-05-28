#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H
#include "../function.h"
#include <iostream>
#include <vector> // for storing coefficients

class Function; 

class Polynomial : public Function {
private:
    std::vector<double> coefficients;

public:
    Polynomial(const std::vector<double>& coeffs);

    double evaluate(double x) const override;
    void displayResult(double x, double y) const override;
    double findMinimum(double a, double b) const override;
    double findMaximum(double a, double b) const override;
    double integrate(double a, double b) const override;
    double differentiate(double x) const override;
};

#endif