#include "object_base.hpp"
#include "object_maptile.hpp"
#include "object_creature.hpp"
#include "system_exception.hpp"
#include "map_class.hpp"
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
    return Parent->GetPosition();
}

void Object::ChangeToTemplate(TObject* argTemplate)
{
    if(ObjectType == argTemplate->ObjectType)
    {
        DisplayChar = argTemplate->DisplayChar;
        DisplayColor = argTemplate->DisplayColor;
    }
    else
    {
        System::Error("Object tried to change into different ObjectType.", 201);
    }
}

void Object::MoveInto(Object* Parent)
{
    this->Parent->RemoveChild(this);
    this->Parent = Parent;
    Parent->AddChild(this);
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
