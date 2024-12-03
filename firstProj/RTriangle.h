//
//  RTriangle.h
//  firstProj
//
//  Created by Андрей Ярема on 10.09.2024.
//

#ifndef RTriangle_h
#define RTriangle_h



#pragma once
#include <array>

class RTriangle
{
private:
    double a;
    double b;

public:
    RTriangle(double sideA, double sideB);
    RTriangle();

    double getA() const;
    double getB() const;

    void setA(double sideA);
    void setB(double sideB);

    void resizeAPlus(double percent);
    void resizeAMinus(double percent);

    void resizeBPlus(double percent);
    void resizeBMinus(double percent);

    double getRadius() const;
    double getHalfMeter() const;

    std::array <double, 3>  getAngle() const;

    double getHypotenuse() const;
};



#endif /* RTriangle_h */
