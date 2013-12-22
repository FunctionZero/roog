#pragma once
#include "component_base.hpp"
#include "boost_fixedwidth.hpp"

class Map;

class cTile : virtual public Component
{
    bool passable;
    bool transparent;
    uint16_t posX;
    uint16_t posY;
    Map* ParentMap;

    cTile();
    ~cTile();
    virtual void Copy(cTile* argcTile);
};
