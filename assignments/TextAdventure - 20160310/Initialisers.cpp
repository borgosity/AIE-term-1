#include <iostream>
#include "Initialisers.h"
#include "GameFunctions.h"

/*******************************************************************************************************
*
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
*
*******************************************************************************************************/
void StartText(Human & HumanObj)
{
	std::cout << "*-----------------------------------------------------------------------------*\n";
	std::cout << "|               >>>>          ***  POP! ***          <<<<                     |\n";
	std::cout << "*-----------------------------------------------------------------------------*\n";
	std::cout << "    Welcome, your name is " << HumanObj.GetName() << ".\n";
	std::cout << "    You heard an almighty *POP!* and you know not from where you came...\n";
	HumanStats(HumanObj);
}
/*******************************************************************************************************
*
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
	char *finishDescription = "    ??? OH!! ??? \n\n> Well this is a suprise, I really didn't think you would get to the end :S \n> My apologies as I have nothing prepared, no prize, no cake, no fan fair... \n> Well...Good Job!!? \n> Please take your self satifaction elsewhere or try again ;)";
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
*
*******************************************************************************************************/
void InitChallenges(Challenge *challenge[])
{
	StringOO challenge0 = ">> There is no challenge here! \n The path is clear... \n";
	// Flee Challenges
	StringOO challenge1 = ">> Can you avoid the banana peals?";
	StringOO challenge2 = ">> Can you jump the forgotten long drop of stinkiness?";
	StringOO challenge3 = ">> Can you swim the lake of despair?";
	StringOO challenge4 = ">> Can you navigate the icey pond of peas?";
	StringOO challenge5 = ">> Can you climb the waterfall of molten chocolate?";
	// Mental Challenges
	StringOO Question1 = "?> What day is Wednesday? \n  a) the third day \n  b) hump day \n  c) the day after Tuesday";
	StringOO Question2 = "?> One, two or three? \n  a) one \n  b) two \n  c) three";
	StringOO Question3 = "?> North, south, east or west? \n  a) north \n  b) south \n  c) east \n  d) west";
	StringOO Question4 = "?> Up, down, left or right? \n  a) up \n  b) down \n  c) left \n  d) right";
	StringOO Question5 = "?> Black, white or gray? \n  a) black \n  b) white \n  c) gray";
	StringOO Answer1 = "the day after Tuesday";
	StringOO Answer2 = "three";
	StringOO Answer3 = "east";
	StringOO Answer4 = "left";
	StringOO Answer5 = "gray";
	// Physical Challenges
	StringOO challenge11 = ">> To proceed in this direction you must challenge Bill the Badger?";
	StringOO challenge12 = ">> To proceed in this direction you must challenge Richard the Rooster?";
	StringOO challenge13 = ">> To proceed in this direction you must challenge Michelle the Mouse?";
	StringOO challenge14 = ">> To proceed in this direction you must challenge Susan the Lazy?";
	StringOO challenge15 = ">> To proceed in this direction you must challenge Justin the Yellow?";
	// difficulty set to default of 2 and weighted based on location and player at the time the challenge is taken
	int difficulty = 2;

	challenge[0] = new Challenge(challenge0, 0);
	challenge[1] = new FleeChallenge(challenge1, difficulty);
	challenge[2] = new FleeChallenge(challenge2, difficulty);
	challenge[3] = new FleeChallenge(challenge3, difficulty);
	challenge[4] = new FleeChallenge(challenge4, difficulty);
	challenge[5] = new FleeChallenge(challenge5, difficulty);
	challenge[6] = new Question(Question1, Answer1, difficulty);
	challenge[7] = new Question(Question2, Answer2, difficulty);
	challenge[8] = new Question(Question3, Answer3, difficulty);
	challenge[9] = new Question(Question4, Answer4, difficulty);
	challenge[10] = new Question(Question5, Answer5, difficulty);
	challenge[11] = new PhysicalChallenge(challenge11, difficulty);
	challenge[12] = new PhysicalChallenge(challenge12, difficulty);
	challenge[13] = new PhysicalChallenge(challenge13, difficulty);
	challenge[14] = new PhysicalChallenge(challenge14, difficulty);
	challenge[15] = new PhysicalChallenge(challenge15, difficulty);

}
/*******************************************************************************************************
*    
*******************************************************************************************************/
void InitEnemies(Enemy * Enemies[], int enemyNum)
{
	int enemyLoc = 0;
	int strength = 0;
	int health = 0;
	int luck = 0;

	StringOO enemyName1 = "Bill the Badger";
	StringOO enemyName2 = "Richard the Rooster";
	StringOO enemyName3 = "Michelle the Mouse";
	StringOO enemyName4 = "Susan the Lazy";
	StringOO enemyName5 = "Justin the Yellow";
	std::vector<const char *> enemyNames = { enemyName1, enemyName2, enemyName3, enemyName4, enemyName5 };

	for (int i = 0; i < enemyNum; i++)
	{
		int strength = std::rand() % 5 + 5;
		int health = std::rand() % 20 + 80;
		int luck = std::rand() % 5 + 5;
		Enemies[i] = new Enemy(enemyLoc, enemyNames[i], strength, health, luck);
	}
}
/*******************************************************************************************************
*
*******************************************************************************************************/
void AddEnemyToChallenge(Enemy * Enemies[], Challenge * Challenges[], int enemyNum, int challNum)
{
	int c = 0;
	int diff = challNum - enemyNum;
	for (int i = 0; i < enemyNum; i++)
	{
		c = 0;
		c = i + diff;
		Challenges[c]->SetEnemy(*Enemies[i]);
	}
}
/*******************************************************************************************************
*
*******************************************************************************************************/
void InitHuman(Human human)
{
	//std::cout << "Please setup your character" << std::endl;
}
/*******************************************************************************************************
*
*******************************************************************************************************/
void DestroyLocations(Location *locations[], int length)
{
	for (int i = 0; i < length; i++)
	{
		delete locations[i];
	}
}
/*******************************************************************************************************
*
*******************************************************************************************************/
void DestroyChallenges(Challenge *challenge[], int length)
{
	for (int i = 0; i < length; i++)
	{
		delete challenge[i];
	}
}
/*******************************************************************************************************
*
*******************************************************************************************************/
void DestroyEnemies(Enemy *Enemies[], int length)
{
	for (int i = 0; i < length; i++)
	{
		delete Enemies[i];
	}
}

