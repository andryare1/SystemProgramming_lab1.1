#include "RTriangle.h"
#include <cmath>
#include <array>
#include <stdexcept>


RTriangle::RTriangle(double sideA, double sideB) : a(sideA), b(sideB) {

    if (a <= 0 or b <= 0) {
        throw std::invalid_argument("Сторона не может быть отрицательной!");
    }
}

RTriangle::RTriangle() : a(0), b(0) {}


double RTriangle::getA() const {
    return a;
}

double RTriangle::getB() const {
    return b;
}

double RTriangle::getHypotenuse() const {
    return sqrt(b * b + a * a);
}

void RTriangle::setA(double sideA) {
    a = sideA;
}

void RTriangle::setB(double sideB) {
    b = sideB;
}

double RTriangle::getHalfMeter() const {
    return (a + b + getHypotenuse()) / 2;
}

void RTriangle::resizeAPlus(double percent) {
    a += (a * (percent / 100));
}

void RTriangle::resizeBPlus(double percent) {
    b += (b * (percent / 100));
}

void RTriangle::resizeAMinus(double percent) {
    a -= (a * (percent / 100));
}

void RTriangle::resizeBMinus(double percent) {
    b -= (b * (percent / 100));
}

double RTriangle::getRadius() const {
    return (a * b * getHypotenuse()) / (4 * ((a * b) / 2));
}

std::array<double, 3> RTriangle::getAngle() const {
    
    double first_angle = (atan(b / a) * 180) / M_PI;
    double second_angle = 90;
    double third_angle = 180 - (90 + first_angle);
    
    return { first_angle, second_angle, third_angle };
}
