// Copyright (C) 2020 | Vladimir Simonyan <simonyan.vlad@gmail.com>

// PLAYER.CPP
// Player class description

#include "Player.h"
#include <stdlib.h>
#include <time.h>
#include <iostream> //

void setRand()
{
    static int sr = 0;
    if(!sr)
    {
        srandom(time(NULL));
        sr++;
    }
}

void Player::autoInitPlayer()
{
    setRand();

    int k = 0, x, y, o, s;
    for(int i = 1; i <= 4; ++i)
    {
        for(int j = 5-i; j > 0; --j)
        {
            // radom gen
            do {
                // inf loop protection
                static int LN = 1;
                if(LN++ % 10000 == 0) 
                {
                    setRand();
                }                

                x = (random() % 10) + 1;
                y = (random() % 10) + 1;
                o = random() % 2; 
                
                // board checking
                s = 0;
                if(o) // 1
                {
                    if(i + x > 10) s++; // Out of range

                    for(int ii = -1; ii <= i; ++ii)
                    {
                        s += board.board[x + ii][y - 1] + board.board[x + ii][y] + board.board[x + ii][y + 1];
                    }
                } else { // 0
                    if(i + y > 10) s++; // Out of range

                    for(int ii = -1; ii <= i; ++ii)
                    {
                        s += board.board[x - 1][y + ii] + board.board[x][y + ii] + board.board[x + 1][y + ii];
                    }
                }
            } while(s != 0);
            
            ships[k++].setShip(x, y, i, o);

            // board update
            if(o)
            {
                for(int ii = 0; ii < i; ++ii)
                {
                    board.board[x + ii][y] = 100 + k;
                }
            } else {
                for(int ii = 0; ii < i; ++ii)
                {
                    board.board[x][y + ii] = 100 + k;
                }
            }
        }
    }

    /*/ print for testing 
    std::cout << "\t";
    std::cout << "   ";
    char cr = 'A';
    for(int i = 0; i < 10; ++i)
    {
        std::cout << cr++ << " ";
    }
    std::cout << "\n";

    for(int i = 0; i < 10; ++i)
    {
        std::cout << "\t";
        if(i != 9)
        {
            std::cout << " ";
        }
        std::cout << i + 1 << " ";
        for(int j = 0; j < 10; ++j)
        {
            if(board.board[i + 1][j + 1] > 10000) std::cout << "o ";
            else if(board.board[i + 1][j + 1] > 1000) std::cout << "x ";
            else if(board.board[i + 1][j + 1] != 0) std::cout << "# ";
            else std::cout << ". ";
        }
        std::cout << "\n";
    }
    std::cout << "\n";
    */
}

int Player::getHP() const
{
    int hp = 0;
    for(int i = 0; i < 10; ++i)
    {
        hp += ships[i].getHP();
    }
    return hp;
}

void Player::printLn(int ln)
{
    int i = ln;
    std::cout << "\t";
    if(i != 9)
    {
        std::cout << " ";
    }
    std::cout << i + 1 << " ";
    for(int j = 0; j < 10; ++j)
    {
        if(board.board[i + 1][j + 1] >= 10000) std::cout << "O ";
        else if(board.board[i + 1][j + 1] >= 1000) std::cout << "X ";
        else if(board.board[i + 1][j + 1] != 0) std::cout << "# ";
        else std::cout << ". ";
    }
}

void Player::printLnS(int ln)
{
    int i = ln;
    std::cout << "\t";
    if(i != 9)
    {
        std::cout << " ";
    }
    std::cout << i + 1 << " ";
    for(int j = 0; j < 10; ++j)
    {
        if(board.board[i + 1][j + 1] >= 10000) std::cout << "O ";
        else if(board.board[i + 1][j + 1] >= 1000) std::cout << "X ";
        else if(board.board[i + 1][j + 1] != 0) std::cout << ". ";
        else std::cout << ". ";
    }
}

bool Player::getHit(int x, int y)
{
    if(board.board[x][y] == 0)
    {
        board.board[x][y] += 10000;
        return false;
    }
    else 
    {
        board.board[x][y] += 1000;
        ships[board.board[x][y] % 100].minusHP();
        return true;
    }
}