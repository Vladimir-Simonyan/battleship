// Copyright (C) 2020 | Vladimir Simonyan <simonyan.vlad@gmail.com>

// PLAYER.H
// Player class declaration
// The functions are described in PLAYER.CPP

#ifndef PLAYER_H
#define PLAYER_H

#include "Ship.h"
#include "Board.h"

class Player {
private:
	Ship ships[10];
    Board board;

public:
	void autoInitPlayer();
    int getHP() const;
    void printLn(int ln);
    void printLnS(int ln);
    bool getHit(int x, int y);
};

#endif

