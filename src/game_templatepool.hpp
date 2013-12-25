#pragma once
#include <list>
#include "template_base.hpp"
#include "template_maptile.hpp"
#include "template_creature.hpp"

class TemplatePool
{
public:
    std::list<TObject*> TemplateList;
    TObject* DefaultCreature;
    TObject* Player;

    TemplatePool();
    ~TemplatePool();
};
