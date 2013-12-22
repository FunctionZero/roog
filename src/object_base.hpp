#pragma once
#include <list>
#include "boost_fixedwidth.hpp"
#include "system_vector2.hpp"
#include "libtcod.hpp"

enum enumObjectType
{
    OBJECT_OBJECT,
    OBJECT_MAPTILE
};

class Object
{
public:
    Object* Parent;
    std::list<Object*> Child;
    enumObjectType ObjectType;

    char DisplayChar;
    const TCODColor* DisplayColor;

    Object();
    Object(Object* argParent);

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
