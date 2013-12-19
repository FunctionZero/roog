#pragma once

class Vector3
{
public:
    int x;
    int y;
    int z;

    Vector3();
    Vector3(int x, int y, int z);
};

Vector3 operator+(const Vector3 &VectorA, const Vector3 &VectorB);
Vector3 operator-(const Vector3 &VectorA, const Vector3 &VectorB);
