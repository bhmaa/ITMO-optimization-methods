#include <functional>

using namespace std;

class HalfDivision {
private:
    double a;
    double b;
    const double e;
    const std::function<double(double)> function;

public:
    HalfDivision(double a, double b, double e, std::function<double(double)> function);

    void findMinimum();
};

