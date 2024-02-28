#include "include/HalfDivision.h"
#include "include/GoldenRatio.h"
#include "include/Chords.h"
#include "include/Newton.h"
#include "include/Derivative.h"

#include <cmath>

using namespace std;

int main() {
    std::function<double(double)> function = [](double x) {
        return pow(x, 3) / 3 - 5 * x + x * log(x);
    };

    HalfDivision::findMinimum(1.5, 2.0, 0.02, function);

    GoldenRatio::findMinimum(1.5, 2.0, 0.02, function);

    Chords::findMinimum(1.5, 2.0, 0.02, function);

    Newton::findMinimum(1.5, 2.0, 0.02, function);

    return 0;
}
