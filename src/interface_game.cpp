#include "libtcod_input.hpp"
#include "libtcod_display.hpp"
#include "interface_game.hpp"
#include "interface_mainmenu.hpp"
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

            case TCODK_KP8:
                Game->PlayerObject->MoveBy(0, -1);
                break;

            case TCODK_KP9:
                Game->PlayerObject->MoveBy(1, -1);
                break;

            case TCODK_KP6:
                Game->PlayerObject->MoveBy(1, 0);
                break;

            case TCODK_KP3:
                Game->PlayerObject->MoveBy(1, 1);
                break;

            case TCODK_KP2:
                Game->PlayerObject->MoveBy(0, 1);
                break;

            case TCODK_KP1:
                Game->PlayerObject->MoveBy(-1, 1);
                break;

            case TCODK_KP4:
                Game->PlayerObject->MoveBy(-1, 0);
                break;

            case TCODK_KP7:
                Game->PlayerObject->MoveBy(-1, -1);
                break;

            default:
                break;
            }
        }
    }

    void Display()
    {
        Vector2 origin = Game::Game->PlayerObject->GetPosition();
        Object* CurrentObj = nullptr;
        int tempX, tempY;

        for(int y = 0; y < viewportSizeY; y++)
        {
            for(int x = 0; x < viewportSizeX; x++)
            {
                tempX = origin.x - viewportSizeX / 2 + x;
                tempY = origin.y - viewportSizeY / 2 + y;

                if(Game::Game->CurrentMap->IsPositionLegal(tempX, tempY) && Game::Game->CurrentMap->MapFOV->isInFov(tempX, tempY))
                {
                    CurrentObj = Game::Game->CurrentMap->GetTileAt(tempX, tempY);
                    if(!CurrentObj->Child.empty())
                        CurrentObj = CurrentObj->Child.back();

                    TCODConsole::root->putCharEx(viewportPosX + x, viewportPosY + y, CurrentObj->DisplayChar, *CurrentObj->DisplayColor, TCODColor::black);
                }
            }
        }

        TCODConsole::root->print(1, 0, "Press ESC to return to main menu.");
    }
}
