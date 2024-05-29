#include "hiperbola.h"
#include <cmath>
#include <limits>
using namespace std;

Hyperbola::Hyperbola(double aVal, double hVal, double kVal) : value(aVal), h(hVal), k(kVal) {}

double Hyperbola::evaluate(double x) const
{
    return value / (x - h) + k;
}

void Hyperbola::displayResult(double x, double y) const
{
    cout << "Значение f(x) = " << value << "/(x -" << h << ") + (" << k << ") в точке x = " << x << ": " << y << endl;
}

double Hyperbola::findMinimum(double a, double b) const
{
    // Нет минимума
    cout << "Гипербола не имеет минимума" << endl;
    return std::numeric_limits<double>::quiet_NaN(); // Возвращаем NaN
}

double Hyperbola::findMaximum(double a, double b) const
{
    // Нет максимума
    cout << "Гипербола не имеет максимума" << endl;
    return std::numeric_limits<double>::quiet_NaN(); // Возвращаем NaN
}

// Интеграл a * ln |x - h| + kx + C
double Hyperbola::integrate(double a, double b) const
{
    double integral = (value * log(abs(b - h)) + (k * b)) - (value * log(abs(a - h)) + (k * a));
    cout << "Интеграл на отрезке [" << a << ";" << b << "]: " << integral << endl;
    return integral;
}

// Производная -a / ((x - h)^2)
// value / (x - h) + k
// 
double Hyperbola::differentiate(double x) const
{
    double differential = - value / pow(x - h + k, 2.0);
    cout << "Дифференциал в x = " << x << ": " << differential << endl;
    return differential;
}