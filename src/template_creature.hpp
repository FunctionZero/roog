#pragma once
#include "template_class.hpp"
#include "boost_fixedwidth.hpp"

enum class CreatureType
{
    Player,
    Rabbit
};

class TCreature : public TEntity
{
public:
    uint16_t HealthMax;
    uint16_t ManaMax;
};
