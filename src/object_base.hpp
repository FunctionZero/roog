#pragma once
#include <list>
#include "boost_fixedwidth.hpp"
#include "misc_vector2.hpp"
#include "libtcod.hpp"

enum enumObjectType
{
    OBJECT_OBJECT,
    OBJECT_MAPTILE,
    OBJECT_MISC,
    OBJECT_CREATURE
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
    ~Object();

    virtual int GetContainerLevel();
    virtual Vector2 GetPosition();
    void Copy(const Object& obj);

    void MoveInto(Object* Parent);
    Object* CreateChild(enumObjectType argObjectType);

    void AddChild(Object* argChild);
    void RemoveChild(Object* argChild);
    void SetParent(Object* argParent);

    void MoveBy(Vector2 vect);
    void MoveBy(int x, int y);
    void MoveTo(Vector2 vect);
    void MoveTo(int x, int y);
};
