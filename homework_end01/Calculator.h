#pragma once
#include <stack>       // ������ջ��
#include <cmath>       // ������ѧ������
#include <string>      // �����ַ��������

using namespace std;  // ʹ�ñ�׼�����ռ�

class Calculator {
private:
    // ������������ȼ�����
    int priority(char op) {
        if (op == '^') return 3;          // ָ����������ȼ�Ϊ3
        if (op == '*' || op == '/') return 2;  // �˳���������ȼ�Ϊ2
        if (op == '+' || op == '-') return 1;  // �Ӽ���������ȼ�Ϊ1
        return 0;                          // Ĭ�Ϸ������ȼ�Ϊ0
    }

    // ����Ӧ�����㺯��
    double applyOp(double a, double b, char op) {
        switch (op) {
        case '+': return a + b;   // �ӷ�����
        case '-': return a - b;   // ��������
        case '*': return a * b;   // �˷�����
        case '/': return a / b;   // ��������
        case '^': return pow(a, b);  // ָ������
        default: return 0;        // Ĭ���������0
        }
    }

public:
    // ������ʽ��ֵ����
    double evaluateExpression(string expression) {
        stack<double> values;   // �洢�������Ķ�ջ
        stack<char> ops;        // �洢������Ķ�ջ

        for (int i = 0; i < expression.length(); i++) {
            if (expression[i] == ' ')
                continue;

            if (expression[i] == '(') {
                ops.push(expression[i]);  // ������������ջ
            }
            else if (isdigit(expression[i]) || expression[i] == '.') {
                // �������֣�����С��������
                double val = 0;
                double decimal = 10.0;
                while (i < expression.length() && (isdigit(expression[i]) || expression[i] == '.')) {
                    if (expression[i] == '.') {
                        // ����С������
                        i++;
                        while (i < expression.length() && isdigit(expression[i])) {
                            val = val + (expression[i] - '0') / decimal;
                            decimal *= 10.0;
                            i++;
                        }
                    }
                    else {
                        // ������������
                        val = val * 10 + expression[i] - '0';
                        i++;
                    }
                }
                values.push(val);  // ����ֵ��ջ
                i--;
            }
            else if (expression[i] == ')') {
                // ����������
                while (!ops.empty() && ops.top() != '(') {
                    double val2 = values.top();
                    values.pop();

                    double val1 = values.top();
                    values.pop();

                    char op = ops.top();
                    ops.pop();

                    values.push(applyOp(val1, val2, op));  // ���㲢��ջ
                }
                if (!ops.empty())
                    ops.pop();  // ����������
            }
            else {
                // ���������
                while (!ops.empty() && priority(ops.top()) >= priority(expression[i])) {
                    double val2 = values.top();
                    values.pop();

                    double val1 = values.top();
                    values.pop();

                    char op = ops.top();
                    ops.pop();

                    values.push(applyOp(val1, val2, op));  // ���㲢��ջ
                }
                ops.push(expression[i]);  // �������ջ
            }
        }

        // ����ʣ�������
        while (!ops.empty()) {
            double val2 = values.top();
            values.pop();

            double val1 = values.top();
            values.pop();

            char op = ops.top();
            ops.pop();

            values.push(applyOp(val1, val2, op));  // ���㲢��ջ
        }

        return values.top();  // �������ս��
    }
};