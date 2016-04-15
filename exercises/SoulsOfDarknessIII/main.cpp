
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
	while (c == 0)
	{
		c = _getch();
	}
	std::cout << keypress->m_keypress << "\n keypressed" << std::endl;
	std::cout << "button pressed = " << c << std::endl;
	keypress->m_keypress = true;
	std::cout << keypress->m_keypress << " updated after press" << std::endl;
}

void main()
{

	// Instantiate a console object with a full-screen window
	//Console console;
	// Instantiate a console object with a sized window
	//Console * console = new Console(-1,-1,101,40);
	Console console(-1, -1, 101, 40);

	//initialise UserActions
	UserAction * keypress = new UserAction();
	std::cout << keypress->m_keypress << " initialised" << std::endl;

	// initialise GameAnimation Object
	GameAnimations * GameAnime = new GameAnimations(&console, keypress);

	/*******************************************************************
	// intro
	********************************************************************/
	std::cout << " INTRO" << std::endl;
	GameAnime->IntroAnime();

	/*******************************************************************
		display start screen
	********************************************************************/ 
	// create a thread for user input, needs to run in the back ground
	// while animation runs
	std::thread t_listen_0(getUserInput, keypress);
	t_listen_0;
	std::cout << " START" << std::endl;
	GameAnime->StartAnime();
	
	/*******************************************************************
	   play game
	********************************************************************/
	std::cout << " Playing" << std::endl;
	GameAnime->InGameAnime();

	/*******************************************************************
	   you died screen
	********************************************************************/
	std::thread t_listen_1(getUserInput, keypress);
	t_listen_1;
	std::cout << keypress->m_keypress << " DIED" << std::endl;
	GameAnime->YouDiedAnime();
	/*******************************************************************
	   play again
	********************************************************************/
	std::thread t_listen_2(getUserInput, keypress);
	t_listen_2;
	std::cout << keypress->m_keypress << " Play again" << std::endl;
	GameAnime->PlayAgainAnime();
	/*******************************************************************
	  the end
	********************************************************************/
	std::thread t_listen_3(getUserInput, keypress);
	t_listen_3;
	GameAnime->JumpingBearAnime();

	std::cout << "\n\nfinished\n\n" << std::endl;

	delete GameAnime;
	delete keypress;
	delete & console;
}
