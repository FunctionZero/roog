#pragma once
#include <string>
#include "system_vector2.hpp"

class BaseEntry
{
public:
    std::string label;

    BaseEntry(std::string label);

    virtual void Loop() = 0;
    virtual void Display() = 0;
    virtual bool IsSelected() = 0;
    virtual bool IsPointInBoundaries(Vector2 pos) = 0;
    virtual bool IsPointInBoundaries(uint8_t x, uint8_t y) = 0;
};
