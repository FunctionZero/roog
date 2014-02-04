#pragma once
#include "entity_class.hpp"
#include "entity_creature.hpp"

namespace EntityFactory
{
    Creature* CreateCreature();
    Creature* CreateCreature(CreatureType arg);
}
