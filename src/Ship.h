// Copyright (C) 2020 | Vladimir Simonyan <simonyan.vlad@gmail.com>

// SHIP.H
// Ship class declaration
// The functions are described in SHIP.CPP

#ifndef SHIP_H
#define SHIP_H

class Ship {
private:
	int x;
	int y;
	int len;
	int orientation;
	int hp;

public:
	void setShip(int x, int y, int len, int orientation);
	int getHP() const;
	void minusHP();
};

#endif

