#include "maptile_class.hpp"
#include "system_random.hpp"

MapTile::MapTile(Map* ParentMap)
{
    this->ParentMap = ParentMap;
    this->SetParent(nullptr);

    if(RandomOneIn(6))
    {
        Passable = false;
        Transparent = false;
        DisplayChar = 'T';
        DisplayColor = &TCODColor::green;
    }

    else
    {
        Passable = true;
        Transparent = true;
        DisplayChar = '.';
        DisplayColor = &TCODColor::darkGrey;
    }
}

void MapTile::Copy(const MapTile& tile)
{
    Passable = tile.Passable;
    Transparent = tile.Transparent;
    DisplayChar = tile.DisplayChar;
    DisplayColor = tile.DisplayColor;
}
