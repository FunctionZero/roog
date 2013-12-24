#include "interface_main.hpp"
#include "interface_mainmenu.hpp"
#include "interface_game.hpp"
#include "interface_options.hpp"

namespace Interface
{
    void Initialize()
    {
        MainMenu::Initialize();
        Game::Initialize();
        Options::Initialize();
    }
}
