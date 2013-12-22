#pragma once
#include "entity_class.hpp"

class Component
{
public:
    Entity* Parent;

    virtual void OnTick();
};
