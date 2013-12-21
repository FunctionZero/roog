#include "object_class.hpp"
#include "map_class.hpp"
#include "maptile_class.hpp"
#include "game_main.hpp"

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
        if(temp->Passable)
        {
            this->MoveInto(temp);
        }
    }
}
