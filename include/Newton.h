#include <functional>

class Newton {
private:
    double a;
    double b;
    const double e;
    const std::function<double(double)> function;
    const std::function<double(double)> first_derivative;
    const std::function<double(double)> second_derivative;

public:
    Newton(double a, double b, double e, std::function<double(double)> function);

    void findMinimum();
};

