#include <iostream>
#include <cmath>
#include "Sector.h"

using namespace std;

int main() {
    double centerX, centerY, radius, angle;
    cout << "输入扇形的中心坐标 （x y）: ";
    cin >> centerX >> centerY;
    cout << "输入扇形的半径: ";
    cin >> radius;
    cout << "输入扇形的角度（以弧度为单位）: ";
    cin >> angle;

    Sector sector(centerX, centerY, radius, angle);

    double area = sector.calculateArea();

    cout << "该扇形的面积是: " << area << endl;

    return 0;
}
