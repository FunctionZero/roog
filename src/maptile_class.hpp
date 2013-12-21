#pragma once
#include "libtcod.hpp"
#include "object_class.hpp"
#include "boost_fixedwidth.hpp"

class Map;

class MapTile : public Object
{
public:
    bool passable;
    bool transparent;

    uint16_t posX;
    uint16_t posY;

    Map* ParentMap;

    MapTile(Map* ParentMap = nullptr);

    void Copy(const MapTile& tile);
};
