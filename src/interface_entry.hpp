#pragma once
#include <string>
#include "boost_fixedwidth.hpp"
#include "misc_vector2.hpp"

class BaseEntry
{
public:
    uint8_t ID;
    std::string label;

    BaseEntry(std::string label);

    virtual void Loop() = 0;
    virtual void Display() = 0;
    virtual bool IsSelected() = 0;
};
