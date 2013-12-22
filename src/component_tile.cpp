#include "component_tile.hpp"

cTile::cTile()
{

}

cTile::~cTile()
{

}

bool cTile::IsWalkable()
{
    return walkable;
}

bool cTile::IsTransparent()
{
    return transparent;
}

Vector2 cTile::GetPosition()
{
    return Vector2(posX, posY);
}
