#pragma once
#include "entity_class.hpp"
#include "template_creature.hpp"
#include "boost_fixedwidth.hpp"

class Creature : public Entity
{
public:
    uint16_t Health;
    uint16_t HealthMax;
    uint16_t Mana;
    uint16_t ManaMax;

    Creature();
    virtual ~Creature();

    void UseTemplate(TCreature* arg);
};
