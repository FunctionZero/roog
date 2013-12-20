#pragma once
#include <vector>
#include "boost_fixedwidth.hpp"
#include "system_vector2.hpp"

class Object
{
public:
    Object* Parent;
    std::vector<Object> Child;

    uint8_t GetContainerLevel();
    Vector2 GetPosition();
};
