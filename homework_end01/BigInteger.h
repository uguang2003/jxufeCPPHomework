#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>

using namespace std;

struct BigInteger {
    vector<int> digits;

    BigInteger() {}

    BigInteger(string num) {
        for (int i = num.size() - 1; i >= 0; i--) {
            digits.push_back(num[i] - '0');
        }
    }

    BigInteger(vector<int> num) : digits(num) {}

    void removeLeadingZeros() {
        while (digits.size() > 1 && digits.back() == 0) {
            digits.pop_back();
        }
    }

    BigInteger operator+(const BigInteger& other) const {
        vector<int> result(max(digits.size(), other.digits.size()) + 1, 0);
        for (int i = 0; i < result.size(); i++) {
            if (i < digits.size()) result[i] += digits[i];
            if (i < other.digits.size()) result[i] += other.digits[i];
            if (result[i] >= 10) {
                result[i] -= 10;
                result[i + 1] += 1;
            }
        }
        return BigInteger(result);
    }

    BigInteger operator-(const BigInteger& other) const {
        vector<int> result(digits.size(), 0);
        for (int i = 0; i < digits.size(); i++) {
            result[i] += digits[i];
            if (i < other.digits.size()) result[i] -= other.digits[i];
            if (result[i] < 0) {
                result[i] += 10;
                result[i + 1] -= 1;
            }
        }
        return BigInteger(result);
    }

    BigInteger operator*(const BigInteger& other) const {
        vector<int> result(digits.size() + other.digits.size(), 0);
        for (int i = 0; i < digits.size(); i++) {
            for (int j = 0; j < other.digits.size(); j++) {
                result[i + j] += digits[i] * other.digits[j];
                result[i + j + 1] += result[i + j] / 10;
                result[i + j] %= 10;
            }
        }
        return BigInteger(result);
    }

    pair<BigInteger, BigInteger> division(const BigInteger& other) const {
        if (other == BigInteger("0")) {
            throw invalid_argument("Division by zero");
        }

        BigInteger quotient, remainder;
        BigInteger currentDividend;
        for (int i = digits.size() - 1; i >= 0; i--) {
            currentDividend.digits.insert(currentDividend.digits.begin(), digits[i]);
            currentDividend.removeLeadingZeros();
            int x = 0, l = 0, r = 10;
            while (l <= r) {
                int m = (l + r) / 2;
                BigInteger t = other * BigInteger(to_string(m));
                if (t <= currentDividend) {
                    x = m;
                    l = m + 1;
                }
                else {
                    r = m - 1;
                }
            }
            quotient.digits.insert(quotient.digits.begin(), x);
            currentDividend = currentDividend - other * BigInteger(to_string(x));
        }
        quotient.removeLeadingZeros();
        remainder = currentDividend;
        return make_pair(quotient, remainder);
    }

    BigInteger operator%(const BigInteger& other) const {
        pair<BigInteger, BigInteger> result = division(other);
        return result.second;
    }

    bool operator<(const BigInteger& other) const {
        if (digits.size() != other.digits.size()) {
            return digits.size() < other.digits.size();
        }
        for (int i = digits.size() - 1; i >= 0; i--) {
            if (digits[i] != other.digits[i]) {
                return digits[i] < other.digits[i];
            }
        }
        return false;
    }

    bool operator<=(const BigInteger& other) const {
        return *this < other || *this == other;
    }

    bool operator==(const BigInteger& other) const {
        return digits == other.digits;
    }

    bool operator!=(const BigInteger& other) const {
        return !(*this == other);
    }

    bool operator>(const BigInteger& other) const {
        return !(*this <= other);
    }

    bool operator>=(const BigInteger& other) const {
        return !(*this < other);
    }

    friend ostream& operator<<(ostream& os, const BigInteger& num) {
        for (int i = num.digits.size() - 1; i >= 0; i--) {
            os << num.digits[i];
        }
        return os;
    }
};
