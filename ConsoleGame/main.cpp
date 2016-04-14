#include <iostream>
#include <vector>
#include <stdio.h>
#include <string.h>
#include <windows.h>    // Win32Api Header File 

#include <thread>
#include <chrono>

#include "animate.h"



LPCWSTR imagePath_0 = L"C:\\Users\\phillip.banks\\Documents\\Visual Studio 2015\\Projects\\AIE-term-1\\ConsoleGame\\images\\image_0.bmp";
LPCWSTR imagePath_1 = L"C:\\Users\\phillip.banks\\Documents\\Visual Studio 2015\\Projects\\AIE-term-1\\ConsoleGame\\images\\image_1.bmp";
LPCWSTR imagePath_2 = L"C:\\Users\\phillip.banks\\Documents\\Visual Studio 2015\\Projects\\AIE-term-1\\ConsoleGame\\images\\image_2.bmp";
LPCWSTR imagePath_3 = L"C:\\Users\\phillip.banks\\Documents\\Visual Studio 2015\\Projects\\AIE-term-1\\ConsoleGame\\images\\image_3.bmp";
LPCWSTR imagePath_4 = L"C:\\Users\\phillip.banks\\Documents\\Visual Studio 2015\\Projects\\AIE-term-1\\ConsoleGame\\images\\image_4.bmp";
LPCWSTR imagePath_5 = L"C:\\Users\\phillip.banks\\Documents\\Visual Studio 2015\\Projects\\AIE-term-1\\ConsoleGame\\images\\image_5.bmp";
LPCWSTR imagePath_6 = L"C:\\Users\\phillip.banks\\Documents\\Visual Studio 2015\\Projects\\AIE-term-1\\ConsoleGame\\images\\image_6.bmp";
LPCWSTR imagePath_7 = L"C:\\Users\\phillip.banks\\Documents\\Visual Studio 2015\\Projects\\AIE-term-1\\ConsoleGame\\images\\image_7.bmp";
LPCWSTR imagePath_8 = L"C:\\Users\\phillip.banks\\Documents\\Visual Studio 2015\\Projects\\AIE-term-1\\ConsoleGame\\images\\image_8.bmp";

int main()
{
	std::vector<LPCWSTR> images;
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
	anitmation(images);

	std::cout << "\n\nfinished\n\n" << std::endl;
	return 0;
}
