#define _USE_MATH_DEFINES

#include <iostream>
#include <cmath>
#include "Vector2D.h"

using namespace std;

void Vector2D::rotate(double angle) {  // angle in deg 
    angle = angle * M_PI / 180;  // move to radians
    double _x = x, _y = y;
    x = _x * cos(angle) + _y * sin(angle);
    y = -_x * sin(angle) + _y * cos(angle);
} 

bool Vector2D::operator==(const Vector2D &v2) const {
    return x == v2.x && y == v2.y;
}

bool Vector2D::operator!=(const Vector2D &v2) const {
    return !(*this == v2);
}

Vector2D Vector2D::operator+(const Vector2D &v2) const {
    return Vector2D(x + v2.x, y + v2.y);
}

Vector2D Vector2D::operator-(const Vector2D &v2) const {
    return Vector2D(x - v2.x, y - v2.y);
}

Vector2D Vector2D::operator*(const double a) const {
    return Vector2D(x * a, y * a);
}

double Vector2D::operator*(const Vector2D &v2) const {
    return x * v2.x + y * v2.y;
}

Vector2D operator*(double a, const Vector2D &v) {
    return v * a;
}

ostream &operator<<(ostream &os, const Vector2D &v) {
    os << '(' << v.x << "; " << v.y << ')';
    return os;
}

istream &operator>>(istream &is, Vector2D &v) {
    is >> v.x >> v.y;
    return is;
}

Vector2D& Vector2D::operator+=(const Vector2D& v2) {
    this->x += v2.x;
    this->y += v2.y;
    return *this;
}