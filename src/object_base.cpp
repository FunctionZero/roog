#include "object_base.hpp"
#include "object_misc.hpp"
#include "object_creature.hpp"
#include "map_class.hpp"
#include "maptile_class.hpp"
#include "game_main.hpp"

Object::Object()
{
    SetParent(nullptr);
    ObjectType = OBJECT_OBJECT;

    DisplayChar = '?';
    DisplayColor = &TCODColor::pink;
}

Object::Object(Object* argParent)
{
    Object();
    SetParent(argParent);
}

Object::~Object()
{
    //Parent->RemoveChild(this);
}

int Object::GetContainerLevel()
{
    Object* temp = this;
    if(this->Parent == nullptr)
        return 0;

    else
    {
        int n = 0;
        while(temp->Parent != nullptr)
        {
            n++;
            temp = temp->Parent;
        }
        return n;
    }
}

Vector2 Object::GetPosition()
{
    if(GetContainerLevel() == 0)
    {
        MapTile *temp = dynamic_cast<MapTile*>(this);
        /*
        unsigned int offset = temp - temp->ParentMap->vectorMapTile.data();
        unsigned int sizeX = temp->ParentMap->sizeX;

        return Vector2(offset % sizeX, offset / sizeX);
        */
        return Vector2(temp->posX, temp->posY);
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

class MapTile;
class Misc;
class Creature;

Object* Object::CreateChild(enumObjectType argObjectType)
{
    switch(argObjectType)
    {
    case OBJECT_OBJECT:
        Game::Game->ObjectList.push_back(Object());
        break;
    case OBJECT_MAPTILE:
        Game::Game->ObjectList.push_back(MapTile());
        break;
    case OBJECT_MISC:
        Game::Game->ObjectList.push_back(Misc());
        break;
    case OBJECT_CREATURE:
        Game::Game->ObjectList.push_back(Creature());
        break;
    }

    Game::Game->ObjectList.back().SetParent(this);
    this->AddChild(&Game::Game->ObjectList.back());
    return &Game::Game->ObjectList.back();
}

void Object::AddChild(Object* argChild)
{
    this->Child.push_back(argChild);
    this->Child.unique();
}

void Object::RemoveChild(Object* argChild)
{
    this->Child.remove(argChild);
}

void Object::SetParent(Object* argParent)
{
    this->Parent = argParent;
}

void Object::MoveBy(Vector2 vect)
{
    Object::MoveBy(vect.x, vect.y);
}

void Object::MoveBy(int x, int y)
{
    Vector2 origin = this->GetPosition();
    Object::MoveTo(origin.x + x, origin.y + y);
}

void Object::MoveTo(Vector2 vect)
{
    Object::MoveTo(vect.x, vect.y);
}

void Object::MoveTo(int x, int y)
{
    if(Game::IsPositionLegal(x, y))
    {
        MapTile* temp = Game::Game->CurrentMap->GetTileAt(x, y);
        if(temp->passable)
        {
            this->MoveInto(temp);
            Game::Tick();
        }
    }
}
