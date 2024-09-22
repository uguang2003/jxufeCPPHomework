#include <iostream>    // 包含标准输入输出流库
#include <stack>       // 包含堆栈库
#include <cmath>       // 包含数学函数库
#include <string>      // 包含字符串处理库

using namespace std;  // 使用标准命名空间

// 定义运算符优先级函数
int priority(char op) {
    if (op == '^') return 3;          // 指数运算符优先级为3
    if (op == '*' || op == '/') return 2;  // 乘除运算符优先级为2
    if (op == '+' || op == '-') return 1;  // 加减运算符优先级为1
    return 0;                          // 默认返回优先级为0
}

// 定义应用运算函数
double applyOp(double a, double b, char op) {
    switch (op) {
    case '+': return a + b;   // 加法运算
    case '-': return a - b;   // 减法运算
    case '*': return a * b;   // 乘法运算
    case '/': return a / b;   // 除法运算
    case '^': return pow(a, b);  // 指数运算
    default: return 0;        // 默认情况返回0
    }
}

// 定义表达式求值函数
double evaluateExpression(string expression) {
    stack<double> values;   // 存储操作数的堆栈
    stack<char> ops;        // 存储运算符的堆栈

    for (int i = 0; i < expression.length(); i++) {
        if (expression[i] == ' ')
            continue;

        if (expression[i] == '(') {
            ops.push(expression[i]);  // 遇到左括号入栈
        }
        else if (isdigit(expression[i]) || expression[i] == '.') {
            // 处理数字（包括小数）部分
            double val = 0;
            double decimal = 10.0;
            while (i < expression.length() && (isdigit(expression[i]) || expression[i] == '.')) {
                if (expression[i] == '.') {
                    // 处理小数部分
                    i++;
                    while (i < expression.length() && isdigit(expression[i])) {
                        val = val + (expression[i] - '0') / decimal;
                        decimal *= 10.0;
                        i++;
                    }
                }
                else {
                    // 处理整数部分
                    val = val * 10 + expression[i] - '0';
                    i++;
                }
            }
            values.push(val);  // 将数值入栈
            i--;
        }
        else if (expression[i] == ')') {
            // 处理右括号
            while (!ops.empty() && ops.top() != '(') {
                double val2 = values.top();
                values.pop();

                double val1 = values.top();
                values.pop();

                char op = ops.top();
                ops.pop();

                values.push(applyOp(val1, val2, op));  // 计算并入栈
            }
            if (!ops.empty())
                ops.pop();  // 弹出左括号
        }
        else {
            // 处理运算符
            while (!ops.empty() && priority(ops.top()) >= priority(expression[i])) {
                double val2 = values.top();
                values.pop();

                double val1 = values.top();
                values.pop();

                char op = ops.top();
                ops.pop();

                values.push(applyOp(val1, val2, op));  // 计算并入栈
            }
            ops.push(expression[i]);  // 运算符入栈
        }
    }

    // 处理剩余运算符
    while (!ops.empty()) {
        double val2 = values.top();
        values.pop();

        double val1 = values.top();
        values.pop();

        char op = ops.top();
        ops.pop();

        values.push(applyOp(val1, val2, op));  // 计算并入栈
    }

    return values.top();  // 返回最终结果
}

// 主函数
int main() {
    string expression;
    cout << "请输入表达式：";
    getline(cin, expression);

    double result = evaluateExpression(expression);  // 调用表达式求值函数
    cout << "计算结果为: " << result << endl;  // 输出计算结果

    return 0;
}
