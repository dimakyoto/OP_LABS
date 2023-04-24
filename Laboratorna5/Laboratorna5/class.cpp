#include "class.h"

Point :: Point() {
    x = 0;
    y = 0;
}
Point :: Point(double x, double y) {
    this->x = x;
    this->y = y;
}

THexagon :: THexagon(Point a, Point b, Point c, Point d, Point e, Point f) {
    this->a = a;
    this->b = b;
    this->c = c;
    this->d = d;
    this->e = e;
    this->f = f;
}

double THexagon :: getSideLength(Point p1, Point p2) {
    double dx = p1.x - p2.x;
    double dy = p1.y - p2.y;
    return sqrt(dx * dx + dy * dy);
}
double THexagon :: getPerimeter() {
    double ab = getSideLength(a, b);
    double bc = getSideLength(b, c);
    double cd = getSideLength(c, d);
    double de = getSideLength(d, e);
    double ef = getSideLength(e, f);
    double fa = getSideLength(f, a);
    return ab + bc + cd + de + ef + fa;
}
double THexagon :: getArea() {
    double s = getSideLength(a, b);
    double r = s / (2 * sin(M_PI / 6));
    return 6 * r * r * sin(M_PI / 3);
}

TPentagon :: TPentagon(Point a, Point b, Point c, Point d, Point e) {
    this->a = a;
    this->b = b;
    this->c = c;
    this->d = d;
    this->e = e;
}

double TPentagon :: getSideLength(Point p1, Point p2) {
    double dx = p1.x - p2.x;
    double dy = p1.y - p2.y;
    return sqrt(dx * dx + dy * dy);
}
double TPentagon :: getPerimeter() {
    double ab = getSideLength(a, b);
    double bc = getSideLength(b, c);
    double cd = getSideLength(c, d);
    double de = getSideLength(d, e);
    double ea = getSideLength(e, a);
    return ab + bc + cd + de + ea;
}
double TPentagon :: getArea() {
    double s = getSideLength(a, b);
    double r = s / (2 * sin(M_PI / 5));
    return 5 * r * r * sin(2 * M_PI / 5);
}