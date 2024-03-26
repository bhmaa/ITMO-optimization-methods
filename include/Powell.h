#include <functional>

class Powell {
public:
    static void findMinimum(double a, double e_1, double e_2, const std::function<double(double)>& function);
};

