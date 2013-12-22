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

    virtual int GetContainerLevel();
    virtual Vector2 GetPosition();
    virtual void Copy(const Object& obj);

    virtual void MoveInto(Object* Parent);
    virtual Object* CreateChild();

    virtual void AddChild(Object* argChild);
    virtual void RemoveChild(Object* argChild);
    virtual void SetParent(Object* argParent);

    virtual void MoveBy(Vector2 vect);
    virtual void MoveBy(int x, int y);
    virtual void MoveTo(Vector2 vect);
    virtual void MoveTo(int x, int y);
};
