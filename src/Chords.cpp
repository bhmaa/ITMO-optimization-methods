#include "../include/Chords.h"
#include "../include/Derivative.h"
#include <iostream>
#include <functional>
#include <cmath>

using namespace std;

Chords::Chords(double a, double b, double e, std::function<double(double)> function)
        : a(a), b(b), e(e), function(std::move(function)), derivative(std::move(calculateDerivative(this->function))) {}

void Chords::findMinimum() {
    cout << "-----" << endl;
    cout << "Вычисление по методу хорд" << endl;
    cout << "-----" << endl;

    int n = 1;
    double x = a - derivative(a) / (derivative(a) - derivative(b)) * (a - b);

    while (fabs(derivative(x)) > e) {
        cout << "Шаг " << n << ":" << endl;
        cout << "a = " << a << "; b = " << b << endl;
        x = a - derivative(a) / (derivative(a) - derivative(b)) * (a - b);
        cout << "Отрезок, соединяющий точки (a; f'(a)) и (b; f'(b)) пересекает ось 0y в точке с x = " << x
             << ". f'(" << x << ") = " << derivative(x) << endl;

        if (derivative(x) > 0) {
            cout << "f'(" << x << ") > 0 => Отсекаем отрезок справа от " << x << " до " << b << endl;
            b = x;
        } else {
            cout << "f'(" << x << ") <= 0 => Отсекаем отрезок слева от " << a << " до " << x << endl;
            a = x;
        }
        n++;
    }

    cout << "|f'(x)| <= e. Минмум с заданной погрешностью e = " << e << " найден" << endl;
    cout << "-----" << endl;
    cout << "Минимум в точке xm = " << x << endl;
    cout << "Значение в минимуме ym = " << function(x) << endl;
}


