#pragma once
#include "object_class.hpp"

class Map;

class MapTile : public Object
{
public:
    bool Passable;
    bool Transparent;

    Map* ParentMap;

    MapTile(Map* ParentMap);
    MapTile();

    void CopyTile(const MapTile& tile);
};
