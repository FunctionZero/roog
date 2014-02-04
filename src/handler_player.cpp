#include "handler_player.hpp"
#include "game_map.hpp"

namespace Player
{
    Creature* Player;

    void MoveBy(int x, int y)
    {
        Vector2 pos = Player->GetPosition() + Vector2(x, y);
        if(Player->GetParentMap()->IsInBounds(pos))
            //if(Player->GetParentMap()->IsOccupied(pos))
                //Attack?
            if(Player->GetParentMap()->IsPassable(pos))
                Player->MoveTo(pos);
        Player->GetParentMap()->CalculateFOV(Player->GetPosition());
    }

    void Wait()   {}
    void MoveN()  {MoveBy( 0,-1);}
    void MoveNE() {MoveBy( 1,-1);}
    void MoveE()  {MoveBy( 1, 0);}
    void MoveSE() {MoveBy( 1, 1);}
    void MoveS()  {MoveBy( 0, 1);}
    void MoveSW() {MoveBy(-1, 1);}
    void MoveW()  {MoveBy(-1, 0);}
    void MoveNW() {MoveBy(-1,-1);}
}
