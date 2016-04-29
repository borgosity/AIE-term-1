
// std libraries
#include <iostream>
#include <vector>
#include <stdio.h>
#include <string.h>
#include <windows.h>  
#include <thread>
#include <chrono>
#include <conio.h>

// home grown
#include "animate.h"
#include "UserAction.h"
#include "Console.h"
#include "GameAnimations.h"


void getUserInput(UserAction * keypress)
{
	int c = 0;
	while (!keypress->m_quit)
	{
		c = _getch();
		// check for enter key
		if (c == 13)
		{
			keypress->m_keypress = true;
		}
		// check for up arrow
		if (c == 72)
		{
			keypress->m_upPress = true;
		}
		// check for down arrow
		if (c == 80)
		{
			keypress->m_DownPress = true;
		}

		c = 0;
	}

}

void gameLoop(GameAnimations * GameAnime, UserAction * keypress)
{
	bool replay = false;
	keypress->m_keypress = false;
	/*******************************************************************
	// intro
	********************************************************************/
	//std::cout << " INTRO" << std::endl;
	//GameAnime->IntroAnime();

	while (!replay)
	{
		/*******************************************************************
		display start screen
		********************************************************************/
		// create a thread for user input, needs to run in the back ground
		// while animation runs
		std::thread t_listen_0(getUserInput, keypress);
		t_listen_0.detach();
		//std::cout << " START" << std::endl;
		GameAnime->StartAnime();

		/*******************************************************************
		play game
		********************************************************************/
		//std::cout << " Playing" << std::endl;
		keypress->m_playing = true;
		GameAnime->InGameAnime();
		keypress->m_playing = false;

		/*******************************************************************
		you died screen
		********************************************************************/
		//std::thread t_listen_1(getUserInput, keypress);
		//t_listen_1;
		//std::cout << keypress->m_keypress << " DIED" << std::endl;
		GameAnime->YouDiedAnime();
		/*******************************************************************
		play again
		********************************************************************/
		//std::thread t_listen_2(getUserInput, keypress);
		//t_listen_2;
		//std::cout << keypress->m_keypress << " Play again" << std::endl;
		replay = GameAnime->PlayAgainAnime();
	}
	/*******************************************************************
	the end
	********************************************************************/
	//std::thread t_listen_3(getUserInput, keypress);
	//t_listen_3;
	GameAnime->JumpingBearAnime();
}

void main()
{

	// Instantiate a console object with a full-screen window
	Console console;
	// Instantiate a console object with a sized window
	//Console console(-1, -1, 101, 40);

	//initialise UserActions
	UserAction * keypress = new UserAction();
	//std::cout << keypress->m_keypress << " initialised" << std::endl;

	// initialise GameAnimation Object
	GameAnimations * GameAnime = new GameAnimations(&console, keypress);

	gameLoop(GameAnime, keypress);

	std::cout << "\n\nfinished\n\n" << std::endl;

	//delete GameAnime;
	//delete keypress;
	//delete & console;
}
