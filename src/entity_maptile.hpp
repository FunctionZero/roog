#pragma once
#include "entity_class.hpp"
#include "template_maptile.hpp"
#include "boost_fixedwidth.hpp"

class Map;

class Maptile : public Entity
{
public:
    Map* ParentMap;
    uint32_t posX;
    uint32_t posY;

    bool isPassable;
    bool isTransparent;

    Maptile();
    virtual ~Maptile();

    virtual Vector2 GetPosition();
    virtual Map* GetParentMap();

    void UseTemplate(TMaptile* arg);
};
