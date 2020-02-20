// Copyright (C) 2020 | Vladimir Simonyan <simonyan.vlad@gmail.com>

// GAME.H
// Game class declaration
// The functions are described in GAME.CPP

#ifndef GAME_H
#define GAME_H

#include "Player.h"
#include "Bot.h"

class Game {
private:
	Player player;
    Player enemy;
    Bot bot;
    int trow;

public:
	void newGame();
    bool gameOver() const;
    void step();
    void print();
};

#endif

