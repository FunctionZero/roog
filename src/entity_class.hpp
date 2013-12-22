#pragma once
#include <list>
#include <vector>

//class Component;

class Entity
{
public:
    Entity* Parent;
    std::list<Entity*> ChildList;
    //std::list<Component> ComponentList;

    Entity();
    ~Entity();

    //void Add(Component argComponent);

    void OnTick();
};
