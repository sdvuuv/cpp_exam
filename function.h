#include <iostream>
#pragma once
/* Абстрактный класс функции от которого будет наследоваться*/
using namespace std;

class Function {
public:
    virtual double evaluate(double x) const = 0; // Виртуальная функция для вычисления f(x)
    virtual void displayResult(double x, double y) const = 0; // Виртуальная функция для вывода функции

    virtual double findMinimum(double a, double b) const = 0; // Поиск минимума функции на заданном интервале
    virtual double findMaximum(double a, double b) const = 0; // Поиск максимума функции на заданном интервале

    virtual double integrate(double a, double b) const = 0; // Определенный интеграл на интервале 
    virtual double differentiate(double x) const = 0;      // Диффиренцирование
};

