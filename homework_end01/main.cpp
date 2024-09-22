#include <iostream>    // 包含标准输入输出流库
#include <stack>       // 包含堆栈库
#include <cmath>       // 包含数学函数库
#include <string>      // 包含字符串处理库
#include "ComplexNumber.h"
#include "Calculator.h"
#include "BigInteger.h"

using namespace std;  // 使用标准命名空间

// 复数计算
void complexCalculate() {
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
}

// 无穷精度计算
void infinitePrecisionCalculate() {
    string aa, bb;
    cout << "请输入第一个数:";
    cin >> aa;
    cout << "请输入第二个数:";
    cin >> bb;
    BigInteger a(aa);
    BigInteger b(bb);

	cout << "a + b = " << a + b << endl;
	cout << "a - b = " << a - b << endl;
	cout << "a * b = " << a * b << endl;
	pair<BigInteger, BigInteger> result = a.division(b);
	cout << "a / b = " << result.first << " 余数:" << result.second << endl;

	try {
		cout << "a % b = " << a % b << endl;
	}
	catch (const invalid_argument& e) {
		cout << "错误: " << e.what() << endl;
	}
}

// 主函数
int main() {
    Calculator calc;
    int choose;
    string expression;
    double result = 0;

    while (true) {
        cout << "请选择你的计算模式(1.表达式计算 2.复数计算 3.无穷精度计算 4.退出):";
        cin >> choose;
        cin.ignore();

        switch (choose)
        {
        case 1:
            cout << "请输入表达式:";
            getline(cin, expression);  // 输入表达式
            result = calc.evaluateExpression(expression);  // 调用表达式求值函数
            cout << "计算结果为: " << result << endl;  // 输出计算结果
            break;
        case 2:
            complexCalculate();
            break;
        case 3:
            infinitePrecisionCalculate();
            break;
        case 4:
            cout << "退出程序";
            return 0;
            break;
        default:
            cout << "选择错误";
            break;
        }

    }

    return 0;
}
