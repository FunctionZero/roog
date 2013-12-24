#include "game_class.hpp"

classGame::classGame()
{

}

classGame::~classGame()
{
    if(CurrentMap != nullptr)
        delete CurrentMap;
}
