#pragma once
#include "object_base.hpp"
#include "boost_fixedwidth.hpp"
#include "misc_vector2.hpp"
#include "libtcod.hpp"

class TObject
{
public:
    enumObjectType ObjectType;
    char DisplayChar;
    const TCODColor* DisplayColor;
};