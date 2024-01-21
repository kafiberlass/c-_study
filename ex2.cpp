#include <iostream>
#include <cmath>
#include <iomanip>

double factorial(int n) {
    if (n == 0 || n == 1) {
        return 1.0;
    }
    return n * factorial(n - 1);
}

double binomialCoefficient(int n, int k) {
    if (k == 0 || k == n) {
        return 1.0;
    }
    return binomialCoefficient(n - 1, k - 1) * (double)n / k;
}

double powerSeriesExpansion(int m, double x, int n) {
    double result = 1.0;
    for (int i = 1; i <= n; ++i) {
        result += pow(-1, i) * (binomialCoefficient(m + i - 1, i) / factorial(i)) * pow(x, i);
    }
    return result;
}

int main() {
    const int m = 4;
    const double step = 0.1;

    std::cout << " x      | Exact   | Approximation\n";
    std::cout << "-----------------------------\n";

    for (double x = -0.9; x <= 0.9; x += step) {
        double exactResult = pow(1 + x, -m);
        double approximateResult = powerSeriesExpansion(m, x, 7);

        std::cout << std::fixed << std::setprecision(2) << x << " | " << exactResult << " | " << approximateResult << "\n";
    }

    return 0;
}
