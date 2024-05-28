#include "parabola.h"
#include <cmath>
using namespace std;
Parabola::Parabola(double aVal, double hVal, double kVal) : value(aVal), h(hVal), k(kVal) {}

double Parabola::evaluate(double x) const {
    return value * pow(x - h, 2) + k;
}

void Parabola::displayResult(double x, double y) const {
    std::cout << "Значение f(x) = " << value << "(x - " << h << ")^2" << "+" << k << " в точке x = " << x << ": " << y << std::endl;
}

double Parabola::findMinimum(double a, double b) const {
    // Минимум зависит от знака у коэффицента a 
    if (value > 0) {

        if (h>=a && h<=b) cout << "Минимум параболы на заданном интервале в точке (" << h << ";" << k << ")" << endl;
        else cout << "Максимум параболы на заданном интервале в точке (" << b << ";" << value * pow(b - h, 2) + k << ")" << endl;

        return h; //Возвращаем х
    } else {
        cout << "Минимума параболы нет" << endl;
        return std::numeric_limits<double>::quiet_NaN(); // Если ветви параболы направлены вниз то минимума нет
    }
}

double Parabola::findMaximum(double a, double b) const {
    if (value < 0) {
        if (h>=a && h<=b) cout << "Максимум параболы на заданном интервале в точке (" << h << ";" << k << ")" << endl;
        else cout << "Максимум параболы на заданном интервале в точке (" << b << ";" << value * pow(b - h, 2) + k << ")" << endl;

        return h; //Возвращаем х
    } else {
        cout << "Максимума параболы нет" << endl;
        return std::numeric_limits<double>::quiet_NaN(); // Нет максимума если ветви параболы направлены вверх
    } 
}

// Интеграл 2 * (x^3/3 - hx^2 +h^2x) + kx
double Parabola::integrate(double a, double b) const {
    double integral = abs(((value*((pow(a, 3)/3) -  (h * pow(a, 2)) + (pow(h, 2)*a))) + (k * a)) - ((value*((pow(b, 3)/3) -  (h * pow(b, 2)) + (pow(h, 2)*b))) + (k * b)));
    cout << "Интеграл на отрезке [" << a << ";" << b << "]: " << integral << endl;
    return integral;
}

// Дифференциал 
double Parabola::differentiate(double x) const {
    double differential = 2 * value * x - 2 * value * h;
    cout << "Дифференциал в x = " << x << ": " << differential << endl;
    return differential;
}
