#include <functional>

using namespace std;

class Chords {
private:
    double a;
    double b;
    const double e;
    const std::function<double(double)> function;
    const std::function<double(double)> derivative;

public:
    Chords(double a, double b, double e, std::function<double(double)> function);

    void findMinimum();
};

