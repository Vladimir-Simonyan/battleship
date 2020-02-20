// Copyright (C) 2020 | Vladimir Simonyan <simonyan.vlad@gmail.com>

#include <iostream>
#include "Game.h"

int main(int argc, char **argv)
{
	Game game;
	game.newGame();

	if(!game.gameOver())
	{
		//game.print();
		game.step();
	}

	std::cout << "Ok!\n";
	return 0;
}
