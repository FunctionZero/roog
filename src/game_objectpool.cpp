#include "game_objectpool.hpp"
#include "game_templatepool.hpp"
#include "game_main.hpp"
#include "system_exception.hpp"

ObjectPool::~ObjectPool()
{
    for(auto& it: ObjectList)
    {
        delete it;
    }
}

Object* ObjectPool::NewObject(Object* argParent, enumObjectType objType)
{
    switch(objType)
    {
    case OBJECT_OBJECT:
        System::Error("ObjectPool tried to create OBJECT_OBJECT.", 101);
        return nullptr;

    case OBJECT_MAPTILE:
        System::Error("ObjectPool tried to create OBJECT_MAPTILE.", 102);
        return nullptr;

    case OBJECT_CREATURE:
        return NewObject(argParent, Game::Game->Templates.DefaultCreature);

    default:
        System::Error("ObjectPool encountered unhandled ObjectType.", 111);
        return nullptr;
    }
}

Object* ObjectPool::NewObject(Object* argParent, TObject* objTemplate)
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
        System::Error("ObjectPool encountered unhandled ObjectType.", 111);
        return nullptr;
    }

    argParent->AddChild(ObjectList.back());
    ObjectList.back()->SetParent(argParent);
    ObjectList.back()->ChangeToTemplate(objTemplate);
    return ObjectList.back();
}
