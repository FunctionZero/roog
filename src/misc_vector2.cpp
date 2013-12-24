#include "misc_vector2.hpp"

Vector2::Vector2()
{
    this->x = 0;
    this->y = 0;
}

Vector2::Vector2(int x, int y)
{
    this->x = x;
    this->y = y;
}

Vector2 operator+(const Vector2 &VectorA, const Vector2 &VectorB)
{
    return Vector2(VectorA.x + VectorB.x, VectorA.y + VectorB.y);
}

Vector2 operator-(const Vector2 &VectorA, const Vector2 &VectorB)
{
    return Vector2(VectorA.x - VectorB.x, VectorA.y - VectorB.y);
}
