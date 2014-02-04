#include "entity_creature.hpp"

Creature::Creature() : Entity(EntityType::Creature) {}
Creature::~Creature() {}

void Creature::UseTemplate(TCreature* arg)
{
    DisplayChar = arg->DisplayChar;
    DisplayFColor = arg->DisplayFColor;
    DisplayBColor = arg->DisplayBColor;
    Health = arg->HealthMax;
    HealthMax = arg->HealthMax;
    Mana = arg->ManaMax;
    ManaMax = arg->ManaMax;
}
