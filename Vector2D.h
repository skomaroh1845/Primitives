#pragma once

#include <iostream>

class Vector2D final {
public:
    double x, y;

    Vector2D() : x(0), y(0) {}

    Vector2D(double _x, double _y) : x(_x), y(_y) {}

    Vector2D(const Vector2D& v2) : Vector2D(v2.x, v2.y) {}

    void rotate(double angle); //Поворачивает веткор на угол angle, заданный в градусах

    double length() const;
   
    bool operator==(const Vector2D &v2) const;

    bool operator!=(const Vector2D &v2) const;

    Vector2D operator+(const Vector2D &v2) const;

    Vector2D operator-(const Vector2D &v2) const;

    Vector2D operator*(const double a) const;

    Vector2D operator/(const double a) const;

    Vector2D& operator+=(const Vector2D &v2);

    double operator*(const Vector2D &v2) const; //Скалярное произведение векторов
};

Vector2D operator*(double a, const Vector2D &v);

std::ostream &operator<<(std::ostream &os, const Vector2D &v);

std::istream &operator>>(std::istream &is, Vector2D &v);