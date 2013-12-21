#include "object_class.hpp"
#include "map_class.hpp"
#include "maptile_class.hpp"
#include "game_main.hpp"

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

void Object::Copy(const Object& obj)
{
    this->DisplayChar = obj.DisplayChar;
    this->DisplayColor = obj.DisplayColor;
}

void Object::MoveInto(Object* Parent)
{
    this->Parent->RemoveChild(this);
    this->Parent = Parent;
    Parent->AddChild(this);
}

Object* Object::CreateChild()
{
    Game::Game->ObjectList.push_back(Object());
    Game::Game->ObjectList.back().SetParent(this);
    this->AddChild(&Game::Game->ObjectList.back());
    return &Game::Game->ObjectList.back();
}

void Object::AddChild(Object* Child)
{
    this->Child.push_back(Child);
    this->Child.unique();
}

void Object::RemoveChild(Object* Child)
{
    this->Child.remove(Child);
}

void Object::SetParent(Object* Parent)
{
    this->Parent = Parent;
}
