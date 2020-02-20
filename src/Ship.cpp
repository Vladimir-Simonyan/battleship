// Copyright (C) 2020 | Vladimir Simonyan <simonyan.vlad@gmail.com>

// SHIP.CPP
// Ship class description

#include "Ship.h"

void Ship::setShip(int i_x, int i_y, int i_len, int i_orientation)
{
    x = i_x;
    y = i_y;
    len = i_len;
    orientation = i_orientation;
    hp = i_len;
}

int Ship::getHP() const
{
    return hp;
}

void Ship::minusHP()
{
    hp--;
}