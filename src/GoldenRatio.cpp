#include "../include/GoldenRatio.h"

#include <iostream>
#include <functional>

using namespace std;

GoldenRatio::GoldenRatio(double a, double b, double e, std::function<double(double)> function)
        : a(a), b(b), e(e), function(std::move(function)) {}

void GoldenRatio::findMinimum() {
    cout << "-----" << endl;
    cout << "Вычисление по методу золотого сечения" << endl;
    cout << "-----" << endl;

    int n = 1;
    double x1 = a + 0.382 * (b - a);
    double x2 = a + 0.618 * (b - a);

    double y1 = function(x1);
    double y2 = function(x2);

    while (b - a > e) {
        cout << "Шаг " << n << ":" << endl;
        cout << "a = " << a << "; b = " << b << endl;
        cout << "x1 = " << x1 << "; x2 = " << x2 << endl;
        cout << "y1 = " << y1 << "; y2 = " << y2 << endl;

        if (y1 > y2) {
            cout << "y1 > y2 => a = " << x1 << "; x1 = x2. Пересчет y1 не требуется" << endl;
            a = x1;
            x1 = x2;
            y1 = y2;
            x2 = a + 0.618 * (b - a);
            y2 = function(x2);
        } else {
            cout << "y1 <= y2 => b = " << x2 << "; x2 = x1. Пересчет y2 не требуется" << endl;
            b = x2;
            x2 = x1;
            y2 = y1;
            x1 = a + 0.382 * (b - a);
            y1 = function(x1);
        }

        cout << "b - a = " << b - a << endl;
        n++;
    }

    cout << "b - a < e. Минмум с заданной погрешностью e = " << e << " лежит на середине данного отрезка" << endl;
    cout << "-----" << endl;

    double xm = (a + b) / 2;
    double ym = function(xm);

    cout << "Минимум в точке xm = " << xm << endl;
    cout << "Значение в минимуме ym=" << ym << endl;
}

