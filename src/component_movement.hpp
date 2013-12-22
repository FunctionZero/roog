#pragma once
#include "component_base.hpp"
#include "boost_fixedwidth.hpp"

class cMovement : virtual public Component
{
public:
    uint8_t costMovement;

    cMovement();
    ~cMovement();
    virtual void Copy(cMovement* argcMovement);
};
