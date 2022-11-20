/*
COPYRIGHT (C) 2022 Sarah Hughes (4724822) All rights reserved.
Assignment 5-A
Author. Sarah Hughes
sch62@uakron.edu
Version. 1.01 10.16.2022
Purpose: This program will use a shoot function and a startGame function in order to 
simulate 1000 games of dodgeball where three players take turns shooting the best player alive,
and at the end, outputs the win percentages of each player after 1000 games. Each game is randomized using
time(NULL) as the srand seed.
*/

// imports
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <time.h>

// constants
const float AARON_ACCURACY = 1.0 / 3;
const float BOB_ACCURACY = 0.5;
const float CHARLIE_ACCURACY = 1.0;
const int GAMES = 1000;

// prototypes
void shoot(bool &targetAlive, float shooterAccuracy);
int startGame();

int main()
{
    // seed for rand() using computer clock
    srand(time(NULL));

    int aaronWins = 0, bobWins = 0, charlieWins = 0; // win counters
	for (int i = 0; i < GAMES; i++) // That's a lot of dodgeball games
    {
        switch(startGame()) // startGame returns 1, 2, or 3 depending on who wins, perfect for switch statement
        {
            case 1:
                aaronWins++;
                break;
            case 2:
                bobWins++;
                break;
            case 3:
                charlieWins++;
                break;
        }
    }
    std::cout<<"\nUsing the strategy of shooting at the best player alive:\n";
    std::cout<<"--------------------------------------------------------\n";
    std::cout<<"Aaron wins: "<<std::setprecision(2)<<std::fixed<<std::showpoint<<((aaronWins*100.0)/GAMES)<<"%"<<std::endl;
    std::cout<<"Bob wins: "<<std::setprecision(2)<<std::fixed<<std::showpoint<<((bobWins*100.0)/GAMES)<<"%"<<std::endl;
    std::cout<<"Charlie wins: "<<std::setprecision(2)<<std::fixed<<std::showpoint<<((charlieWins*100.0)/GAMES)<<"%"<<std::endl;
    
}

// shoot function
void shoot(bool &targetAlive, float shooterAccuracy)
{
    double randNum = ((rand() % 1000) + 1); // 1000 for accuracy 
    if(randNum <= (shooterAccuracy * 1000))
    {
        targetAlive = false;
    }
    else
    {
        targetAlive = true;
    }
}

// game function
int startGame()
{
    bool aaron(true), bob(true), charlie(true); // true for alive, false for... dead? That seems dramatic for dodgeball
    while((aaron + bob + charlie) > 1) // checks if at least 2 players are alive, if only 1, then he's the winner
    {
        if (aaron) 
        {
            if(charlie)
            {
                shoot(charlie, AARON_ACCURACY);
            }
            else
            {
                shoot(bob, AARON_ACCURACY);
            }
        }
        if(bob)
        {
            if(charlie)
            {
                shoot(charlie, BOB_ACCURACY);
            }
            else
            {
                shoot(aaron, BOB_ACCURACY);
            }
        }
        if(charlie)
        {
            if(bob)
            {
                shoot(bob, CHARLIE_ACCURACY);
            }
            else
            {
                shoot(aaron, CHARLIE_ACCURACY);
            }
        }
    }
    if(aaron)
    {
        return 1;
    }
    else if(bob)
    {
        return 2;
    }
    else
    {
        return 3;
    }
}