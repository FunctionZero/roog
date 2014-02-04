#pragma once
#include "libtcod.hpp"

class TEntity
{
public:
    char DisplayChar;
    const TCODColor* DisplayFColor;
    const TCODColor* DisplayBColor;

    TEntity(char DisplayChar = '?', const TCODColor* DisplayFColor = &TCODColor::white, const TCODColor* DisplayBColor = &TCODColor::black);
};
