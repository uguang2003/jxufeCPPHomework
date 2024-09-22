#include <iostream>
#include "ComplexNumber.h"

using namespace std;

int main() {
    double real1, imag1, real2, imag2;
    cout << "输入第一个复数的实部和虚部: ";
    cin >> real1 >> imag1;
    cout << "输入第二个复数的实部和虚部: ";
    cin >> real2 >> imag2;

    ComplexNumber complexNum(real1, imag1, real2, imag2);

    Complex sum = complexNum.add();
    Complex difference = complexNum.subtract();
    Complex product = complexNum.multiply();
    Complex quotient = complexNum.divide();

    cout << "加: " << sum.real << " + " << sum.imag << "i" << endl;
    cout << "减: " << difference.real << " + " << difference.imag << "i" << endl;
    cout << "乘: " << product.real << " + " << product.imag << "i" << endl;
    cout << "除: " << quotient.real << " + " << quotient.imag << "i" << endl;

    return 0;
}