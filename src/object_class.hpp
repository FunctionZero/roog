#pragma once
#include <list>
#include "boost_fixedwidth.hpp"
#include "system_vector2.hpp"
#include "libtcod.hpp"

class Object
{
public:
    Object* Parent;
    std::list<Object*> Child;
    char DisplayChar;
    const TCODColor* DisplayColor;

    uint8_t GetContainerLevel();
    Vector2 GetPosition();
    void Copy(const Object& obj);

    void MoveInto(Object* Parent);
    Object* CreateChild();

    void AddChild(Object* Child);
    void RemoveChild(Object* Child);
    void SetParent(Object* Parent);
};
