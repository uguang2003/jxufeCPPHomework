#include <iostream>

void matrixMultiplication(int* p, int m, int n, int* q, int k, int* r) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < k; j++) {
            *(r + i * k + j) = 0;
            for (int l = 0; l < n; l++) {
                *(r + i * k + j) += *(p + i * n + l) * *(q + l * k + j);
            }
        }
    }
}

int main() {
    int m1[2][3] = { {6, 8, 10}, {7, 9, 11} };
    int m2[3][2] = { {1, 2}, {3, 4}, {5, 6} };
    int result[2][2];

    matrixMultiplication(&m1[0][0], 2, 3, &m2[0][0], 2, &result[0][0]);

    // 输出结果矩阵
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            std::cout << result[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
