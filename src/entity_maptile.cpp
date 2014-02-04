#include "entity_maptile.hpp"

Maptile::Maptile() : Entity(EntityType::Maptile) {}
Maptile::~Maptile() {}

Vector2 Maptile::GetPosition()
{
    return Vector2(posX, posY);
}

Map* Maptile::GetParentMap()
{
    return ParentMap;
}

void Maptile::UseTemplate(TMaptile* arg)
{
    DisplayChar = arg->DisplayChar;
    DisplayFColor = arg->DisplayFColor;
    DisplayBColor = arg->DisplayBColor;
    isPassable = arg->isPassable;
    isTransparent = arg->isTransparent;
}

