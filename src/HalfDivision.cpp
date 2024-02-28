#include "../include/HalfDivision.h"
#include <iostream>
#include <functional>

using namespace std;

void HalfDivision::findMinimum(double a, double b, double e, const std::function<double(double)> &function) {
    cout << "-----" << endl;
    cout << "Вычисление по методу половинного деления" << endl;
    cout << "-----" << endl;

    int n = 1;
    while (b - a > e * 2) {
        cout << "Шаг " << n << ":" << endl;
        cout << "Рассматриваем отрезок [" << a << "; " << b << "]" << endl;

        double x1 = (a + b - e) / 2;
        double x2 = (a + b + e) / 2;

        cout << "x1 = " << x1 << "; x2 = " << x2 << endl;

        double y1 = function(x1);
        double y2 = function(x2);

        cout << "y1 = " << y1 << "; y2 = " << y2 << endl;

        if (y1 > y2) {
            cout << "y1 > y2 => Отсекаем начало отрезка от " << a << " до " << x1 << endl;
            a = x1;
        } else {
            cout << "y1 <= y2 => Отсекаем конец отрезка от " << x2 << " до " << b << endl;
            b = x2;
        }

        cout << "b - a = " << b - a << endl;
        n++;
    }

    cout << "b - a < 2e. Минимум с заданной погрешностью e = " << e << " лежит на середине этого отрезка" << endl;
    cout << "-----" << endl;

    double xm = (a + b) / 2;
    double ym = function(xm);

    cout << "Минимум в точке xm = " << xm << endl;
    cout << "Значение в минимуме ym = " << ym << endl;
}

