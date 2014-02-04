#pragma once
#include <list>
#include "libtcod.hpp"
#include "entity_type.hpp"
#include "misc_vector2.hpp"
#include "boost_fixedwidth.hpp"

class Map;

class Entity
{
public:
    const EntityType Type;
    Entity* Parent;
    std::list<Entity*> Child;

    char DisplayChar;
    const TCODColor* DisplayFColor;
    const TCODColor* DisplayBColor;

    Entity();
    Entity(EntityType arg);
    virtual ~Entity();

    uint8_t GetContainerLevel();
    virtual Vector2 GetPosition();
    virtual Map* GetParentMap();

    void MoveTo(uint16_t x, uint16_t y);
    void MoveTo(Vector2 pos);
    void MoveBy(uint16_t x, uint16_t y);
    void MoveBy(Vector2 pos);

    void AddChild(Entity* arg);
    void RemoveChild(Entity* arg);
    void SetParent(Entity* arg);
};
