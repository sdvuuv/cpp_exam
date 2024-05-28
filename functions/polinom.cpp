#include "polinom.h"
#include <cmath>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
Polynomial::Polynomial(const std::vector<double> &coeffs) : coefficients(coeffs) {}

double Polynomial::evaluate(double x) const
{
    double result = 0.0;
    int c = 0;
    for (int i = coefficients.size() - 1; i >= 0; --i)
    {
        result += (coefficients[i] * pow(x, c));
        c++;
    }
    return result;
}

// тут издевательство над строками чтобы был красивый вывод
void Polynomial::displayResult(double x, double y) const
{
    double result = 0.0;
    int c = 0;
    cout << "Значение f(x) = ";
    string s = "";
    for (int i = coefficients.size() - 1; i >= 0; --i)
    {
        if (c != 0 and c != 1)
        {
            if (coefficients[i] != 1)
            {
                s.append(to_string(int(coefficients[i])));
                s.append("* x^");
                s.append(to_string(c));
                s.append(" + ");
            }
            else
            {
                s.append(" x^");
                s.append(to_string(c));
                s.append(" +");
            }
        }
        else if (c == 1)
        {
            s.append(to_string(int(coefficients[i])));
            s.append("x +");
        }
        else
        {
            s.append(to_string(int(coefficients[i])));
            s.append(" +");
        }
        c++;
    }
    s.pop_back();
    cout << s.substr() << " в точке x = " << x << ": " << y << endl;
}

double Polynomial::findMinimum(double a, double b) const
{
    double min_value = evaluate(a);
    double x_min = a;
    for (double x = a + 0.1; x <= b; x += 0.1)
    {
        double current_value = evaluate(x);
        if (current_value < min_value)
        {
            min_value = current_value;
            x_min = x;
        }
    }

    cout << "Минимум многочлена на заданном интервале в точке (" << x_min << ";" << evaluate(x_min) << ")" << endl;
    return x_min;
}

double Polynomial::findMaximum(double a, double b) const
{
    double max_value = evaluate(a);
    double x_max = a;
    for (double x = a + 0.1; x <= b; x += 0.1)
    {
        double current_value = evaluate(x);
        if (current_value > max_value)
        {
            max_value = current_value;
            x_max = x;
        }
    }

    cout << "Максимум многочлена на заданном интервале в точке (" << x_max << ";" << evaluate(x_max) << ")" << endl;
    return x_max;
}

// Интегрируем методом трапеций, ибо я не знаю как интегрировать нормально формулой это
double Polynomial::integrate(double a, double b) const
{
    int n = 1000; // Количество трапеций
    double h = (b - a) / n;
    double sum = (evaluate(a) + evaluate(b)) / 2.0;
    for (int i = 1; i < n; ++i)
    {
        double x = a + i * h;
        sum += evaluate(x);
    }
    double integral = sum * h;
    cout << "Интеграл на отрезке [" << a << ";" << b << "]: " << integral << endl;
    return integral;
}

// Дифиренциал
double Polynomial::differentiate(double x) const
{
    double differential = 0.0;

    int c = 0;
    for (int i = coefficients.size() - 1; i >= 0; --i)
    {
        if (c != 0)
            differential += coefficients[i] * c * pow(x, c - 1);
        c++;
    }
    cout << "Дифференциал в x = " << x << ": " << differential << endl;

    return differential;
}
