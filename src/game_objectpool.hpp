#pragma once
#include <list>
#include "object_base.hpp"
#include "object_creature.hpp"
#include "object_misc.hpp"
#include "template_base.hpp"

class ObjectPool
{
public:
    std::list<Object*> ObjectList;
    std::list<Object> BaseList;
    std::list<Creature> CreatureList;
    std::list<Misc> MiscList;

    Object* NewObject(enumObjectType objType);
    Object* NewObject(TObject* objTemplate);
};
