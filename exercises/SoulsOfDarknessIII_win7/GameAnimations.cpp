#include "GameAnimations.h"
#include <conio.h>
#include <string>

//some text

GameAnimations::GameAnimations(Console * consoleW, UserAction * keypress)
{
	m_console = consoleW;
	m_conHeight = m_console->m_consoleH;
	m_conWidth = m_console->m_consoleW;
	m_keypress = keypress;
	m_quitGame = false;
}

GameAnimations::~GameAnimations()
{
}

void GameAnimations::IntroAnime()
{
	DummyAnimation(m_conWidth, m_conHeight);
}

void GameAnimations::StartAnime()
{
	// white text
	LPCWSTR startPath_0 = L"images\\start\\start_white_0_M2.bmp";
	LPCWSTR startPath_1 = L"images\\start\\start_white_0_M.bmp";
	LPCWSTR startPath_2 = L"images\\start\\start_white_0_24.bmp";
	LPCWSTR startPath_3 = L"images\\start\\start_white_0_16.bmp";
	// white fade
	LPCWSTR startPath_4 = L"images\\start\\start_white_4.bmp";
	LPCWSTR startPath_5 = L"images\\start\\start_white_3.bmp";
	LPCWSTR startPath_6 = L"images\\start\\start_white_2.bmp";
	LPCWSTR startPath_7 = L"images\\start\\start_white_1.bmp";
	LPCWSTR startPath_8 = L"images\\start\\start_white_0.bmp";
	// red fade
	LPCWSTR startPath_9 = L"images\\start\\start_red_text_0.bmp";
	LPCWSTR startPath_10 = L"images\\start\\start_red_text_1.bmp";
	LPCWSTR startPath_11 = L"images\\start\\start_red_text_2.bmp";
	LPCWSTR startPath_12 = L"images\\start\\start_red_text_3.bmp";
	// red
	LPCWSTR startPath_13 = L"images\\start\\start_red_0.bmp";
	LPCWSTR startPath_14 = L"images\\start\\start_red_1.bmp";
	LPCWSTR startPath_15 = L"images\\start\\start_red_21.bmp";
	// key map images
	LPCWSTR keymapPath = L"images\\start\\keyMap.bmp";
	LPCWSTR keymapPath_16 = L"images\\start\\keyMap_16.bmp";
	LPCWSTR keymapPathRed = L"images\\start\\keyMapRed_2.bmp";

	// initialise image location vector
	std::vector<LPCWSTR> startFade;
	std::vector<LPCWSTR> start;
	std::vector<LPCWSTR> start_1;

	// white fade out
	startFade.push_back(startPath_4);
	startFade.push_back(startPath_5);
	startFade.push_back(startPath_6);
	startFade.push_back(startPath_7);
	startFade.push_back(startPath_8);
	startFade.push_back(startPath_8);
	startFade.push_back(startPath_0);

	// push image locations onto vector
	start.push_back(startPath_0);
	start.push_back(startPath_1);
	start.push_back(startPath_2);
	start.push_back(startPath_3);

	// push red vector
	start_1.push_back(startPath_15);
	start_1.push_back(startPath_15);
	start_1.push_back(startPath_14);
	start_1.push_back(startPath_13);
	start_1.push_back(startPath_12);
	start_1.push_back(startPath_11);
	start_1.push_back(startPath_10);
	start_1.push_back(startPath_9);

	// animate the images, requires user input to finish so pass keypress
	//DummyAnimation(m_keypress, m_conWidth, m_conHeight);
	animate(startFade, m_conWidth, m_conHeight, 250);
	animate(start, m_keypress, m_conWidth, m_conHeight, 250);
	animate(start_1, m_conWidth, m_conHeight, 120);
	splashScreen(keymapPath, m_keypress, m_conWidth, m_conHeight);
	splashScreen(keymapPathRed, m_conWidth, m_conHeight, 500);
	std::this_thread::sleep_for(std::chrono::seconds(1));
}

void GameAnimations::InGameAnime()
{
	// castle images
	LPCWSTR castlePath_0 = L"images\\play\\castle_2.bmp";
	LPCWSTR castlePath_1 = L"images\\play\\castle_1.bmp";
	LPCWSTR castlePath_2 = L"images\\play\\castle_0.bmp";
	// moving closer
	LPCWSTR castlePath_3 = L"images\\play\\castle_01.bmp";
	LPCWSTR castlePath_4 = L"images\\play\\castle_02.bmp";
	LPCWSTR castlePath_5 = L"images\\play\\castle_03.bmp";
	LPCWSTR castlePath_6 = L"images\\play\\castle_04.bmp";
	// set boss image locations
	LPCWSTR bossPath_00 = L"images\\play\\boss_mono.bmp";
	LPCWSTR bossPath_01 = L"images\\play\\boss_mono2.bmp";
	LPCWSTR bossPath_11 = L"images\\play\\boss2_left_mono.bmp";
	LPCWSTR bossPath_12 = L"images\\play\\boss2_left_mono2.bmp";
	LPCWSTR bossPath_13 = L"images\\play\\boss2_right_mono.bmp";
	LPCWSTR bossPath_14 = L"images\\play\\boss2_right_mono2.bmp";
	LPCWSTR bossPath_21 = L"images\\play\\boss3_left_mono.bmp";
	LPCWSTR bossPath_22 = L"images\\play\\boss3_left_mono2.bmp";
	LPCWSTR bossPath_23 = L"images\\play\\boss3_right_mono.bmp";
	LPCWSTR bossPath_24 = L"images\\play\\boss3_right_mono2.bmp";
	// set slash image locations
	LPCWSTR slashPath_00 = L"images\\play\\slash_0_16.bmp";
	LPCWSTR slashPath_01 = L"images\\play\\slash_0_24.bmp";
	LPCWSTR slashPath_02 = L"images\\play\\slash_0_mono.bmp";
	LPCWSTR slashPath_10 = L"images\\play\\slash_1_16.bmp";
	LPCWSTR slashPath_11 = L"images\\play\\slash_1_24.bmp";
	LPCWSTR slashPath_12 = L"images\\play\\slash_1_mono.bmp";
	LPCWSTR slashPath_20 = L"images\\play\\slash_3_16.bmp";
	LPCWSTR slashPath_21 = L"images\\play\\slash_3_24.bmp";
	LPCWSTR slashPath_22 = L"images\\play\\slash_3_mono.bmp";
	LPCWSTR slashPath_30 = L"images\\play\\slash_4_16.bmp";
	LPCWSTR slashPath_31 = L"images\\play\\slash_4_24.bmp";
	LPCWSTR slashPath_32 = L"images\\play\\slash_4_mono.bmp";
	// set splatter path
	LPCWSTR splatterPath_00 = L"images\\play\\splatter_0.bmp";
	LPCWSTR splatterPath_01 = L"images\\play\\splatter_1.bmp";
	// initialise image location vector
	std::vector<LPCWSTR> play_0;
	std::vector<LPCWSTR> play_1;
	std::vector<LPCWSTR> play;
	// push image locations onto vector
	play_0.push_back(castlePath_0);
	play_0.push_back(castlePath_0);
	play_0.push_back(castlePath_1);
	play_0.push_back(castlePath_1);
	play_0.push_back(castlePath_2);
	play_0.push_back(castlePath_2);
	// move closer
	play_1.push_back(castlePath_3);
	play_1.push_back(castlePath_3);
	play_1.push_back(castlePath_4);
	play_1.push_back(castlePath_4);
	play_1.push_back(castlePath_5);
	play_1.push_back(castlePath_5);
	play_1.push_back(castlePath_6);
	play_1.push_back(castlePath_6);
	// fight
	play.push_back(bossPath_00);
	play.push_back(bossPath_01);
	play.push_back(slashPath_00);
	play.push_back(slashPath_01);
	play.push_back(slashPath_02);
	play.push_back(splatterPath_00);
	play.push_back(bossPath_11);
	play.push_back(bossPath_12);
	play.push_back(slashPath_10);
	play.push_back(slashPath_11);
	play.push_back(slashPath_12);
	play.push_back(splatterPath_01);
	play.push_back(bossPath_13);
	play.push_back(bossPath_14);
	play.push_back(slashPath_20);
	play.push_back(slashPath_21);
	play.push_back(slashPath_22);
	play.push_back(splatterPath_00);
	play.push_back(bossPath_23);
	play.push_back(bossPath_24);
	play.push_back(slashPath_30);
	play.push_back(slashPath_31);
	play.push_back(slashPath_32);
	play.push_back(splatterPath_01);
	// animate the images, no user input required
	// walk path
	animate(play_0, m_conWidth, m_conHeight, 250);
	splashScreen(castlePath_2, m_keypress, m_conWidth, m_conHeight);
	splashScreen(castlePath_3, m_keypress, m_conWidth, m_conHeight);
	splashScreen(castlePath_4, m_keypress, m_conWidth, m_conHeight);
	splashScreen(castlePath_5, m_keypress, m_conWidth, m_conHeight);
	splashScreen(castlePath_6, m_keypress, m_conWidth, m_conHeight);
	//animate(play_1, m_conWidth, m_conHeight, 250);
	// fight
	animate(play, m_conWidth, m_conHeight, 100);
	//DummyAnimation(m_conWidth, m_conHeight);
}

void GameAnimations::YouDiedAnime()
{
	LPCWSTR youDied_0 = L"images\\died\\you_died_1.bmp";
	LPCWSTR youDied_1 = L"images\\died\\you_died_2.bmp";
	LPCWSTR youDied_2 = L"images\\died\\you_died_3.bmp";
	LPCWSTR youDied_3 = L"images\\died\\you_died_24.bmp";
	// animate the images, requires user input to finish so pass keypress
	//splashScreen(youDied_0, m_conWidth, m_conHeight, 200);
	//splashScreen(youDied_1, m_conWidth, m_conHeight, 200);
	//splashScreen(youDied_2, m_conWidth, m_conHeight, 200);
	splashScreen(youDied_3, m_keypress, m_conWidth, m_conHeight);
	//DummyAnimation(m_keypress, m_conWidth, m_conHeight);
}

bool GameAnimations::PlayAgainAnime()
{
	LPCWSTR youDied_0 = L"images\\died\\play_again.bmp";
	// animate the images, requires user input to finish so pass keypress
	//DummyAnimation(m_keypress, m_conWidth, m_conHeight);
	m_keypress->m_options = true;
	splashScreen(youDied_0, m_keypress, m_conWidth, m_conHeight);
	return m_quitGame;
}

void GameAnimations::JumpingBearAnime()
{
	LPCWSTR bearPath_0 = L"images\\bear\\image_0.bmp";
	LPCWSTR bearPath_1 = L"images\\bear\\image_1.bmp";
	LPCWSTR bearPath_2 = L"images\\bear\\image_2.bmp";
	LPCWSTR bearPath_3 = L"images\\bear\\image_3.bmp";
	LPCWSTR bearPath_4 = L"images\\bear\\image_4.bmp";
	LPCWSTR bearPath_5 = L"images\\bear\\image_5.bmp";
	LPCWSTR bearPath_6 = L"images\\bear\\image_6.bmp";
	LPCWSTR bearPath_7 = L"images\\bear\\image_7.bmp";
	LPCWSTR bearPath_8 = L"images\\bear\\image_8.bmp";
	LPCWSTR startPath_15 = L"images\\start\\start_red_21.bmp";
	// initialise image location vector
	std::vector<LPCWSTR> bear;
	// push image locations onto vector
	bear.push_back(bearPath_0);
	bear.push_back(bearPath_1);
	bear.push_back(bearPath_2);
	bear.push_back(bearPath_3);
	bear.push_back(bearPath_4);
	bear.push_back(bearPath_5);
	bear.push_back(bearPath_6);
	bear.push_back(bearPath_7);
	bear.push_back(bearPath_8);
	bear.push_back(bearPath_8);
	bear.push_back(bearPath_7);
	bear.push_back(bearPath_6);
	bear.push_back(bearPath_5);
	bear.push_back(bearPath_4);
	bear.push_back(bearPath_3);
	bear.push_back(bearPath_2);
	bear.push_back(bearPath_1);
	bear.push_back(bearPath_0);
	bear.push_back(startPath_15);
	// animate the images
	animate(bear, m_keypress, m_conWidth, m_conHeight, 40);
}

HWND GameAnimations::GetConsoleWndHandle(void)
{
	HWND hConWnd;
	char szTempTitleC[64];
	LPWSTR szOriginalTitle = L"Souls Of Darkness III";
	sprintf_s(szTempTitleC, "%u - %u", GetTickCount(), GetCurrentProcessId());
	SetConsoleTitle(szOriginalTitle);
	Sleep(40);
	hConWnd = FindWindow(NULL, szOriginalTitle);

	return hConWnd;
}

void GameAnimations::animate(std::vector<LPCWSTR>& images, UserAction * keypress, int width, int height, int speed)
{
	keypress->m_keypress = false;

	static HWND  hConWnd;
	hConWnd = GetConsoleWndHandle();
	if (hConWnd)
	{
		int id = 123;
		int X = 1;
		int Y = 1;
		int W = width;
		int H = height;
		int Res = 0;
		int Style = 0;
		int Exstyle = 0;

		HWND A;
		HBITMAP hBitmap;

		// set default style
		if (!Style)
		{
			Style = WS_CLIPSIBLINGS | WS_CHILD | WS_VISIBLE | SS_BITMAP | WS_TABSTOP;
		}

		// form for the image
		LPCWSTR stat = L"static";
		A = CreateWindowEx(Exstyle, stat, NULL, Style, X, Y, 0, 0, hConWnd, (HMENU)id, GetModuleHandle(0), NULL);

		while (!keypress->m_keypress)
		{

			for (unsigned int i = 0; i < images.size(); i++)
			{
				// Text contains filename
				hBitmap = (HBITMAP)LoadImage(0, images[i], IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
				// auto-adjust width and height
				if (W || H)
				{
					hBitmap = (HBITMAP)CopyImage(hBitmap, IMAGE_BITMAP, W, H, LR_COPYRETURNORG);
				}
				SendMessage(A, (UINT)STM_SETIMAGE, (WPARAM)IMAGE_BITMAP, (LPARAM)hBitmap);
				if (W || H)
				{
					SetWindowPos(A, HWND_TOP, X, Y, W, H, SWP_DRAWFRAME);
				}
				//if (GetAsyncKeyState(VK_RETURN))
				//{
				//	std::cout << " ENTER " << std::endl;
				//	keypress->m_keypress = true;
				//}
				/*enterPress();*/
				std::this_thread::sleep_for(std::chrono::milliseconds(speed));
				system("cls");
			}
		}
		SendMessage(A, WM_CLOSE, 0, 0);
		keypress->m_keypress = false;
	}
}

void GameAnimations::animate(std::vector<LPCWSTR>& images, int width, int height, int speed)
{
	static HWND  hConWnd;
	hConWnd = GetConsoleWndHandle();
	if (hConWnd)
	{
		int id = 123;
		int X = 1;
		int Y = 1;
		int W = width;
		int H = height;
		int Res = 0;
		int Style = 0;
		int Exstyle = 0;

		HWND A;
		HBITMAP hBitmap;

		// set default style
		if (!Style)
		{
			Style = WS_CLIPSIBLINGS | WS_CHILD | WS_VISIBLE | SS_BITMAP | WS_TABSTOP;
		}

		// form for the image
		LPCWSTR stat = L"static";
		A = CreateWindowEx(Exstyle, stat, NULL, Style, X, Y, 0, 0, hConWnd, (HMENU)id, GetModuleHandle(0), NULL);

		for (unsigned int i = 0; i < images.size(); i++)
		{
			// Text contains filename
			hBitmap = (HBITMAP)LoadImage(0, images[i], IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
			// auto-adjust width and height
			if (W || H)
			{
				hBitmap = (HBITMAP)CopyImage(hBitmap, IMAGE_BITMAP, W, H, LR_COPYRETURNORG);
			}
			SendMessage(A, (UINT)STM_SETIMAGE, (WPARAM)IMAGE_BITMAP, (LPARAM)hBitmap);
			if (W || H)
			{
				SetWindowPos(A, HWND_TOP, X, Y, W, H, SWP_DRAWFRAME);
			}
			std::this_thread::sleep_for(std::chrono::milliseconds(speed));
			system("cls");
		}
		SendMessage(A, WM_CLOSE, 0, 0);
	}
}

void GameAnimations::arrowPress()
{
	int pressU_old = 0;
	int pressU_new = 0;
	int pressD_old = 0;
	int pressD_new = 0;
	if (GetAsyncKeyState(VK_DOWN))
	{
		pressU_new = 1;
	}
	else
	{
		pressU_new = 0;
	}
	if (GetAsyncKeyState(VK_UP))
	{
		pressD_new = 1;
	}
	else
	{
		pressD_new = 0;
	}
	if (pressU_new != pressU_old)
	{
		if (pressU_new)
		{
			//std::cout << " DOWN " << std::endl;
			// display no selected
			m_quitGame = true;
			textOptions();
		}
		pressU_old = pressU_new;
	}
	if (pressD_new != pressD_old)
	{
		if (pressD_new)
		{
			//std::cout << " UP " << std::endl;
			// display no selected
			m_quitGame = false;
			textOptions();
		}
		pressD_old = pressD_new;
	}
}

void GameAnimations::enterPress()
{
	int press_old = 0;
	int press_new = 0;
	if (GetAsyncKeyState(VK_RETURN))
	{
		press_new = 1;
	}
	else
	{
		press_new = 0;
	}
	if (press_new != press_old)
	{
		if (press_new)
		{
			//std::cout << " ENTER " << std::endl;
			m_keypress->m_keypress = true;
			std::this_thread::sleep_for(std::chrono::milliseconds(200));
		}
		press_old = press_new;
	}
}

void GameAnimations::splashScreen(LPCWSTR image, UserAction * keypress, int width, int height)
{
	keypress->m_keypress = false;
	static HWND  hConWnd;
	hConWnd = GetConsoleWndHandle();
	if (hConWnd)
	{
		int id = 123;
		int X = 1;
		int Y = 1;
		int W = width;
		int H = height;
		int Res = 0;
		int Style = 0;
		int Exstyle = 0;

		HWND A;
		HBITMAP hBitmap;

		// set default style
		if (!Style)
		{
			Style = WS_CLIPSIBLINGS | WS_CHILD | WS_VISIBLE | SS_BITMAP | WS_TABSTOP;
		}

		// form for the image
		LPCWSTR stat = L"static";
		A = CreateWindowEx(Exstyle, stat, NULL, Style, X, Y, 0, 0, hConWnd, (HMENU)id, GetModuleHandle(0), NULL);

		while (!keypress->m_keypress)
		{
			// Text contains filename
			hBitmap = (HBITMAP)LoadImage(0, image, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
			// auto-adjust width and height
			if (W || H)
			{
				hBitmap = (HBITMAP)CopyImage(hBitmap, IMAGE_BITMAP, W, H, LR_COPYRETURNORG);
			}
			SendMessage(A, (UINT)STM_SETIMAGE, (WPARAM)IMAGE_BITMAP, (LPARAM)hBitmap);
			if (W || H)
			{
				SetWindowPos(A, HWND_TOP, X, Y, W, H, SWP_DRAWFRAME);
			}
			if (keypress->m_options)
			{
				if (keypress->m_DownPress)
				{
					m_quitGame = true;
					textOptions();
					keypress->m_DownPress = false;
				}
				else if (keypress->m_upPress)
				{
					m_quitGame = false;
					textOptions();
					keypress->m_upPress = false;
				}
				else
				{
					textOptions();
				}
			}
			if (keypress->m_playing)
			{
				if (keypress->m_upPress)
				{
					keypress->m_keypress = true;
					keypress->m_upPress = false;
				}
			}
			//while (!keypress->m_keypress)
			//{
				/*enterPress();*/
				//if (keypress->m_options)
				//{
				//	arrowPress();
				//}
			std::this_thread::sleep_for(std::chrono::milliseconds(200));
		}
		//std::this_thread::sleep_for(std::chrono::milliseconds(speed));
		//system("cls");
		keypress->m_keypress = false;
		keypress->m_options = false;
		SendMessage(A, WM_CLOSE, 0, 0);
	}
}

void GameAnimations::splashScreen(LPCWSTR image, int width, int height, int time)
{
	static HWND  hConWnd;
	hConWnd = GetConsoleWndHandle();
	if (hConWnd)
	{
		int id = 123;
		int X = 1;
		int Y = 1;
		int W = width;
		int H = height;
		int Res = 0;
		int Style = 0;
		int Exstyle = 0;

		HWND A;
		HBITMAP hBitmap;

		// set default style
		if (!Style)
		{
			Style = WS_CLIPSIBLINGS | WS_CHILD | WS_VISIBLE | SS_BITMAP | WS_TABSTOP;
		}

		// form for the image
		LPCWSTR stat = L"static";
		A = CreateWindowEx(Exstyle, stat, NULL, Style, X, Y, 0, 0, hConWnd, (HMENU)id, GetModuleHandle(0), NULL);
		for (int i = 0; i < 2; i++)
		{
			// Text contains filename
			hBitmap = (HBITMAP)LoadImage(0, image, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
			// auto-adjust width and height
			if (W || H)
			{
				hBitmap = (HBITMAP)CopyImage(hBitmap, IMAGE_BITMAP, W, H, LR_COPYRETURNORG);
			}

			SendMessage(A, (UINT)STM_SETIMAGE, (WPARAM)IMAGE_BITMAP, (LPARAM)hBitmap);

			if (W || H)
			{
				SetWindowPos(A, HWND_TOP, X, Y, W, H, SWP_DRAWFRAME);
			}
			std::this_thread::sleep_for(std::chrono::milliseconds(time));
		}
		SendMessage(A, WM_CLOSE, 0, 0);
	}
}

//void GameAnimations::userInput(UserAction * keypress)
//{
//	int c = 0;
//	while (c != 13)
//	{
//		c = _getch();
//	}
//	keypress->m_keypress = true;
//}

void GameAnimations::textOptions()
{
	std::string again;
	std::string quit;
	std::string again_0 = " > AGAIN < ";
	std::string quit_0 = "   QUIT   ";
	std::string again_1 = "   AGAIN   ";
	std::string quit_1 = " > QUIT  < ";
	std::string blank = "-----------";

	int width = (m_console->width() / 2) - 5;
	int height = (m_console->height() / 2) - 1;
	int x = width;
	int y = height;
	if (m_quitGame)
	{
		again = again_1;
		quit = quit_1;
	}
	else
	{
		again = again_0;
		quit = quit_0;
	}
	for (int i = 0; i < blank.size(); i++)
	{
		x = width;
		y = height - 1;
		x += i;
		m_console->write(x, y, blank[i]);
	}
	for (int i = 0; i < again.size(); i++)
	{
		x = width;
		y = height;
		x += i;
		m_console->write(x, y, again[i]);
	}
	for (int i = 0; i < quit.size(); i++)
	{
		x = width;
		y = height + 1;
		x += i;
		m_console->write(x, y, quit[i]);
	}
	for (int i = 0; i < blank.size(); i++)
	{
		x = width;
		y = height + 2;
		x += i;
		m_console->write(x, y, blank[i]);
	}
}

void GameAnimations::DummyAnimation(UserAction * keypress, int width, int height)
{
	std::cout << keypress->m_keypress << " start animation" << std::endl;
	while (!keypress->m_keypress)
	{
		//std::cout << " animation \n\n" << keypress->m_keypress << std::endl;
	}
	std::cout << keypress->m_keypress << " end animation \n\n" << std::endl;
	keypress->m_keypress = false;
	std::cout << keypress->m_keypress << " reset keypress animation \n\n" << std::endl;
}

void GameAnimations::DummyAnimation(int width, int height)
{
	std::cout << " start animation" << std::endl;
	for (int i = 0; i < 10; i++)
	{
		//std::cout << " animation \n\n" << i << std::endl;
	}
	std::cout << " end animation \n\n" << std::endl;
}


