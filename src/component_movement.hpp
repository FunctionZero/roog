#pragma once
#include "component_base.hpp"
#include "boost_fixedwidth.hpp"

class cMovement : public Component
{
public:
    uint8_t costMovement;

    cMovement();
    virtual ~cMovement();
};
