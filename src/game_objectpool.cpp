#include "game_objectpool.hpp"


Object* ObjectPool::NewObject(enumObjectType objType)
{
    switch(objType)
    {
    case OBJECT_OBJECT:
        //EXCEPTION
        break;
    case OBJECT_CREATURE:
        CreatureList.emplace_back();
        return &CreatureList.back();
        break;
    }
}

Object* ObjectPool::NewObject(TObject* objTemplate)
{

}
