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

    HalfDivision halfDivision(1.5, 2.0, 0.02, function);
    halfDivision.findMinimum();

    GoldenRatio goldenRatio(1.5, 2.0, 0.02, function);
    goldenRatio.findMinimum();

    Chords chords(1.5, 2.0, 0.02, function);
    chords.findMinimum();

    Newton newton(1.5, 2.0, 0.02, function);
    newton.findMinimum();

    return 0;
}
