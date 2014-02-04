#include "template_factory.hpp"
#include "libtcod.hpp"

namespace TemplateFactory
{
    void MakeDebugTMaptileList(std::map<MaptileType, TMaptile>* arg)
    {
        std::pair<std::map<MaptileType, TMaptile>::iterator, bool> it;

        it = arg->emplace(MaptileType::Ground, TMaptile());
        it.first->second.DisplayChar = '.';
        it.first->second.DisplayFColor = &TCODColor::sepia;
        it.first->second.isPassable = true;
        it.first->second.isTransparent = true;

        it = arg->emplace(MaptileType::Tree, TMaptile());
        it.first->second.DisplayChar = 'T';
        it.first->second.DisplayFColor = &TCODColor::green;
        it.first->second.isPassable = false;
        it.first->second.isTransparent = false;

        it = arg->emplace(MaptileType::Rock, TMaptile());
        it.first->second.DisplayChar = 'o';
        it.first->second.DisplayFColor = &TCODColor::grey;
        it.first->second.isPassable = false;
        it.first->second.isTransparent = true;
    }

    void MakeDebugTCreatureList(std::map<CreatureType, TCreature>* arg)
    {
        std::pair<std::map<CreatureType, TCreature>::iterator, bool> it;

        it = arg->emplace(CreatureType::Player, TCreature());
        it.first->second.DisplayChar = '@';
        it.first->second.DisplayFColor = &TCODColor::red;
        it.first->second.HealthMax = 10;
        it.first->second.ManaMax = 10;

        it = arg->emplace(CreatureType::Rabbit, TCreature());
        it.first->second.DisplayChar = 'r';
        it.first->second.DisplayFColor = &TCODColor::white;
        it.first->second.HealthMax = 1;
        it.first->second.ManaMax = 0;
    }
}
