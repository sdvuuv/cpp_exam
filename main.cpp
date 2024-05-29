#include <iostream>
#include <cfloat>
#include <cmath>
#include "functions/exponenta.h"
#include "functions/hiperbola.h"
#include "functions/parabola.h"
#include "functions/polinom.h"

using namespace std;
void complex_function(Function &firstFunc, Function &secondfunc, double x){
    double res = secondfunc.differentiate(x);
    double res2 = firstFunc.differentiate(res);
    cout << "Дифференциал сложной функции " << res * res2 << endl;

}



int main(){
    setlocale(LC_ALL, "rus");
    // Задаем функцию y = 2^x
    Exponent exp(2.0);
    cout << "=============================================" << endl;
    // Функция в точке x = 3
    double x = 3.0;
    double y = exp.evaluate(x);

    exp.displayResult(x, y);

    // Задаем интервал
    double a = 1.0;
    double b = 5.0;
    exp.findMinimum(a, b);
    exp.findMaximum(a, b);
    exp.differentiate(x);
    exp.integrate(a, b);
    cout << "=============================================" << endl;

    Hyperbola hyp(2.0, 1.0, -1.0);
    y = hyp.evaluate(x);
    hyp.displayResult(x, y);
    hyp.findMinimum(a, b); 
    hyp.findMaximum(a, b); 
    x = 3.0; 
    hyp.differentiate(x);
    hyp.integrate(a, b);

    cout << "=============================================" << endl;

    
    Parabola par(2.0, 1.0, 3.0);
    x = 4.0;
    y = par.evaluate(x);
    par.displayResult(x, y);
    par.findMinimum(a, b);
    par.findMaximum(a, b);
    par.integrate(a, b);
    x = 3.0; 
    par.differentiate(x);
    cout << "=============================================" << endl;


    std::vector<double> coeffs = {1.0, 2.0, 3.0};
    Polynomial poly(coeffs);
    double x4 = 4.0;
    double y4 = poly.evaluate(x4);
    poly.displayResult(x4, y4);
    poly.findMaximum(a, b);
    poly.findMinimum(a, b);
    poly.integrate(a, b);
    x = 3.0; 
    poly.differentiate(x);
    
    cout << "=============================================" << endl;
    complex_function(par, hyp, x);
    
    //hyp.differentiate(par.differentiate(x));

  
   
    return 0;

    
}