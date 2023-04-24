#pragma once
#define _USE_MATH_DEFINES
#include <iostream> 
#include <cmath> 
using namespace std;


class Point {
public:
    double x, y;

    Point();
    Point(double x, double y);
};


class TFigure {
public:
    virtual double getArea() = 0;
    virtual double getPerimeter() = 0;
};


class THexagon : public TFigure {
private:
    Point a = { 0, 0 }, b = { 0, 0 }, c = { 0, 0 }, d = { 0, 0 }, e = { 0, 0 }, f = { 0, 0 };

public:
    THexagon() = default;
    THexagon(Point a, Point b, Point c, Point d, Point e, Point f);

    double getSideLength(Point p1, Point p2);
    double getPerimeter() override;
    double getArea() override;
};
class TPentagon : public TFigure {
private:
    Point a = { 0, 0 }, b = { 0, 0 }, c = { 0, 0 }, d = { 0, 0 }, e = { 0, 0 };

public:
    TPentagon() = default;
    TPentagon(Point a, Point b, Point c, Point d, Point e);

    double getSideLength(Point p1, Point p2);
    double getPerimeter() override;
    double getArea() override;
};


