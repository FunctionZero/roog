#include "entity_class.hpp"
#include "entity_factory.hpp"
#include "system_exception.hpp"
#include "game_map.hpp"

Entity::Entity() : Entity(EntityType::Entity) {}
Entity::Entity(EntityType arg) : Type(arg), Parent(nullptr) {}
Entity::~Entity() {}

uint8_t Entity::GetContainerLevel()
{
    Entity* pointer = this;

    uint8_t n = 0;
    while(pointer->Parent != nullptr)
    {
        n++;
        pointer = pointer->Parent;
    }
    return n;
}

Vector2 Entity::GetPosition()
{
    if(GetContainerLevel() == 0)
        System::Error("Parentless entity cannot get position.");

    return Parent->GetPosition();
}

Map* Entity::GetParentMap()
{
    if(GetContainerLevel() == 0)
        System::Error("Parentless entity cannot get parent map.");

    return Parent->GetParentMap();
}

void Entity::MoveTo(uint16_t x, uint16_t y)
{
    GetParentMap()->GetTileAt(x, y)->AddChild(this);
}

void Entity::MoveTo(Vector2 pos)
{
    MoveTo(pos.x, pos.y);
}

void Entity::MoveBy(uint16_t x, uint16_t y)
{
    Vector2 pos = GetPosition();
    MoveTo(pos.x + x, pos.y + y);
}

void Entity::MoveBy(Vector2 pos)
{
    MoveBy(pos.x, pos.y);
}


void Entity::AddChild(Entity* arg)
{
    if(arg != nullptr)
    {
        Child.remove(arg);
        Child.push_back(arg);
        if(this != arg->Parent)
            arg->SetParent(this);
    }
}

void Entity::RemoveChild(Entity* arg)
{
    arg->Parent = nullptr;
    Child.remove(arg);
    //Warning: calling function needs to set arg's new parent.
    //See Entity::SetParent.
}

void Entity::SetParent(Entity* arg)
{
    if(Parent != arg)
    {
        if(Parent != nullptr)
            Parent->RemoveChild(this);
        Parent = arg;
        arg->AddChild(this);
        //ParentMap = arg->ParentMap;
    }
    else
    {
        System::Warning("Tried to set entity's parent to current parent.");
    }
}
