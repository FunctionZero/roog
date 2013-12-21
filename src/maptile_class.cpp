#include "maptile_class.hpp"

MapTile::MapTile(Map* ParentMap)
{
    MapTile();
    this->ParentMap = ParentMap;
}

MapTile::MapTile()
{
    Parent = nullptr;
}

void MapTile::CopyTile(const MapTile& tile)
{
    this->Passable = tile.Passable;
    this->Transparent = tile.Transparent;
}
