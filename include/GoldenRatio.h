#include <functional>

using namespace std;

class GoldenRatio {
private:
    double a;
    double b;
    const double e;
    const std::function<double(double)> function;

public:
    GoldenRatio(double a, double b, double e, std::function<double(double)> function);

    void findMinimum();
};

