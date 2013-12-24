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

        TemplateList.push_back(new TCreature());
        Player = TemplateList.back();
    }
}
