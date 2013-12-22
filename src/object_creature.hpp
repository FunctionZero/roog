#pragma once
#include "object_base.hpp"

class Creature : public Object
{
public:
    Creature();
    void Copy(const Creature& obj);
};
