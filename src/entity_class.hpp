#pragma once
#include <list>
#include <vector>

class Component;

class Entity
{
public:
    Entity* Parent;
    std::list<Entity*> Child;
    std::list<Component> vectorComponent;

    Entity();
    ~Entity();

    void Add(Component argComponent);
    void Remove(Component argComponent);
    Component& Iterate();

    void OnTick();
};
