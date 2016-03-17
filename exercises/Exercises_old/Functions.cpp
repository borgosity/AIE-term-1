#include <iostream>
#include <cstdlib>
#include <string>
#include "Functions.h"

using namespace std;

// Functions Exercise1
void PrintInteger(int variable)
{
	cout << variable << endl;
}
void FunctionsEx1()
{
	int the_variable = 1;
	PrintInteger(the_variable);
	{
		PrintInteger(the_variable);
		int the_variable = 2;
		PrintInteger(the_variable);
		{
			PrintInteger(the_variable);
			int the_variable = 3;
			PrintInteger(the_variable);
		}
		PrintInteger(the_variable);
	}
	PrintInteger(the_variable);
}

// Functions Exercise 2
float Smaller(float val1, float val2)
{
	float equal = 0;
	if (val1 > val2)
	{
		return val2;
	}
	else if (val2 > val1)
	{
		return val1;
	}
	else
	{
		return equal;
	}
}
void FunctionsEx2()
{
	float value1 = 0;
	float value2 = 0;
	cout << "Please enter two values and I will return the smaller of the two:" << endl;
	cout << "Enter value 1: ";
	cin >> value1;
	cout << "Enter value 2: ";
	cin >> value2;
	if (Smaller(value1, value2) == 0)
	{
		cout << "Neither number is smaller than the other!" << endl;
	}
	else
	{
		cout << "The smaller number is: " << Smaller(value1, value2) << endl;
	}
	
}
// Functions Exercise 3
float Smaller(float val1, float val2, float val3)
{
	float equal = 0;
	float smallest = 0;
	if ((val1 >= val2) && (val3 >= val2))
	{
		return smallest = val2;
	}
	else if ((val2 >= val1) && (val3 >= val1))
	{
		return smallest = val1;
	}
	else if ((val2 >= val3) && (val1 >= val3))
	{
		return smallest = val3;
	}
	else
	{
		return equal;
	}
}
void FunctionsEx3()
{
	float value1 = 0;
	float value2 = 0;
	float value3 = 0;
	cout << "Please enter two values and I will return the smaller of the three:" << endl;
	cout << "Enter value 1: ";
	cin >> value1;
	cout << "Enter value 2: ";
	cin >> value2;
	cout << "Enter value 3: ";
	cin >> value3;
	if (Smaller(value1, value2, value3) == 0)
	{
		cout << "The numbers are all the same!" << endl;
	}
	else
	{
		cout << "The smallest number is: " << Smaller(value1, value2, value3) << endl;
	}

}
// Functions Exercise 4
float Half(float number)
{
	float result = 0;
	result = number / 2;
	return result;
}
void FunctionsEx4()
{
	float number = 16.721f;
	float result = Half(number);
	cout << "Half of 16.721 is: " << result << endl;
}
// Functions Exercise 5
int CoinToss()
{
	int coin = rand();
	int tossResult = 0;
	if (coin % 2 == 0)
	{
		return tossResult = 1; //heads
	}
	else
	{
		return tossResult = 0; //tails
	}
}
void FunctionsEx5()
{
	int coinTosses = 0;
	cout << "--   COIN TOSS !!!   ---" << endl;
	cout << "Please enter the number of times you would like the coin tossed:" << endl;
	cin >> coinTosses;
	for (int i = 0; i <= coinTosses; i++)
	{
		if (CoinToss() == 1)
		{
			cout << "heads" << endl;
		}
		else
		{
			cout << "tails" << endl;
		}
	}

}

// Exercise 7
int SumTo(int number)
{
	int total = 0;
	for (int i = 1; i <= number; i++)
	{
		total = i + total;
	}
	return total;
}
void FunctionsEx7()
{
	int result = SumTo(3);
	cout << result << endl;

	result = SumTo(15);
	cout << result << endl;
}
// Exercise 8
int SumArray(int array[], int size)
{
	int result = 0;
	for (int i = 0; i < size; i++)
	{
		result += array[i];
	}
	return result;
}

void FunctionsEx8()
{
	int integer_array[5] = { 7, 3, 2, 4, 9 };
	int result = SumArray(integer_array, 5); //result = 25
	cout << result << endl;
}

// Exercise 9
int MinInArray(int array[], int size)
{
	int result = 0;
	for (int i = 0; i < size; i++)
	{
		if ((result != 0) && (array[i] < result))
		{
			result = array[i];
		}
		else if ((result != 0) && (array[i] > result))
		{
			continue;
		}
		else
		{
			result = array[i];
		}
	}
	return result;
}

void FunctionsEx9()
{
	int integer_array[7] = { 10, 15, 7, 4, 13, 19, 8 };
	int result = MinInArray(integer_array, 7); //result = 4
	cout << result << endl;

}
// Exercise 10
void MultiplyByIndex(int intArray[], int outArray[], int size)
{
		
	for (int i = 0; i < size; i++)
	{
		outArray[i] = (intArray[i] * i);
	}
	//return outArray;
}
void FunctionsEx10()
{
	int integer_array[7] = { 10, 15, 7, 4, 13, 19, 8 };
	int output_array[7] = {};
	MultiplyByIndex(integer_array, output_array, 7);
	//output_array should be {0, 15, 14, 12, 52, 95, 48};
	for (int i = 0; i < 7; i++)
	{
		cout << output_array[i] << endl;
	}
}
// Exercise 11
void MultiplyByIndex(int intArray1[], int intArray2[], int outArray[], int size)
{

	for (int i = 0; i < size; i++)
	{

		outArray[i] = (intArray1[i] + intArray2[i]);
	}
	//return outArray;
}

void FunctionsEx11()
{
	int integer_array1[7] = { 10, 15, 7, 4, 13, 19, 8 };
	int integer_array2[7] = { 10, 15, 7, 4, 13, 19, 8 };
	int output_array[7] = {};
	MultiplyByIndex(integer_array1, integer_array2, output_array, 7);
	//output_array should be {20, 30, 14, 8, 26, 38, 16};
	for (int i = 0; i < 7; i++)
	{
		cout << output_array[i] << endl;
	}
}

// Exercise 12
void RunningSumArray(int array[], int size)
{
	int last = 0;
	for (int i = 0; i < size; i++)
	{
		array[i] += array[last];
		last = i;
	}
}

void FunctionsEx12()
{
	int integer_array1[7] = { 10, 15, 7, 4, 13, 19, 8 };
	RunningSumArray(integer_array1, 7);
	//integer_array1 should be {10, 25, 32, 36, 49, 78, 86};
	for (int i = 0; i < 7; i++)
	{
		cout << integer_array1[i] << endl;
	}
}

// Exercise 13
int ReturnIndex(int array[], int size, int findNum)
{
	int numIndex = 0;
	int sizeIndex = size -1;
	for (int i = 0; i < size; i++)
	{
		if (array[i] == findNum)
		{
			numIndex = i;
		}
		else if (i == sizeIndex)
		{
			numIndex = -1;
		}
		else
		{
			continue;
		}
	}
	return numIndex;
}

void FunctionsEx13()
{
	int integer_array1[7] = { 10, 15, 7, 4, 13, 19, 8 };
	int findNum = 0;
	cin >> findNum;
	cout << ReturnIndex(integer_array1, 7, findNum) << endl;
}

// Exercise 14
int Split(int intArray1[], int outArray1[], int outArray2[], int size)
{
	int numIndex = 0;
	int outIndex1 = 0;
	int outIndex2 = 0;
	for (int i = 0; i < size; i++)
	{
		if ((intArray1[i] % 2) == 0)
		{
			outArray1[outIndex1] = intArray1[i];
			outIndex1++;
		}
		else
		{
			outArray2[outIndex2] = intArray1[i];
			outIndex2++;
		}
	}
	return outIndex1;
}
void FunctionsEx14()
{
	int integer_array1[7] = { 10, 15, 7, 4, 13, 19, 8 };
	int output_array1[7] = {};
	int output_array2[7] = {};
	// answer should be 3
	cout << Split(integer_array1, output_array1, output_array2, 7) << endl;
}

// Exercise 15
int PowerOf(int x, int y)
{
	int result = x;
	for (int i = 1; i < y; i++)
	{
		result = result * x;
	}
	return result;
}

void FunctionsEx15()
{
	int numX = 2;
	int numY = 5;
	// answer should be 32
	cout << PowerOf(numX, numY) << endl;
}

// Exercise 16
void CountSame(int array[], int size)
{
	int temp = 0;
	int count = 0;
	int num = 0;
	for (int i = 0; i < size; i++)
	{
		num = array[i];
		if ((count > 0) && (array[i] != temp) && (i != (size -1)))
		{
			cout << count << "," << temp << endl;
			temp = array[i];
			count = 1;
		}
		else if ((count > 0) && (array[i] == temp) && (i != (size - 1)))
		{
			count++;
		}
		else if ((count > 0) && (array[i] != temp) && (i == (size - 1)))
		{
			cout << count << "," << temp << endl;
			temp = array[i];
			count = 1;
			cout << count << "," << temp << endl;
		}
		else if ((count > 0) && (array[i] == temp) && (i == (size - 1)))
		{
			count++;
			cout << count << "," << temp << endl;
		}
		else //new number
		{
			temp = array[i];
			count++;
		}
	}
	

	// destructive result, returns count of sme elements in the array but zero's each to not repeat
	//for (int i = 0; i < size; i++)
	//{
	//	if (array[i] != 0)
	//	{
	//		int count = 0;
	//		int num = array[i];
	//		cout << array[i] << " count = ";
	//		for (int n = 0; n < size; n++)
	//		{
	//			if (num == array[n])
	//			{
	//				count++;
	//				array[n] = 0;
	//			}
	//			else
	//			{
	//				continue;
	//			}
	//		}
	//		cout << count << endl;
	//	}
	//}

}

void FunctionsEx16()
{
	int integer_array1[4] = { 1, 1, 1, 1 }; // 4, 1's
	int integer_array2[6] = { 1, 2, 2, 2, 3, 4 }; // 1,1 - 3,2 - 1,3 - 1,4
	int integer_array3[19] = { 1,2,2,1,5,1,1,7,7,7,7,1,1,1,1,1,1,1,1 }; // 1,1,2,2,1,1,1,5,2,1,4,7,8,1
	cout << "one" << endl;
	CountSame(integer_array1, 4);
	cout << "two" << endl;
	CountSame(integer_array2, 6);
	cout << "three" << endl;
	CountSame(integer_array3, 19);
}

// Exercise 17

// generate random number 1-3
// 1 == rock, 2 == paper, 3 == scissors

// user enters choice rock paper scissors
// display computers choice

// rock beats scissors
// scissors beats paper
// paper beats rock

// if there is a tie repeat
void Compare(int comp, int human)
{
	if (comp == human)
	{
		cout << "Draw !! Play Again" << endl;
		Game();
	}
	else if ((comp == 1 && human == 3) || (comp == 2 && human == 1) || (comp == 2 && human == 1))
	{
		cout << "Computer Wins" << endl;
	}
	else
	{
		cout << "Human Wins" << endl;
	}

}

int ConvertHuman(char human[])
{
	if (strcmp(human, "rock"))
	{
		return 1;
	}
	else if (strcmp(human, "paper"))
	{
		return 2;
	}
	else if (strcmp(human, "scissors"))
	{
		return 3;
	}
	else
	{
		return 0;
	}
}

void Game()
{
	char compChoice[10];
	char human[10];
	int humanInt;
	char rock[] = "rock";
	char paper[] = "paper";
	char scissors[] = "scissors";
	char error[] = "error";
	int computer = rand() % 3 + 1;
	switch (computer)
	{
	case 1:
		strcpy_s(compChoice, rock);
		break;
	case 2:
		strcpy_s(compChoice, paper);
		break;
	case 3:
		strcpy_s(compChoice, scissors);
		break;
	default:
		strcpy_s(compChoice, error);
		break;
	}
	cout << "Rock, Paper or Scissors?" << endl;
	cin >> human;
	cout << "Computer says - " << compChoice << " " << computer << endl;
	humanInt = ConvertHuman(human);
	Compare(computer, humanInt);
}

void FunctionsEx17()
{
	Game();
}
