#pragma once
#include <list>
#include "object_enumtypes.hpp"
#include "template_base.hpp"
#include "boost_fixedwidth.hpp"
#include "misc_vector2.hpp"
#include "libtcod.hpp"

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
    virtual ~Object();

    virtual int GetContainerLevel();
    virtual Vector2 GetPosition();
    virtual void ChangeToTemplate(TObject* argTemplate);

    void MoveInto(Object* Parent);
    void AddChild(Object* argChild);
    void RemoveChild(Object* argChild);
    void SetParent(Object* argParent);

    void MoveBy(Vector2 vect);
    void MoveBy(int x, int y);
    void MoveTo(Vector2 vect);
    void MoveTo(int x, int y);
};
