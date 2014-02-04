#pragma once
#include "template_class.hpp"

enum class MaptileType
{
    Ground,
    Tree,
    Rock
};

class TMaptile : public TEntity
{
public:
    bool isPassable;
    bool isTransparent;
};
