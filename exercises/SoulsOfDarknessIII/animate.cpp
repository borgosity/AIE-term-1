#include "animate.h"
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <conio.h>


#include <thread>
#include <chrono>

#define KEY_UP 72
#define KEY_DOWN 80

static HWND  hConWnd;
HWND GetConsoleWndHandle(void);

void anitmation(std::vector<LPCWSTR> images)
{
	hConWnd = GetConsoleWndHandle();
	if (hConWnd)
	{
		//HWND BCX_Bitmap(LPCWSTR Text, HWND hWnd, int id, int X, int Y, int W, int H, int Res, int Style, int Exstyle)
		//BCX_Bitmap(images[i], hConWnd, 123, 1, 1, 0, 0);
		int id = 123;
		int X = 1;
		int Y = 1;
		int W = 0;
		int H = 0;
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
		
		// select a bitmap file you have or use one of the files in the Windows folder
		// filename, handle, ID, ulcX, ulcY, width, height   0,0 auto-adjusts
		
		//MSG msg;

		while (1)
		{

			for (int i = 0; i < images.size(); i++)
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
				//std::cout << "hello image - " << i << std::endl;
					
				//GetMessage(&msg, NULL, 0, 0);
				//if (msg.message == WM_KEYDOWN)
				//{
				//	std::cout << "key down" << std::endl;
				//}
				//else
				//{
				//	std::cout << "something else" << std::endl;
				//	TranslateMessage(&msg);
				//	DispatchMessage(&msg);
				//}

				std::this_thread::sleep_for(std::chrono::milliseconds(100));
				system("cls");
			}
		}
			 
		SendMessage(A, WM_CLOSE, 0, 0);
	}
}

// tricking Windows just a little ...
HWND GetConsoleWndHandle(void)
{
	HWND hConWnd;
	OSVERSIONINFO os;
	char szTempTitleC[64];

	LPWSTR szOriginalTitle = L"Souls Of Darkness III";

	sprintf(szTempTitleC, "%u - %u", GetTickCount(), GetCurrentProcessId());
	SetConsoleTitle(szOriginalTitle);
	Sleep(40);
	hConWnd = FindWindow(NULL, szOriginalTitle);

	return hConWnd;
}
