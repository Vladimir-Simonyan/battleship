// Copyright (C) 2020 | Vladimir Simonyan <simonyan.vlad@gmail.com>

// GAME.CPP
// Game class description

#include "Game.h"
#include <iostream>

void Game::newGame()
{
    trow = 0;
    player.autoInitPlayer();
    enemy.autoInitPlayer();
}

bool Game::gameOver() const
{
    if(player.getHP() * enemy.getHP() == 0) 
    {
        return true;
    }
    return false;
}

void Game::step()
{
    //print();
    int x, y;
    if(trow == 0)
    {
        std::system ("clear");
        print();

        int x, y;
        std::cout << "Your turn!\n" << "Enter point coordinates  (x[1-10] y[1-10]):  ";
        std::cin >> x >> y;
        
        std::cout << "\n\n\n";
        if(enemy.getHit(x, y))
        {
            std::cout << "You hit!\n\n";
            if(!gameOver()) step();
            else std::cout << "GameOver!\n";
        }
        else
        {
            std::cout << "You missed!\n\n";
            trow = 1;
            step();
        }
    }
    else // trow == 1
    {
        int x, y;
        x = (random() % 10) + 1;
        y = (random() % 10) + 1;

        std::system ("clear");
        std::cout << "Enemy step: X " << x << " Y " << y << "\n";

        if(player.getHit(x, y))
        {
            std::cout << "Enemy hit!\n\n";
            if(!gameOver()) step();
            else std::cout << "GameOver!\n";
        }
        else
        {
            std::cout << "Enemy missed!\n\n";
            trow = 0;
            step();
        }
    }
}

void Game::print()
{
    std::cout << "\n\n";

    std::cout << "\t";
    std::cout << "   ";
    char cr = '1'; // A
    for(int i = 0; i < 10; ++i)
    {
        std::cout << cr++ << " ";
    }

    std::cout << "\t\t";

    std::cout << "\t";
    std::cout << "   ";
    cr = '1'; // A
    for(int i = 0; i < 10; ++i)
    {
        std::cout << cr++ << " ";
    }

    std::cout << "\n";

    for(int i = 0; i < 10; ++i)
    {
        player.printLn(i);
        std::cout << "\t\t";
        enemy.printLnS(i); // printLnS S!
        std::cout << "\n";
    }

    std::cout << "\n\n";
}



        /*
        char inputText[512];
    L1:
        std::cout << "Your turn!\n" << "Enter point coordinates:  ";
        std::cin.getline(inputText, 512);
        
        if(int(inputText[3]) == 0)
        { 
            if(inputText[2] == '0')
            {
                if(inputText[1] == '1')
                {
                    x = 10;
                }

                if(inputText[0] >= 'a' && inputText[0] <= 'j')
                {
                    y = inputText[0] - 'a';
                    goto L2;
                }
            } 
            else if(int(inputText[2]) == 0)
            {
                if(inputText[2] >= '1' && inputText[2 <= '9'])
                {
                    x = inputText[2] - '1';
                }

                if(inputText[0] >= 'a' && inputText[0] <= 'j')
                {
                    y = inputText[0] - 'a';
                    goto L2;
                }
            }
        }

        std::cout << "Incorrect coordinates! \n" << "Enter point coordinates in the format [a-j][1-10]:  ";
        goto L1;
    L2:
        std::cout << x << " " << y << "\n";
        */
