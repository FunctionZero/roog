#pragma once

class Vector2
{
public:
    int x;
    int y;

    Vector2(int x, int y);
};

Vector2 operator+(const Vector2 &VectorA, const Vector2 &VectorB);
Vector2 operator-(const Vector2 &VectorA, const Vector2 &VectorB);
