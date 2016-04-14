#include <iostream>
#include <vector>
#include <stdio.h>
#include <string.h>
#include <windows.h>    // Win32Api Header File 

#include <thread>
#include <chrono>

#include "animate.h"

#include <conio.h>



LPCWSTR imagePath_0 = L"images\\image_0.bmp";
LPCWSTR imagePath_1 = L"images\\image_1.bmp";
LPCWSTR imagePath_2 = L"images\\image_2.bmp";
LPCWSTR imagePath_3 = L"images\\image_3.bmp";
LPCWSTR imagePath_4 = L"images\\image_4.bmp";
LPCWSTR imagePath_5 = L"images\\image_5.bmp";
LPCWSTR imagePath_6 = L"images\\image_6.bmp";
LPCWSTR imagePath_7 = L"images\\image_7.bmp";
LPCWSTR imagePath_8 = L"images\\image_8.bmp";

LPCWSTR start_0 = L"images\\start_mono.bmp";
LPCWSTR start_1 = L"images\\start_16.bmp";
LPCWSTR start_2 = L"images\\start_24.bmp";
LPCWSTR start_3 = L"images\\start_16_red.bmp";
LPCWSTR start_4 = L"images\\start_24_red.bmp";


int main()
{
	std::vector<LPCWSTR> images;
	std::vector<LPCWSTR> start;
	start.push_back(start_0);
	start.push_back(start_0);
	start.push_back(start_0);
	start.push_back(start_0);
	start.push_back(start_1);
	start.push_back(start_2);
	start.push_back(start_2);
	start.push_back(start_1);
	start.push_back(start_0);
	start.push_back(start_0);
	start.push_back(start_0);
	start.push_back(start_0);
	start.push_back(start_3);
	start.push_back(start_4);
	start.push_back(start_3);
	start.push_back(start_0);
	start.push_back(start_0);
	start.push_back(start_0);
	start.push_back(start_0);

	images.push_back(imagePath_0);
	images.push_back(imagePath_1);
	images.push_back(imagePath_2);
	images.push_back(imagePath_3);
	images.push_back(imagePath_4);
	images.push_back(imagePath_5);
	images.push_back(imagePath_6);
	images.push_back(imagePath_7);
	images.push_back(imagePath_8);
	images.push_back(imagePath_7);
	images.push_back(imagePath_6);
	images.push_back(imagePath_5);
	images.push_back(imagePath_4);
	images.push_back(imagePath_3);
	images.push_back(imagePath_2);
	images.push_back(imagePath_1);
	images.push_back(imagePath_0);



	// intro

	// display start screen
	/*std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n                        Start\n\n" << std::endl;*/
	int c = 0;
	while(c ==0)
	{
		anitmation(start);
		std::cout << "hello" << std::endl;
		c = 0;
		c = getch();
		std::cout << c << std::endl;
	}
	// play game

	// you died screen

	// play again

	std::cout << "\n\nfinished\n\n" << std::endl;
	return 0;
}
