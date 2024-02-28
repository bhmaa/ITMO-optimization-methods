#include "../include/Derivative.h"
#include <functional>

using namespace std;

std::function<double(double)> calculateDerivative(const std::function<double(double)> &function, double h) {
    return [function, h](double x) {
        return (function(x + h) - function(x)) / h;
    };
}
