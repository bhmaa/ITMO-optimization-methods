#include <functional>

using namespace std;

class Chords {
public:
    static void findMinimum(double a, double b, double e, const std::function<double(double)>& function);
};

