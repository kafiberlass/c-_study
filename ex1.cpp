#include <iostream>
#include <cstdlib>
#include <ctime>

void ShiftLeftt3(double &A, double &B, double &C) {
    double temp = A;
    A = C;
    C = B;
    B = temp;
}

int main() {
    std::srand(static_cast<unsigned>(std::time(nullptr)));

    double num1 = rand() % 100;
    double num2 = rand() % 100;
    double num3 = rand() % 100;

    std::cout << "Initial numbers: " << num1 << ", " << num2 << ", " << num3 << std::endl;

    ShiftLeftt3(num1, num2, num3);

    std::cout << "Numbers after left cyclic shift: " << num1 << ", " << num2 << ", " << num3 << std::endl;

    return 0;
}
