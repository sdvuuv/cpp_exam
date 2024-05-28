#include "exponenta.h"
#include <cmath>
using namespace std;

Exponent::Exponent(double aVal) : value(aVal) {}

double Exponent::evaluate(double x) const
{
    return pow(value, x); // Задаем функцию
}

void Exponent::displayResult(double x, double y) const
{
    // Вывод функции
    cout << "Значение f(x) = " << value << "^x в точке x = " << x << ": " << y << endl;
}

double Exponent::findMinimum(double a, double b) const
{
    cout << "Экспоненциальная функция не имеет минимума" << endl;
    return numeric_limits<double>::quiet_NaN(); // Возвращаем NaN т.к. минимуа нет
}

double Exponent::findMaximum(double a, double b) const
{
    cout << "Экспоненциальная функция не имеет максимума" << endl;
    return std::numeric_limits<double>::quiet_NaN(); // Возвращаем NaN
}

// Интегрируем, формула: a^x dx = (a^x) / ln(a) + C
double Exponent::integrate(double a, double b) const
{
    double integral = (pow(value, b) / log(value)) - (pow(value, a) / log(value));
    cout << "Интеграл на отрезке [" << a << ";" << b << "]: " << integral << endl;
    return integral;
}
// Дифифиренциал в точке x: ln(a) * a^x
double Exponent::differentiate(double x) const
{
    double differential = log(value) * pow(value, x);
    cout << "Дифференциал в x = " << x << ": " << differential << endl;
    return differential;
}