#pragma once
#include <map>
#include "template_maptile.hpp"
#include "template_creature.hpp"
#include "boost_fixedwidth.hpp"

namespace TemplateFactory
{
    void MakeDebugTMaptileList(std::map<MaptileType, TMaptile>* arg);
    void MakeDebugTCreatureList(std::map<CreatureType, TCreature>* arg);
}
