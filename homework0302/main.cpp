#include <iostream>
using namespace std;

long fibonacci(int n) {
    if (n == 0) {
        return 0;
    }
    else if (n == 1) {
        return 1;
    }
    else {
        long a = 0;
        long b = 1;
        long fib = 0;

        for (int i = 2; i <= n; i++) {
            fib = a + b;
            a = b;
            b = fib;
        }

        return fib;
    }
}

int main() {
    int n_values[] = { 10, 20, 30 };

    for (int i = 0; i < 3; i++) {
        int n = n_values[i];
        long result = fibonacci(n);
        cout << "Fibonacci(" << n << ") = " << result << endl;
    }

    return 0;
}
