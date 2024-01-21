#include <iostream>
#include <cmath>

double exactFunction(double x) {
    return x * x;
}

double approximateFunction(double x) {
    return 2 * x;
}

int main() {
    const int arraySize = 100;
    double xValues[arraySize];
    double differences[arraySize];

    for (int i = 0; i < arraySize; ++i) {
        xValues[i] = i;
    }

    double maxDifference = 0;
    double maxX = 0;

    for (int i = 0; i < arraySize; ++i) {
        double exactValue = exactFunction(xValues[i]);
        double approxValue = approximateFunction(xValues[i]);
        differences[i] = std::abs(exactValue - approxValue);

        if (differences[i] > maxDifference) {
            maxDifference = differences[i];
            maxX = xValues[i];
        }
    }

    std::cout << "Max difference occurs at x = " << maxX << " with a difference of " << maxDifference << std::endl;

    return 0;
}
