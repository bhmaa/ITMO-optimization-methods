#include "../include/Newton.h"
#include "../include/Derivative.h"
#include <iostream>
#include <cmath>

using namespace std;

Newton::Newton(double a, double b, double e, std::function<double(double)> function)
        : a(a), b(b), e(e), function(std::move(function)),
          first_derivative(std::move(calculateDerivative(this->function))),
          second_derivative(std::move(calculateDerivative(this->first_derivative))) {};

void Newton::findMinimum() {
    cout << "-----" << endl;
    cout << "Вычисление по методу Ньютона" << endl;
    cout << "-----" << endl;

    int n = 1;
    double x = (a + b) / 2;
    cout << "Шаг 0:" << endl;
    cout << "Начнем с середины заданного отрезка, т.е x0 = " << x << endl;

    while (fabs(first_derivative(x)) > e) {
        cout << "Шаг " << n << ":" << endl;
        x = x - first_derivative(x) / second_derivative(x);
        cout << "Касательная к графику функции f'(x) в точке x" << n << " пересекает ось Oy в точке x" << n + 1 << " = "
             << x << endl;
        cout << "Выберем это новой точкой. В ней f'(x" << n + 1 << ") = " << first_derivative(x) << endl;
        n++;
    }

    cout << "|f'(x)| <= e. Минимум с заданной погрешностью e = " << e << " найден!" << endl;
    cout << "-----" << endl;
    cout << "Минимум достигается в точке xm = " << x << endl;
    cout << "Значение в минимуме ym = " << function(x) << endl;
}
