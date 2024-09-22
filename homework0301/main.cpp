#include <iostream>
#include <iomanip>
using namespace std;

double calculateFunction(double x, double p) {
    if (x >= 0 && x <= p) {
        return x / p;
    }
    else if (x > p && x <= 0.5) {
        return (x - p) / (0.5 - p);
    }
    else if (x > 0.5 && x <= 1) {
        return calculateFunction(1 - x, p);
    }
    else {
        return 0.0;
    }
}

int main() {
    double p;
    cout << "请输入p的值：";
    cin >> p;

    cout << "输出长度为100的状态序列：" << endl;
    cout << fixed << setprecision(6);
    for (int i = 0; i < 100; i++) {
        double x = i / 100.0;
        double result = calculateFunction(x, p);
        cout << result << endl;
    }

    return 0;
}
