#pragma once
class Sector {
private:
    double centerX;
    double centerY;
    double radius;
    double angle;

public:
    Sector(double x = 0, double y = 0, double r = 0, double a = 0) : centerX(x), centerY(y), radius(r), angle(a) {}

    void setCenter(double x, double y) {
        centerX = x;
        centerY = y;
    }

    void setRadius(double r) {
        radius = r;
    }

    void setAngle(double a) {
        angle = a;
    }

    double getCenterX() {
        return centerX;
    }

    double getCenterY() {
        return centerY;
    }

    double getRadius() {
        return radius;
    }

    double getAngle() {
        return angle;
    }

    double calculateArea() {
        return 0.5 * radius * radius * angle;
    }
};

