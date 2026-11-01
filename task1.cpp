#include <iostream>
#include <cmath>

double integrate(double (*f)(double), double a, double b, int n) {
    double h = (b - a) / n;
    double sum = 0.0;
    
    for (int i = 1; i <= n; ++i) {
        double x_i = a + i * h;
        sum += f(x_i);
    }
    
    return h * sum;
}

double f1(double x) {
    return x * x - 2 * x + 2;
}

double f2(double x) {
    return std::exp(-x);
}

double f3(double x) {
    return std::sqrt(x + 4);
}

int main() {
    const int n = 1000;

    double a1 = 0.0, b1 = 3.0;
    double a2 = 0.0, b2 = 2.0;
    double a3 = 0.0, b3 = 5.0;

    double I1 = integrate(f1, a1, b1, n);
    double I2 = integrate(f2, a2, b2, n);
    double I3 = integrate(f3, a3, b3, n);

    double S = I1 + I2 + I3;

    std::cout << "I1 = " << I1 << std::endl;
    std::cout << "I2 = " << I2 << std::endl;
    std::cout << "I3 = " << I3 << std::endl;
    std::cout << "S  = " << S << std::endl;

    return 0;
}