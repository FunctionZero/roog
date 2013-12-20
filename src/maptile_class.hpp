#pragma once
#include "object_class.hpp"

class MapTile : public Object
{
public:
    bool Passable;
    bool Transparent;

    MapTile();
    MapTile(const MapTile& tile);
};
