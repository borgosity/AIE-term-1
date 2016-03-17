#include <iostream>
#include <string>   
#include <conio.h>
#include <time.h>



// A single position in the world. NOte that a Position will automatically
// initialize to (0,0,0)
struct Position
{
    float x;
    float y;
    float z;

    Position()
    {
        x = y = z = 0;
    }

    Position(float x_, float y_, float z_)
    {
        x = x_;
        y = y_;
        z = z_;
    }
};

enum EnemyTypes  
{
    Enemy_Archer,
    Enemy_Tiger,
    Enemy_KillerBee,
    Enemy_PoisonousSlug,
};

struct Enemy
{
    EnemyTypes enemyType;
    Position position;     // Position in the world
    float health;
    float speed;           // How fast the enemy travels per move
};

static const int NUM_ENEMIES = 6;
static const float WORLD_SIZE = 1000.0f;

Enemy g_enemies[NUM_ENEMIES];



/******************************************************************************
Computes the distance to a specified Position in the world. This assumes that
the distance is to be measured from the origin, which is where the player is
located (the player can't move in this very simple game).
*******************************************************************************/
float distanceToPlayer(const Position & position)
{
    return sqrt(position.x * position.x + position.y * position.y + position.z * position.z);
}

/******************************************************************************
Returns a random float that lies in the range 0 to upperLimit
*******************************************************************************/
float randomFloat(float upperLimit)
{
    return (float)rand() / (float)RAND_MAX * upperLimit;
}

/******************************************************************************
Initialize all enemies according to each of their individual characteristics
*******************************************************************************/
void initEnemies()
{
    g_enemies[0].enemyType = Enemy_Archer;
    g_enemies[1].enemyType = Enemy_Archer;
    g_enemies[2].enemyType = Enemy_Tiger;
    g_enemies[3].enemyType = Enemy_KillerBee;
    g_enemies[4].enemyType = Enemy_KillerBee;
    g_enemies[5].enemyType = Enemy_PoisonousSlug;

    for (size_t i = 0; i < NUM_ENEMIES; i++)
    {
        // Place the enemy at a random position in the world
        g_enemies[i].position.x = randomFloat(WORLD_SIZE);
        g_enemies[i].position.y = randomFloat(WORLD_SIZE);

        // Here is a more compact way to to the same thing using one of the Position constructors
        g_enemies[i].position = Position(randomFloat(WORLD_SIZE), randomFloat(WORLD_SIZE), 0);

        g_enemies[i].health = 100;

        switch (g_enemies[i].enemyType)
        {
        case Enemy_Archer:
            g_enemies[i].position.z = 0; // On the ground
            g_enemies[i].speed = 20;
            break;

        case Enemy_Tiger:
            g_enemies[i].position.z = 0; // On the ground
            g_enemies[i].speed = 5;
            break;

        case Enemy_KillerBee:
            g_enemies[i].position.z = randomFloat(100); // Up to 100 units in the air
            g_enemies[i].speed = 10;
            break;

        case Enemy_PoisonousSlug:
            g_enemies[i].position.z = 0; // On the ground
            g_enemies[i].speed = 1;
            break;
        }
    }
}

/******************************************************************************
Update the positions of all enemies in the game according to their individual
movement behaviours.
*******************************************************************************/
void moveEnemies()
{
    for (size_t i = 0; i < NUM_ENEMIES; i++)
    {
        // Move the enemey base on speed, health and a different algorithm 
        // for each type of enemy (e.g. killer bees fly, but graound-based
        // enemies move along the ground).
        switch (g_enemies[i].enemyType)
        {
        case Enemy_Archer:
            break;

        case Enemy_Tiger:
            break;

        case Enemy_KillerBee:
            break;

        case Enemy_PoisonousSlug:
            break;
        }
    }
}

/******************************************************************************
Resolve all attack for all enemies according to their individual capabilities 
and powers. Returns if the player is still alive after the attack, or false if 
the player has been killed by an enemy.
*******************************************************************************/
bool doEnemyAttacks(std::string & killReason)
{
    for (size_t i = 0; i < NUM_ENEMIES; i++)
    {
        // Compute the distance that the enemy is from the player
        float distance = distanceToPlayer(g_enemies[i].position);

        // Now compute the probability that the enemy can kill the player
        // based on the distance and enemy's capabilities.
        switch (g_enemies[i].enemyType)
        {
        case Enemy_Archer:
            if (rand() % 10 == 0)
            {
                killReason = "Hit between the eyes by an arrow.";
                return false;
            }
            break;

        case Enemy_Tiger:
            if (rand() % 10 == 0)
            {
                killReason = "Eaten by a stripey cat.";
                return false;
            }
            break;

        case Enemy_KillerBee:
            if (rand() % 10 == 0)
            {
                killReason = "Stung on the lip, got a swollen mouth, couldn't eat, finally died of starvation";
                return false;
            }
            break;

        case Enemy_PoisonousSlug:
            if (rand() % 10 == 0)
            {
                killReason = "Painfully poisoned.";
                return false;
            }
            break;
        }
    }

    return true;
}



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

    initEnemies();

    int moveCount = 1;
    while (true)
    {
        std::cout << "Move " << moveCount++ << "\n";
        moveEnemies();

        std::string killReason;
        bool playerIsAlive = doEnemyAttacks(killReason);

        if (!playerIsAlive)
        {
            std::cout << "You died -- " << killReason;
            break;
        }
    }
	system("pause");
    std::cout << "\n\n";
//    system("pause");
}