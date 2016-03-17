#include <iostream>
#include <string>   
#include <conio.h>
#include <time.h>

// General types and function
#include "Types.h"
#include "Functions.h"

// Enemy classes
#include "EnemyArcher.h"
#include "KillerBee.h"
#include "Tiger.h"
#include "PoisonousSlug.h"



/******************************************************************************
Program entry point
*******************************************************************************/
void main()
{
    std::cout << "Press any key to run the game...";

    srand((unsigned int)time(0));

    _getch();

    system("cls");
    std::cout << "Running...\n\n";

    Enemy *enemies[NUM_ENEMIES];

    enemies[0] = new EnemyArcher(Position(randomFloat(WORLD_SIZE), randomFloat(WORLD_SIZE), 0));
    enemies[1] = new EnemyArcher(Position(randomFloat(WORLD_SIZE), randomFloat(WORLD_SIZE), 0));
    enemies[2] = new KillerBee(Position(randomFloat(WORLD_SIZE), randomFloat(WORLD_SIZE), 0));
    enemies[3] = new Tiger(Position(randomFloat(WORLD_SIZE), randomFloat(WORLD_SIZE), 0));
    enemies[4] = new PoisonousSlug(Position(randomFloat(WORLD_SIZE), randomFloat(WORLD_SIZE), 0));

    int moveCount = 1;
    bool playerIsAlive = true;
    while (playerIsAlive)
    {
        std::cout << "Move " << moveCount++ << "\n";

        std::string killReason;
        for (size_t i = 0; i < NUM_ENEMIES; i++)
        {
            enemies[i]->onMove();

            playerIsAlive = enemies[i]->onAttack(killReason);
            if (!playerIsAlive)
            {
                std::cout << "You died -- " << killReason;
                break;
            }
        }
    }

    std::cout << "\n\n";
    //    system("pause");
}