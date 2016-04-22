#include "GameAnimations.h"
#include <conio.h>

//some text

GameAnimations::GameAnimations(Console * consoleW, UserAction * keypress)
{
	m_console = consoleW;
	m_conHeight = m_console->m_consoleH;
	m_conWidth = m_console->m_consoleW;
	m_keypress = keypress;
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
	LPCWSTR startPath_0 = L"images\\start\\start_white_0_M2.bmp";
	LPCWSTR startPath_1 = L"images\\start\\start_white_0_M.bmp";
	LPCWSTR startPath_2 = L"images\\start\\start_white_0_24.bmp";
	LPCWSTR startPath_3 = L"images\\start\\start_white_0_16.bmp";
	LPCWSTR startPath_4 = L"images\\start\\start_white_0.bmp";
	LPCWSTR startPath_5 = L"images\\start\\start_white_1.bmp";
	LPCWSTR startPath_6 = L"images\\start\\start_white_2.bmp";
	LPCWSTR startPath_7 = L"images\\start\\start_white_3.bmp";
	LPCWSTR startPath_8 = L"images\\start\\start_white_4.bmp";
	LPCWSTR startPath_9 = L"images\\start\\start_red_text_0.bmp";
	LPCWSTR startPath_10 = L"images\\start\\start_red_text_1.bmp";
	LPCWSTR startPath_11 = L"images\\start\\start_red_text_2.bmp";
	LPCWSTR startPath_12 = L"images\\start\\start_red_text_3.bmp";
	LPCWSTR startPath_13 = L"images\\start\\start_red_0.bmp";
	LPCWSTR startPath_14 = L"images\\start\\start_red_1.bmp";
	LPCWSTR startPath_15 = L"images\\start\\start_red_2.bmp";
	// key map images
	LPCWSTR keymapPath = L"images\\start\\keyMap.bmp";
	LPCWSTR keymapPathRed = L"images\\start\\keyMapRed.bmp";
	// initialise image location vector
	std::vector<LPCWSTR> start;
	std::vector<LPCWSTR> start_1;
	// push image locations onto vector
	start.push_back(startPath_0);
	start.push_back(startPath_1);
	start.push_back(startPath_2);
	start.push_back(startPath_3);
	start.push_back(startPath_4);
	start.push_back(startPath_5);
	start.push_back(startPath_6);
	start.push_back(startPath_7);
	start.push_back(startPath_8);
	start.push_back(startPath_8);
	start.push_back(startPath_7);
	start.push_back(startPath_6);
	start.push_back(startPath_5);
	start.push_back(startPath_4);
	start.push_back(startPath_3);
	start.push_back(startPath_2);
	start.push_back(startPath_1);
	start.push_back(startPath_0);
	// push red vector
	start_1.push_back(startPath_9);
	start_1.push_back(startPath_10);
	start_1.push_back(startPath_11);
	start_1.push_back(startPath_12);
	start_1.push_back(startPath_13);
	start_1.push_back(startPath_14);
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
	animate(start, m_keypress, m_conWidth, m_conHeight, 120);
	animate(start_1, m_conWidth, m_conHeight, 120);
	splashScreen(keymapPath, m_keypress, m_conWidth, m_conHeight);
	splashScreen(keymapPathRed, m_conWidth, m_conHeight, 250);
}

void GameAnimations::StartAnimeOld()
{
	// set image locations
	LPCWSTR startPath_ = L"images\\start\\start_edged.bmp";
	LPCWSTR startPath_0 = L"images\\start\\start_mono.bmp";
	LPCWSTR startPath_1 = L"images\\start\\start_16.bmp";
	LPCWSTR startPath_2 = L"images\\start\\start_24.bmp";
	LPCWSTR startPath_3 = L"images\\start\\start_16_red.bmp";
	LPCWSTR startPath_4 = L"images\\start\\start_24_red.bmp";
	// initialise image location vector
	std::vector<LPCWSTR> start;
	std::vector<LPCWSTR> start1;
	// push image locations onto vector
	start.push_back(startPath_0);
	start.push_back(startPath_0);
	start.push_back(startPath_0);
	start.push_back(startPath_0);
	start.push_back(startPath_1);
	start.push_back(startPath_2);
	start.push_back(startPath_2);
	start.push_back(startPath_1);
	start.push_back(startPath_0);
	start.push_back(startPath_0);
	start.push_back(startPath_0);
	start.push_back(startPath_0);
	start.push_back(startPath_3);
	start.push_back(startPath_4);
	start.push_back(startPath_3);
	start.push_back(startPath_0);
	start.push_back(startPath_0);
	start.push_back(startPath_0);
	start.push_back(startPath_0);
	// animate the images, requires user input to finish so pass keypress
	//DummyAnimation(m_keypress, m_conWidth, m_conHeight);
	animate(start, m_keypress, m_conWidth, m_conHeight, 100);

}

void GameAnimations::InGameAnime()
{
	// castle images
	LPCWSTR castlePath_0 = L"images\\play\\castle_2.bmp";
	LPCWSTR castlePath_1 = L"images\\play\\castle_1.bmp";
	LPCWSTR castlePath_2 = L"images\\play\\castle_0.bmp";
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
	// initialise image location vector
	std::vector<LPCWSTR> play;
	// push image locations onto vector
	play.push_back(castlePath_0);
	play.push_back(castlePath_1);
	play.push_back(castlePath_2);
	play.push_back(castlePath_3);
	play.push_back(castlePath_4);
	play.push_back(castlePath_5);
	play.push_back(castlePath_6);
	play.push_back(bossPath_00);
	play.push_back(bossPath_01);
	play.push_back(slashPath_00);
	play.push_back(slashPath_01);
	play.push_back(slashPath_02);
	play.push_back(bossPath_11);
	play.push_back(bossPath_12);
	play.push_back(slashPath_10);
	play.push_back(slashPath_11);
	play.push_back(slashPath_12);
	play.push_back(bossPath_13);
	play.push_back(bossPath_14);
	play.push_back(slashPath_20);
	play.push_back(slashPath_21);
	play.push_back(slashPath_22);
	play.push_back(bossPath_23);
	play.push_back(bossPath_24);
	play.push_back(slashPath_30);
	play.push_back(slashPath_31);
	play.push_back(slashPath_32);
	// animate the images, no user input required
	animate(play, m_conWidth, m_conHeight, 100);
	//DummyAnimation(m_conWidth, m_conHeight);
}

void GameAnimations::YouDiedAnime()
{
	LPCWSTR youDied_0 = L"images\\died\\you_died_24.bmp";
	// animate the images, requires user input to finish so pass keypress
	splashScreen(youDied_0, m_keypress, m_conWidth, m_conHeight);
	//DummyAnimation(m_keypress, m_conWidth, m_conHeight);
}

void GameAnimations::PlayAgainAnime()
{
	// animate the images, requires user input to finish so pass keypress
	DummyAnimation(m_keypress, m_conWidth, m_conHeight);
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
				if (GetAsyncKeyState(VK_RETURN))
				{
					std::cout << " ENTER " << std::endl;
					keypress->m_keypress = true;
				}
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

void GameAnimations::splashScreen(LPCWSTR image, UserAction * keypress, int width, int height)
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
		while (!keypress->m_keypress)
		{
			if (GetAsyncKeyState(VK_RETURN))
			{
				std::cout << " ENTER " << std::endl;
				keypress->m_keypress = true;
			}
			if (GetAsyncKeyState(VK_DOWN))
			{
				std::cout << " DOWN " << std::endl;
				// display no selected
				keypress->m_keypress = true;
			}
			if (GetAsyncKeyState(VK_UP))
			{
				std::cout << " UP " << std::endl;
				// display yes selected
				keypress->m_keypress = true;
			}
		}
		//std::this_thread::sleep_for(std::chrono::milliseconds(speed));
		//system("cls");
		keypress->m_keypress = false;
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
		SendMessage(A, WM_CLOSE, 0, 0);
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


