#pragma once
#include <list>
#include "template_base.hpp"
#include "template_maptile.hpp"
#include "template_creature.hpp"

namespace TemplatePool
{
    extern std::list<TObject*> TemplateList;
    extern TObject* DefaultCreature;
    extern TObject* Player;

    void Initialize();
}
