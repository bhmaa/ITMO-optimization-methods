#include <functional>

std::function<double(double)> calculateDerivative(const std::function<double(double)> &function, double h = 1e-5);
