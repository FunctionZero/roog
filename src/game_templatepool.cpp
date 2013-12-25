#include "game_templatepool.hpp"

TemplatePool::TemplatePool()
{
    TemplateList.push_back(new TCreature());
    DefaultCreature = TemplateList.back();

    DefaultCreature->DisplayChar = '?';
    DefaultCreature->DisplayColor = &TCODColor::pink;

    TemplateList.push_back(new TCreature());
    Player = TemplateList.back();

    Player->DisplayChar = '@';
    Player->DisplayColor = &TCODColor::red;
}

TemplatePool::~TemplatePool()
{
    for(auto& it: TemplateList)
    {
        delete it;
    }
}
