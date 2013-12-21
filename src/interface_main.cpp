#include "interface_main.hpp"
#include "interface_mainmenu.hpp"
#include "interface_game.hpp"

namespace Interface
{
    void Initialize()
    {
        MainMenu::Initialize();
        Game::Initialize();
    }
}
