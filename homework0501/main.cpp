#include <iostream>
#include "ComplexNumber.h"

using namespace std;

int main() {
    double real1, imag1, real2, imag2;
    cout << "�����һ��������ʵ�����鲿: ";
    cin >> real1 >> imag1;
    cout << "����ڶ���������ʵ�����鲿: ";
    cin >> real2 >> imag2;

    ComplexNumber complexNum(real1, imag1, real2, imag2);

    Complex sum = complexNum.add();
    Complex difference = complexNum.subtract();
    Complex product = complexNum.multiply();
    Complex quotient = complexNum.divide();

    cout << "��: " << sum.real << " + " << sum.imag << "i" << endl;
    cout << "��: " << difference.real << " + " << difference.imag << "i" << endl;
    cout << "��: " << product.real << " + " << product.imag << "i" << endl;
    cout << "��: " << quotient.real << " + " << quotient.imag << "i" << endl;

    return 0;
}