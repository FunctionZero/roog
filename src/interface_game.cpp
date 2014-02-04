#include "libtcod_input.hpp"
#include "libtcod_display.hpp"
#include "interface_game.hpp"
#include "interface_mainmenu.hpp"
#include "handler_player.hpp"
#include "system_global.hpp"
#include "game_main.hpp"

namespace Game
{
    uint8_t viewportPosX = 1;
    uint8_t viewportPosY = 1;
    uint8_t viewportSizeX = 35;
    uint8_t viewportSizeY = 35;

    void Initialize()
    {
        if(viewportSizeX % 2 == 0)
            viewportSizeX++;
        if(viewportSizeY % 2 == 0)
            viewportSizeY++;
    }

    void Open()
    {
        Global::ChangeGamestate(STATE_GAME);
    }

    void Loop()
    {
        Input();

        Display();
    }

    void Input()
    {
        if(LibTCOD::ev == TCOD_EVENT_KEY_PRESS)
        {
            switch(LibTCOD::key.vk)
            {
            case TCODK_ESCAPE:
                MainMenu::Open();
                break;

            case TCODK_KP5:
                Player::Wait();
                break;

            case TCODK_KP1:
                Player::MoveSW();
                break;

            case TCODK_KP2:
                Player::MoveS();
                break;

            case TCODK_KP3:
                Player::MoveSE();
                break;

            case TCODK_KP4:
                Player::MoveW();
                break;

            case TCODK_KP6:
                Player::MoveE();
                break;

            case TCODK_KP7:
                Player::MoveNW();
                break;

            case TCODK_KP8:
                Player::MoveN();
                break;

            case TCODK_KP9:
                Player::MoveNE();
                break;

            default:
                break;
            }
        }
    }

    void Display()
    {
        Vector2 viewpointPos = Player::Player->GetPosition();
        TCODConsole::root->print(1, 0, "Press ESC to return to main menu.");

        Entity* pointer = nullptr;
        uint16_t localX, localY;

        for(int y = 0; y < viewportSizeY; y++)
        {
            for(int x = 0; x < viewportSizeX; x++)
            {
                localX = viewpointPos.x - viewportSizeX / 2 + x;
                localY = viewpointPos.y - viewportSizeY / 2 + y;

                if(Game::Game->currentMap->IsInBounds(localX, localY) && Game::Game->currentMap->MapFOV->isInFov(localX, localY))
                {
                    pointer = Game::Game->currentMap->GetTileAt(localX, localY);
                    if(!pointer->Child.empty())
                        pointer = pointer->Child.back();

                    TCODConsole::root->putCharEx(viewportPosX + x, viewportPosY + y, pointer->DisplayChar, *pointer->DisplayFColor, *pointer->DisplayBColor);
                }
            }
        }
    }
}
