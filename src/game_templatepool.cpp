#include "game_templatepool.hpp"

namespace TemplatePool
{
    std::list<TObject*> TemplateList;
    TObject* DefaultCreature;
    TObject* Player;

    void Initialize()
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
}
