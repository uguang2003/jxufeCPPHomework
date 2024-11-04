#include <iostream>
using namespace std;

int main() {
    const int height = 11;
    int triangle[height][height];

    // 初始化杨辉三角形的第一列和对角线上的值为1
    for (int i = 0; i < height; i++) {
        triangle[i][0] = 1;
        triangle[i][i] = 1;
    }

    // 计算其他位置的值
    for (int i = 2; i < height; i++) {
        for (int j = 1; j < i; j++) {
            triangle[i][j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
        }
    }

    // 输出杨辉三角形
    for (int i = 0; i < height; i++) {
        // 打印每行之前的空格，使其居中显示
        for (int k = 0; k < height - i - 1; k++) {
            cout << " ";
        }
          
        for (int j = 0; j <= i; j++) {
            cout << triangle[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
