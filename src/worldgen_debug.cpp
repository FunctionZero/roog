#include "worldgen_debug.hpp"
#include "entity_maptile.hpp"
#include "misc_random.hpp"

namespace Worldgen
{
    void GenerateDebugForest(Map* argMap, std::map<MaptileType, TMaptile>* argTemp)
    {
        Maptile* pointer;
        for(int y = 0; y < argMap->sizeY; y++)
        {
            for(int x = 0; x < argMap->sizeX; x++)
            {
                pointer = argMap->GetTileAt(x, y);
                if(RandomPercent(10))
                    pointer->UseTemplate(&argTemp->find(MaptileType::Tree)->second);
                else if(RandomPercent(3))
                    pointer->UseTemplate(&argTemp->find(MaptileType::Rock)->second);
                else
                    pointer->UseTemplate(&argTemp->find(MaptileType::Ground)->second);
            }
        }
    }
}
