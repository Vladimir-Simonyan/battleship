// Copyright (C) 2020 | Vladimir Simonyan <simonyan.vlad@gmail.com>

// BOARD.H
// Board class declaration
// The functions are described in BOARD.CPP

#ifndef BOARD_H
#define BOARD_H

class Board {
private:

public:
	int board[12][12] = { 0 };
    void getBoard(int arr[10][10]) const;
};

#endif

