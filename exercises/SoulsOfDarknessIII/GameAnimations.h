#pragma once
// std libraries
#include <iostream>
#include <vector>
#include <windows.h>
#include <thread>
#include <chrono>

// home grown
#include "UserAction.h"
#include "Console.h"


class GameAnimations
{
public:
	GameAnimations(Console * consoleW, UserAction * keypress);
	~GameAnimations();
	void IntroAnime();
	void StartAnime();
	void StartAnimeOld();
	void InGameAnime();
	void YouDiedAnime();
	void PlayAgainAnime();
	void JumpingBearAnime();
private:
	HWND GetConsoleWndHandle(void);
	void animate(std::vector<LPCWSTR> & images, UserAction * keypress, int width, int height, int speed);
	void animate(std::vector<LPCWSTR> & images, int width, int height, int speed);
	void splashScreen(LPCWSTR image, UserAction * keypress, int width, int height);
	void splashScreen(LPCWSTR image, int width, int height, int time);
	void DummyAnimation(UserAction * keypress, int width, int height);
	void DummyAnimation(int width, int height);
	UserAction * m_keypress;
	Console * m_console;
	int m_conWidth;
	int m_conHeight;
};

