#include <iostream>

int factorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    }
    else {
        return n * factorial(n - 1);
    }
}

int main() {
    int result = factorial(8);
    std::cout << "8! = " << result << std::endl;

    return 0;
}
