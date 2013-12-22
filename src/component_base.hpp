#pragma once
#include "entity_class.hpp"

class Component
{
public:
    Entity* Parent;

    Component();
    ~Component();
    virtual void Copy(Component* argComponent);
    virtual void OnTick();
};
