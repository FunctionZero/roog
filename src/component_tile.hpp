#pragma once
#include "component_base.hpp"
#include "boost_fixedwidth.hpp"
#include "system_vector2.hpp"

class Map;

class cTile : public Component
{
public:
    bool walkable;
    bool transparent;
    uint16_t posX;
    uint16_t posY;
    Map* ParentMap;

    cTile();
    virtual ~cTile();

    bool IsWalkable();
    bool IsTransparent();
    Vector2 GetPosition();
};
