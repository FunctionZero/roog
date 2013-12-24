#pragma once
#include <list>
#include "object_base.hpp"
#include "object_creature.hpp"
#include "template_base.hpp"

class ObjectPool
{
public:
    std::list<Object*> ObjectList;

    Object* NewObject(enumObjectType objType);
    Object* NewObject(TObject* objTemplate);
};
