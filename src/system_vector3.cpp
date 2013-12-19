#include "system_vector3.hpp"

Vector3::Vector3()
{
    this->x = 0;
    this->y = 0;
    this->z = 0;
}

Vector3::Vector3(int x, int y, int z)
{
    this->x = x;
    this->y = y;
    this->z = z;
}

Vector3 operator+(const Vector3 &VectorA, const Vector3 &VectorB)
{
    return Vector3(VectorA.x + VectorB.x, VectorA.y + VectorB.y, VectorA.z + VectorB.z);
}

Vector3 operator-(const Vector3 &VectorA, const Vector3 &VectorB)
{
    return Vector3(VectorA.x - VectorB.x, VectorA.y - VectorB.y, VectorA.z - VectorB.z);
}
