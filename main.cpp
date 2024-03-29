#include "include/HalfDivision.h"
#include "include/GoldenRatio.h"
#include "include/Chords.h"
#include "include/Newton.h"
#include "include/Derivative.h"
#include "include/Powell.h"

#include <cmath>
#include <iostream>

using namespace std;

int main() {
    std::function<double(double)> function = [](double x) {
        return pow(x, 3) / 3 - 5 * x + x * log(x);
    };
    cout << "1 - половинное деление; 2 - золотое сечение; 3 - хорды; 4 - Ньютон; 5 - квадратичная аппроксимация"
         << endl;
    int method;
    cin >> method;
    switch (method) {
        case 1: {
            HalfDivision::findMinimum(1.5, 2.0, 0.02, function);
            break;
        }
        case 2: {
            GoldenRatio::findMinimum(1.5, 2.0, 0.02, function);
            break;
        }
        case 3: {
            Chords::findMinimum(1.5, 2.0, 0.02, function);
            break;
        }
        case 4: {
            Newton::findMinimum(1.5, 2.0, 0.02, function);
            break;
        }
        case 5: {
            Powell::findMinimum(1.5, 0.02, 0.0001, function);
            break;
        }
        default: {
            cout << "No such method";
        }
    }
    return 0;
}
