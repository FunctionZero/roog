#pragma once
#include <map>
#include "game_map.hpp"

namespace Worldgen
{
    void GenerateDebugForest(Map* argMap, std::map<MaptileType, TMaptile>* argTemp);
}
