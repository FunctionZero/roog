#include "object_class.hpp"
#include "map_class.hpp"
#include "maptile_class.hpp"

uint8_t Object::GetContainerLevel()
{
    if(this == nullptr)
        return 0;
    else
        return Parent->GetContainerLevel() + 1;
}

Vector2 Object::GetPosition()
{
    if(GetContainerLevel() == 0)
    {
        MapTile *temp = static_cast<MapTile*>(this);
        unsigned int offset = temp - temp->ParentMap->vectorMapTile.data();
        unsigned int sizeX = temp->ParentMap->sizeX;

        return Vector2(offset % sizeX, offset / sizeX);
    }
    else
        return Parent->GetPosition();
}
