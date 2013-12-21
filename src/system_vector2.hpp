#pragma once

struct Vector2
{
    int x;
    int y;

    Vector2();
    Vector2(int x, int y);
};

Vector2 operator+(const Vector2 &VectorA, const Vector2 &VectorB);
Vector2 operator-(const Vector2 &VectorA, const Vector2 &VectorB);
