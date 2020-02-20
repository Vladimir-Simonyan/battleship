// Copyright (C) 2020 | Vladimir Simonyan <simonyan.vlad@gmail.com>

// BOARD.CPP
// Board class description

#include "Board.h"

void Board::getBoard(int arr[10][10]) const
{
    for(int i = 0; i < 10; ++i)
    {
        for(int j = 0; j < 10; ++j)
        {
            arr[i][j] = board[i + 1][j + 1];
        }
    }
}