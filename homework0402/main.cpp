#include <iostream>

double power(double x, int n) {
    if (n == 0) {
        return 1;
    }
    else if (n > 0) {
        return x * power(x, n - 1);
    }
    else {
        return 1 / power(x, -n);
    }
}

int main() {
    double base = 3.1;
    int exponent = 4;
    double result = power(base, exponent);

    std::cout << base << "以" << exponent << "为指数的结果是: " << result << std::endl;

    return 0;
}