#include <iostream>
#include <thread>
#include <chrono>

#include "Initialisers.h"
#include "GameFunctions.h"

/*******************************************************************************************************
* SET CONSOLE - set console window size and title
*******************************************************************************************************/
void SetConsole()
{
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r); //stores the console's current dimensions

	//MoveWindow(window_handle, x, y, width, height, redraw_window);
	MoveWindow(console, r.left, r.top, 800, 600, TRUE);
	SetConsoleTitle(L"<## -- TEXT ADVENTURE --##>");
}
/*******************************************************************************************************
* START TEXT - set game intro screen
*******************************************************************************************************/
void StartText(Human & HumanObj)
{
	std::this_thread::sleep_for(std::chrono::seconds(3));
	std::cout << "\n\n";
	std::cout << "      -             > > >>           ***          << < <             -      \n";
	std::cout << "     -            > > >>           *******          << < <            -       \n";
	std::cout << "    -           > > >>          ***       ***          << < <          -        \n";
	std::cout << "   -           > > >>          ***  POP!!! ***          << < <          -        \n";
	std::cout << "    -           > > >>          ***       ***          << < <          -       \n";
	std::cout << "     -            > > >>           *******          << < <            -     \n";
	std::cout << "      -             > > >>           ***          << < <             -    \n";
	std::this_thread::sleep_for(std::chrono::seconds(3));
	std::cout << "\n\n                                                       hello...?\n";
	std::this_thread::sleep_for(std::chrono::seconds(2));
	std::cout << "\n             hello...???\n";
	std::this_thread::sleep_for(std::chrono::seconds(3));
	std::cout << "\n\n                                HELLOOOOOOooooo...?!!\n\n";
	std::this_thread::sleep_for(std::chrono::seconds(3));
	std::cout << "\n    OH! Hi there! Awefully dark in here yes?\n";
	std::this_thread::sleep_for(std::chrono::seconds(3));
	std::cout << "\n\n                Welcome, you must be " << HumanObj.GetName() << "?\n";
	Pause();
	std::cout << "\n    Well every one around here seems to be called " << HumanObj.GetName() << " these days...\n";
	std::this_thread::sleep_for(std::chrono::seconds(3));
	std::cout << "\n          Did you hear that almighty * POP! *? Was it you?\n";
	Pause();
	HumanStats(HumanObj);
	Pause();
}
/*******************************************************************************************************
* FINISH TEXT - set games final screen
*******************************************************************************************************/
void FinishText(Human & HumanObj)
{
	
	std::this_thread::sleep_for(std::chrono::seconds(1));
	std::cout << "         ...\n";
	std::this_thread::sleep_for(std::chrono::seconds(1));
	std::cout << "               ...\n";
	std::this_thread::sleep_for(std::chrono::seconds(1));
	std::cout << "                     ...\n";
	std::this_thread::sleep_for(std::chrono::seconds(2));
	std::cout << "                            THUMP..!!\n";
	std::cout << "                                       ... \n\n";
	std::this_thread::sleep_for(std::chrono::seconds(3));
	std::cout << "\n                                                       hello...?\n";
	std::this_thread::sleep_for(std::chrono::seconds(2));
	std::cout << "\n             hello...???\n";
	std::this_thread::sleep_for(std::chrono::seconds(3));
	std::cout << "\n\n                                HELLOOOOOOooooo...?!!\n\n";
	std::this_thread::sleep_for(std::chrono::seconds(3));
	std::cout << "\n    OH! Hi there! Awefully dark in here yes?\n";
	std::this_thread::sleep_for(std::chrono::seconds(3));
	std::cout << "\n\n                HA HA!! Just kidding!\n\n";
	std::this_thread::sleep_for(std::chrono::seconds(3));
	std::cout << "   Well this is awkward, much like that the spelling of that word...\n\n                                     orquard...\n";
	std::this_thread::sleep_for(std::chrono::seconds(3));
	std::cout << "\n         To be honest, as I like to be sometimes...some say blunt!?\n\n";
	std::this_thread::sleep_for(std::chrono::seconds(4));
	std::cout << "\n      I really didn't think you would get to the end!... \n";
	std::this_thread::sleep_for(std::chrono::seconds(4));
	std::cout << "\n   I must apologise as I have nothing prepared,";
	std::this_thread::sleep_for(std::chrono::seconds(1));
	std::cout << "\n                                               no prize,";
	std::this_thread::sleep_for(std::chrono::seconds(1));
	std::cout << "\n                                                         no cake, ";
	std::this_thread::sleep_for(std::chrono::seconds(1));
	std::cout << "\n                                                                  no fan fair...";
	std::this_thread::sleep_for(std::chrono::seconds(3));
	std::cout << "\n\n         Well I must say...Good Job!!? \n ";
	std::this_thread::sleep_for(std::chrono::seconds(3));
	std::cout << "\n Now please take your self satifaction elsewhere or try again;) \n";
	std::this_thread::sleep_for(std::chrono::seconds(3));
	Pause();
	HumanStats(HumanObj);
	Pause();
	std::cout << "\n          Yup...thats it, no more...bye now...\n";
}
/*******************************************************************************************************
* INIT LOCATIONS - initialise the worlds locations
*******************************************************************************************************/
void InitLocations(Location *locations[])
{
	
	//Location variables
	// ajacent locations vector key = { N, S , E, W }
	// challenges exit allocation = { N, S , E, W }
	// Start location - locations[0] connections to locations [0,2,3,1]
	char *startName = "Start Location";
	char *startDescription = "\n>  You have materialised in a maze of three twisty little passages...\n   And they all look the same!!! \n>  Choose one to begin your escape...\n ";
	std::vector<int> startAdjLoc = { 0,2,3,1 };
	// General Location 1 - locations[1] connects to locations[0,4,2,7]
	char *loc1Name = "Location 1";
	char *loc1Description = "> Welcome to the area labeled Location 1 \n  You see three twisty little passages that all look the same! \n  Choose one to continue your escape...\n ";
	std::vector<int> loc1AdjLoc = { 0,4,2,7 };
	// General Location 2 - locations[2] connects to locations[0,5,3,1]
	char *loc2Name = "Location 2";
	char *loc2Description = "> Welcome to the area labeled Location 2 \n  You see three twisty little passages that all look the same! \n  Choose one to continue your escape...\n ";
	std::vector<int> loc2AdjLoc = { 0,5,3,1 };
	// General Location 3 - locations[3] connects to locations[0,6,9,2]
	char *loc3Name = "Location 3";
	char *loc3Description = "> Welcome to the area labeled Location 3 \n  You see three twisty little passages that all look the same! \n  Choose one to continue your escape...\n ";
	std::vector<int> loc3AdjLoc = { 0,6,9,2 };
	// General Location 4 - locations[4] connects to locations[1,9,5,7]
	char *loc4Name = "Location 4";
	char *loc4Description = "> Welcome to the area labeled Location 4 \n  You see three twisty little passages that all look the same! \n  Choose one to continue your escape...\n ";
	std::vector<int> loc4AdjLoc = { 1,9,5,7 };
	// General Location 5 - locations[5] connects to locations[2,8,6,4]
	char *loc5Name = "Location 5";
	char *loc5Description = "> Welcome to the area labeled Location 5 \n  You see three twisty little passages that all look the same! \n  Choose one to continue your escape...\n ";
	std::vector<int> loc5AdjLoc = { 2,8,6,4 };
	// General Location 6 - locations[6] connects to locations[3,9,7,5]
	char *loc6Name = "Location 6";
	char *loc6Description = "> Welcome to the area labeled Location 6 \n  You see three twisty little passages that all look the same! \n  Choose one to continue your escape...\n ";
	std::vector<int> loc6AdjLoc = { 3,9,7,5 };
	// General Location 7 - locations[7] connects to locations[4,10,3,8]
	char *loc7Name = "Location 7";
	char *loc7Description = "> Welcome to the area labeled Location 7 \n  You see three twisty little passages that all look the same! \n  Choose one to continue your escape...\n ";
	std::vector<int> loc7AdjLoc = { 4,10,3,8 };
	// General Location 8 - locations[8] connects to locations[5,10,9,7]
	char *loc8Name = "Location 8";
	char *loc8Description = "> Welcome to the area labeled Location 8 \n  You see three twisty little passages that all look the same! \n  Choose one to continue your escape...\n ";
	std::vector<int> loc8AdjLoc = { 5,10,9,7 };
	// General Location 9 - locations[9] connects to locations[6,10,3,8]
	char *loc9Name = "Location 9";
	char *loc9Description = "> Welcome to the area labeled Location 9 \n  You see three twisty little passages that all look the same! \n  Choose one to continue your escape...\n ";
	std::vector<int> loc9AdjLoc = { 6,10,3,8 };
	// Finish location - locations[10] connections to locations [8,10,9,7]
	char *finishName = "Finish Location";
	char *finishDescription = "    ...\n";
	std::vector<int> finishAdjLoc = { 8,10,9,7 };

	locations[0] = new StartLocation(startName, startDescription, startAdjLoc);
	locations[1] = new GeneralLocation(loc1Name, loc1Description, loc1AdjLoc);
	locations[2] = new GeneralLocation(loc2Name, loc2Description, loc2AdjLoc);
	locations[3] = new GeneralLocation(loc3Name, loc3Description, loc3AdjLoc);
	locations[4] = new GeneralLocation(loc4Name, loc4Description, loc4AdjLoc);
	locations[5] = new GeneralLocation(loc5Name, loc5Description, loc5AdjLoc);
	locations[6] = new GeneralLocation(loc6Name, loc6Description, loc6AdjLoc);
	locations[7] = new GeneralLocation(loc7Name, loc7Description, loc7AdjLoc);
	locations[8] = new GeneralLocation(loc8Name, loc8Description, loc8AdjLoc);
	locations[9] = new GeneralLocation(loc9Name, loc9Description, loc9AdjLoc);
	locations[10] = new FinishLocation(finishName, finishDescription, finishAdjLoc);
}
/*******************************************************************************************************
* INIT CHALLENGES - initialise game challenges
*******************************************************************************************************/
void InitChallenges(Challenge *challenge[])
{
	int difficulty = 2;

	challenge[0] = new Challenge(">> There is no challenge here! \n The path is clear... \n", 0);
	challenge[1] = new FleeChallenge(">> Can you avoid the banana peals?", difficulty);
	challenge[2] = new FleeChallenge(">> Can you jump the forgotten long drop of stinkiness?", difficulty);
	challenge[3] = new FleeChallenge(">> Can you swim the lake of despair?", difficulty);
	challenge[4] = new FleeChallenge(">> Can you navigate the icey pond of peas?", difficulty);
	challenge[5] = new FleeChallenge(">> Can you climb the waterfall of molten chocolate?", difficulty);
	challenge[6] = new Question("?> What day is Wednesday? \n   a) the third day \n   b) hump day \n   c) the day after Tuesday", "the day after Tuesday", difficulty);
	challenge[7] = new Question("?> One, two or three? \n   a) one \n   b) two \n   c) three", "three", difficulty);
	challenge[8] = new Question("?> North, south, east or west? \n   a) north \n   b) south \n   c) east \n   d) west", "east", difficulty);
	challenge[9] = new Question("?> Up, down, left or right? \n   a) up \n   b) down \n   c) left \n   d) right", "left", difficulty);
	challenge[10] = new Question("?> Black, white or gray? \n   a) black \n   b) white \n   c) gray", "gray", difficulty);
	challenge[11] = new PhysicalChallenge(">> To proceed in this direction you must challenge Bill the Badger?", difficulty);
	challenge[12] = new PhysicalChallenge(">> To proceed in this direction you must challenge Richard the Rooster?", difficulty);
	challenge[13] = new PhysicalChallenge(">> To proceed in this direction you must challenge Michelle the Mouse?", difficulty);
	challenge[14] = new PhysicalChallenge(">> To proceed in this direction you must challenge Susan the Lazy?", difficulty);
	challenge[15] = new PhysicalChallenge(">> To proceed in this direction you must challenge Justin the Yellow?", difficulty);

}
/*******************************************************************************************************
*    INIT ENEMIES - initialise enemies
*******************************************************************************************************/
void InitEnemies(Enemy * Enemies[], const int enemyNum)
{
	int enemyLoc = 0;
	int strength = 0;
	int health = 0;
	int luck = 0;
	const int nameNum = 5;
	
	const char *Names[nameNum] = { "Bill the Badger", "Richard the Rooster", "Michelle the Mouse", "Susan the Lazy", "Justin the Yellow" };

	for (int i = 0; i < enemyNum; i++)
	{
		int strength = std::rand() % 5 + 5;
		int health = std::rand() % 20 + 80;
		int luck = std::rand() % 5 + 5;
		Enemies[i] = new Enemy(enemyLoc, Names[i], strength, health, luck);
	}
}
/*******************************************************************************************************
* ADD ENEMY TO CHALLENGE - assign an enemy to each challenge
*******************************************************************************************************/
void AddEnemyToChallenge(Challenge * Challenges[], int enemyNum, int challNum)
{
	int c = 0;
	int diff = challNum - enemyNum;
	for (int i = 0; i < enemyNum; i++)
	{
		c = 0;
		c = i + diff;
		Challenges[c]->SetEnemy(i);
	}
}
/*******************************************************************************************************
* INIT HUMAN - originally created to allow user to setup there character
*******************************************************************************************************/
void InitHuman(Human human)
{
	//std::cout << "Please setup your character" << std::endl;
}
/*******************************************************************************************************
*  DESTROY LOCATIONS - delete locations
*******************************************************************************************************/
void DestroyLocations(Location *locations[], int length)
{
	for (int i = 0; i < length; i++)
	{
		delete locations[i];
	}
}
/*******************************************************************************************************
*  DESTROY CHALLENGES - delete challenges
*******************************************************************************************************/
void DestroyChallenges(Challenge *challenge[], int length)
{
	for (int i = 0; i < length; i++)
	{
		delete challenge[i];
	}
}
/*******************************************************************************************************
*  DESTROY ENEMIES - delete enenmies
*******************************************************************************************************/
void DestroyEnemies(Enemy *Enemies[], int length)
{
	for (int i = 0; i < length; i++)
	{
		delete Enemies[i];
	}
}

