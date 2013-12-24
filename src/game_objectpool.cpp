#include "game_objectpool.hpp"
#include "game_templatepool.hpp"

Object* ObjectPool::NewObject(enumObjectType objType)
{
    switch(objType)
    {
    case OBJECT_OBJECT:
        //EXCEPTION
        return nullptr;

    case OBJECT_MAPTILE:
        //EXCEPTION
        return nullptr;

    case OBJECT_CREATURE:
        return NewObject(TemplatePool::DefaultCreature);

    default:
        return nullptr;
    }
}

Object* ObjectPool::NewObject(TObject* objTemplate)
{
    switch(objTemplate->ObjectType)
    {
    case OBJECT_OBJECT:
        ObjectList.push_back(new Object());
        break;

    case OBJECT_MAPTILE:
        ObjectList.push_back(new MapTile());
        break;

    case OBJECT_CREATURE:
        ObjectList.push_back(new Creature());
        break;

    default:
        //EXCEPTION
        return nullptr;
    }

    ObjectList.back()->ChangeToTemplate(objTemplate);
    return ObjectList.back();
}
