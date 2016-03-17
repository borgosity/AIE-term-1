#include <iostream>
#include <string>   
#include <conio.h>
#include <time.h>



static const int NUM_ENEMIES = 5;
static const float WORLD_SIZE = 1000.0f;

// Forward declarations
struct Position;
class Enemy;

// Function prototypes
float distanceToPlayer(const Position & position);
float randomFloat(float upperLimit);

Enemy *g_enemies[NUM_ENEMIES];



// A single position in the world. Note that a Position will automatically
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



// 'Enemy' is the base class for all enemies in the game.
// It is an abstract base class (i.e. pure virtual) that cannot
// be instantiated by itself.
class Enemy
{
public:
    Enemy()
    {
        init();
    }

    Enemy(const Position & position)
    {
        init();

        m_position = position;
    }
        
    virtual ~Enemy()
    {

    }

    virtual void onMove() = 0;

    virtual bool onAttack(std::string & killReason)
    {
        killReason = "";
        m_distanceToPlayer = distanceToPlayer(m_position);
        return true;
    }

private:
    Position m_position;
    float m_health;
    float m_speed;
    float m_distanceToPlayer;

    void init()
    {
        m_health = 0;
        m_speed = 0;
    }
};

// 'EnemyArcher' is a specialisation of 'Enemy' 
class EnemyArcher : public Enemy
{
public:
    EnemyArcher(const Position & position) : Enemy(position)
    {
    }

private:

    virtual void onMove()
    {
        // Archer-specific code goes here
        // ...
    }

    virtual bool onAttack(std::string & killReason)
    {
        Enemy::onAttack(killReason);

        // Archer-specific code goes here
        // ...
        if (randomFloat(100) < 8.0f)
        {
            killReason = "Hit between the eyes by an arrow.";
            return false;
        }

        return true;
    }
};

// 'KillerBee' is a specialisation of 'Enemy' 
class KillerBee : public Enemy
{
public:
    KillerBee(const Position & position) : Enemy(position)
    {
    }

private:

    virtual void onMove()
    {
        // Archer-specific code goes here
        // ...
    }

    virtual bool onAttack(std::string & killReason)
    {
        Enemy::onAttack(killReason);

        // Archer-specific code goes here
        // ...
        if (randomFloat(100) < 10.0f)
        {
            killReason = "Stung on the lip, got a swollen mouth, couldn't eat, finally died of starvation";
            return false;
        }

        return true;
    }
};

// 'Tiger' is a specialisation of 'Enemy' 
class Tiger : public Enemy
{
public:
    Tiger(const Position & position) : Enemy(position)
    {
    }

private:

    virtual void onMove()
    {
        // Archer-specific code goes here
        // ...
    }

    virtual bool onAttack(std::string & killReason)
    {
        Enemy::onAttack(killReason);

        // Archer-specific code goes here
        // ...
        if (randomFloat(100) < 10.0f)
        {
            killReason = "Eaten by a stripey cat.";
            return false;
        }

        return true;
    }
};

// 'PoisonousSlug' is a specialisation of 'Enemy' 
class PoisonousSlug : public Enemy
{
public:
    PoisonousSlug(const Position & position) : Enemy(position)
    {
    }

private:

    virtual void onMove()
    {
        // Archer-specific code goes here
        // ...
    }

    virtual bool onAttack(std::string & killReason)
    {
        Enemy::onAttack(killReason);

        // Archer-specific code goes here
        // ...
        if (randomFloat(100) < 2.0f)
        {
            killReason = "Painfully poisoned.";
            return false;
        }

        return true;
    }
};



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
Program entry point
*******************************************************************************/
void main()
{
    std::cout << "Press any key to run the game...";

    srand((unsigned int)time(0));

    _getch();

    system("cls");
    std::cout << "Running...\n\n";

    g_enemies[0] = new EnemyArcher(Position(    randomFloat(WORLD_SIZE), randomFloat(WORLD_SIZE), 0));
    g_enemies[1] = new EnemyArcher(Position(    randomFloat(WORLD_SIZE), randomFloat(WORLD_SIZE), 0));
    g_enemies[2] = new KillerBee(Position(      randomFloat(WORLD_SIZE), randomFloat(WORLD_SIZE), 0));
    g_enemies[3] = new Tiger(Position(          randomFloat(WORLD_SIZE), randomFloat(WORLD_SIZE), 0));
    g_enemies[4] = new PoisonousSlug(Position(  randomFloat(WORLD_SIZE), randomFloat(WORLD_SIZE), 0));

    int moveCount = 1;
    bool playerIsAlive = true;
    while (playerIsAlive)
    {
        std::cout << "Move " << moveCount++ << "\n";

        std::string killReason;
        for (size_t i = 0; i < NUM_ENEMIES; i++)
        {
            g_enemies[i]->onMove();

            playerIsAlive = g_enemies[i]->onAttack(killReason);
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