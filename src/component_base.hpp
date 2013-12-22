#pragma once
#include "entity_class.hpp"

class Component
{
public:
    Entity* Parent;

    Component();
    virtual ~Component();

    virtual void OnTick() = 0;
};
