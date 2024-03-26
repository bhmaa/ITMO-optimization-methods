#include <iostream>
#include <cmath>
#include "../include/Powell.h"

using namespace std;

void Powell::findMinimum(double x_1, double e_1, double e_2, const std::function<double(double)> &function) {
    cout << "-----" << endl;
    cout << "Вычисление по методу квадратичной аппроксимации" << endl;
    cout << "-----" << endl;

    double delta_x = 1;

    double x_2 = x_1 + delta_x, f_1 = function(x_1), f_2 = function(x_2);
    cout << "x_1 = " << x_1 << "; f(x_1) = " << f_1 << endl;
    cout << "x_2 = " << x_2 << "; f(x_2) = " << f_2 << endl;

    double x_3 = f_1 > f_2 ? x_1 + 2 * delta_x : x_1 - delta_x;
    double f_3 = function(x_3);
    cout << "x_3 = " << x_3 << "; f(x_3) = " << f_3 << endl;

    double f_min, x_min, x, f;
    do {
        if (f_1 > f_2) {
            if (f_3 > f_2) {
                f_min = f_2;
                x_min = x_2;
            } else {
                f_min = f_3;
                x_min = x_3;
            }
        } else {
            if (f_3 > f_1) {
                f_min = f_1;
                x_min = x_1;
            } else {
                f_min = f_3;
                x_min = x_3;
            }
        }
        cout << "f_min = " << f_min << "; x_min = " << x_min << endl;

        x = ((pow(x_2, 2) - pow(x_3, 2)) * f_1 + (pow(x_3, 2) - pow(x_1, 2)) * f_2 +
             (pow(x_1, 2) - pow(x_2, 2)) * f_3) / ((x_2 - x_3) * f_1 + (x_3 - x_1) * f_2
                                                   + (x_1 - x_2) * f_3) / 2;
        f = function(x);

        cout << "x_ = " << x << "; f_ = " << f << endl;

        if (((x_1 < x_3) && ((x <= x_1) || (x >= x_3))) || ((x_1 > x_3) && ((x >= x_1) || (x <= x_3)))) {
            x_1 = x;
            x_2 = x_1 + delta_x;
            f_1 = function(x_1);
            f_2 = function(x_2);
            x_3 = f_1 > f_2 ? x_1 + 2 * delta_x : x_1 - delta_x;
            f_3 = function(x_3);

            cout << "Точка выходит за пределы [x_1; x_3]. Выбраны новые точки:" << endl;
            cout << "x_1 = " << x_1 << "; f(x_1) = " << f_1 << endl;
            cout << "x_2 = " << x_2 << "; f(x_2) = " << f_2 << endl;
            cout << "x_3 = " << x_3 << "; f(x_3) = " << f_3 << endl;
        } else {
            if (x_1 < x_3) {
                if (x > x_2) {
                    x_1 = x_2;
                } else {
                    x_3 = x_2;
                }
            } else {
                if (x > x_1) {
                    x_3 = x_2;
                } else {
                    double d = x_1;
                    x_1 = x_3;
                    x_3 = d;
                }
            }
            f_1 = function(x_1);
            f_3 = function(x_3);
            x_2 = x;
            f_2 = function(x_2);

            cout << "Точка входит в пределы [x_1; x_3]. Далее рассматриваем:" << endl;
            cout << "x_1 = " << x_1 << "; f(x_1) = " << f_1 << endl;
            cout << "x_2 = " << x_2 << "; f(x_2) = " << f_2 << endl;
            cout << "x_3 = " << x_3 << "; f(x_3) = " << f_3 << endl;
        }

        cout << "|(f_min - f_) / f_| = " << abs((f_min - f) / f) << endl;
        cout << "|(x_min - x_) / x_| = " << abs((x_min - x) / x) << endl;
    } while ((abs((f_min - f) / f) > e_1) || (abs((x_min - x) / x) > e_2));

    cout << "Минимум с заданной точностью e_1 = " << e_1 << " и e_2 = " << e_2 << " найден!" << endl;
    cout << "-----" << endl;
    cout << "Минимум достигается в точке x_m = " << x << endl;
    cout << "Значение в минимуме y_m = " << f << endl;
}
