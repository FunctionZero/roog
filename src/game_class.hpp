#pragma once
#include <list>
#include "map_class.hpp"
#include "object_base.hpp"

class classGame
{
public:
    Map* CurrentMap;
    Object* PlayerObject;

    std::list<Object> ObjectList;

    classGame();
    ~classGame();
};
