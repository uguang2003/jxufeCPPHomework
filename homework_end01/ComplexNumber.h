#pragma once

struct Complex {
    double real;
    double imag;
};

class ComplexNumber {
private:
    Complex num1;
    Complex num2;

public:
    ComplexNumber(double real1, double imag1, double real2, double imag2) {
        num1.real = real1;
        num1.imag = imag1;
        num2.real = real2;
        num2.imag = imag2;
    }

    void setNumber1(double real, double imag) {
        num1.real = real;
        num1.imag = imag;
    }

    void setNumber2(double real, double imag) {
        num2.real = real;
        num2.imag = imag;
    }

    Complex getNumber1() {
        return num1;
    }

    Complex getNumber2() {
        return num2;
    }

    Complex add() {
        Complex result;
        result.real = num1.real + num2.real;
        result.imag = num1.imag + num2.imag;
        return result;
    }

    Complex subtract() {
        Complex result;
        result.real = num1.real - num2.real;
        result.imag = num1.imag - num2.imag;
        return result;
    }

    Complex multiply() {
        Complex result;
        result.real = num1.real * num2.real - num1.imag * num2.imag;
        result.imag = num1.real * num2.imag + num1.imag * num2.real;
        return result;
    }

    Complex divide() {
        Complex result;
        result.real = (num1.real * num2.real + num1.imag * num2.imag) / (num2.real * num2.real + num2.imag * num2.imag);
        result.imag = (num2.real * num1.imag - num1.real * num2.imag) / (num2.real * num2.real + num2.imag * num2.imag);
        return result;
    }
};