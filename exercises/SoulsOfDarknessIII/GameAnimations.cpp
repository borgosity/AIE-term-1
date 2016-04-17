#include "GameAnimations.h"

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
	
	// set image locations
	LPCWSTR startPath_ = L"images\\start\\start_edged.bmp";
	LPCWSTR startPath_0 = L"images\\start\\start_mono.bmp";
	LPCWSTR startPath_1 = L"images\\start\\start_16.bmp";
	LPCWSTR startPath_2 = L"images\\start\\start_24.bmp";
	LPCWSTR startPath_3 = L"images\\start\\start_16_red.bmp";
	LPCWSTR startPath_4 = L"images\\start\\start_24_red.bmp";
	// initialise image location vector
	std::vector<LPCWSTR> start;
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
	// animate the images, requires user input to finish so pass keypress
	DummyAnimation(m_keypress, m_conWidth, m_conHeight);
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
	HWND conWnd = GetConsoleWindow();
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

		int loopCount = 0;

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

		while (loopCount != 10)
		{
			//!keypress->m_keypress ||
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
				std::cout << loopCount << std::endl;
				std::cout << keypress->m_keypress << std::endl;
				std::this_thread::sleep_for(std::chrono::milliseconds(speed));
				system("cls");
			}
			loopCount++;
			std::cout << keypress->m_keypress << std::endl;
		}

		SendMessage(A, WM_CLOSE, 0, 0);
		keypress->m_keypress = false;
	}
}

void GameAnimations::animate(std::vector<LPCWSTR>& images, int width, int height, int speed)
{
	static HWND  hConWnd;
	hConWnd = GetConsoleWndHandle();
	HWND conWnd = GetConsoleWindow();
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

