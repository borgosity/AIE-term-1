#include "ArrayEx.h"
#include <iostream>

using namespace std;

void ArrayEx2()
{
	int values[] = { 2, 6, 10, 14 };
	cout << "Arrays!!" << endl;
	cout << values[2] << endl;
	cout << ++values[0] << endl;
	cout << values[1]++ << endl;
	int x = 2;
	cout << values[++x] << endl;
	cout << values[4] << endl;
}

void ArrayEx3()
{
	int data[10] = {};
	int n = 0;
	for (int i = 9; i >= 0; i--)
	{
		n = i;
		n++;
		data[i] = n;
	}
	for (int i = 0; i < 10; i++)
	{
		cout << data[i] << endl;
	}
}

void ArrayEx4()
{
	int data[5] = {};

	for (int i = 0; i < 5; i++)
	{
		cout << "please enter a number: ";
		cin >> data[i];
	}
	cout << "in reverse order" << endl;
	for (int i = 4; i >= 0; i--)
	{
		cout << data[i] << endl;
	}
}

void ArrayEx5()
{
	int data[10] = {};
	int smallest = 0;
	int biggest = 0;

	for (int i = 0; i < 9; i++)
	{
		cout << "please enter a number: ";
		cin >> data[i];
	}
	for (int i = 0; i < 9; i++)
	{
		if (data[i] > biggest)
		{
			biggest = data[i];
		}
		if ((i == 0) || (data[i] < smallest))
		{
			smallest = data[i];
		}
	}
	cout << "smallest number is: " << smallest << endl;
	cout << "biggest number is: " << biggest << endl;
}

void ArrayEx6()
{
	int array2D[3][3] = {};

	for (int row = 0; row < 3; row++)
	{
		for (int col = 0; col < 3; col++)
		{
			int r = row;
			int c = col;
			r++;
			c++;
			int n = (r * c);
			array2D[row][col] = n;
		}
	}

	for (int row = 0; row < 3; row++)
	{
		for (int col = 0; col < 3; col++)
		{
			cout << array2D[row][col];
		}
		cout << endl;
	}


}

void ArrayEx7()
{
	int days[29][5];
	int sumRow = 0;
	int sumCol = 0;
	for (int row = 0; row < 29; row++)
	{
		for (int col = 0; col < 5; col++)
		{
			int r = row;
			int c = col;
			r++;
			c++;
			int n = (r * c);
			days[row][col] = n;
		}
	}

	for (int row = 0; row < 29; row++)
	{
		for (int col = 0; col < 5; col++)
		{
			cout << days[row][col] << ",";
		}
		cout << endl;
	}
	cout << " Sum of Cols" << endl;
	for (int col = 0; col < 5; col++)
	{
		for (int row = 0; row < 29; row++)
		{
			sumCol = sumCol + days[row][col];
		}
		cout << sumCol << endl;
		sumCol = 0;
	}
	cout << " Sum of Rows" << endl;
	for (int row = 0; row < 29; row++)
	{
		for (int col = 0; col < 5; col++)
		{
			sumRow = sumRow + days[row][col];
		}
		cout << sumRow << endl;
		sumRow = 0;
	}

	
}

void ArrayEx8()
{
	int players[5] = { 100,100,100,100,100 };

	int damage = 40;
	int health = 0;
	int selection = 0;

	for (int i = 0; i < 5; i++)
	{
		selection = AskPlayer();
		health = players[selection];
		if ((CheckHealth(health, damage) == 0) && (selection < 5))
		{
			cout << "That player has no health :(" << endl;
			selection = AskPlayer();
		}
		else if ( selection < 5)
		{
			damage = rand() % 50 + 1;
			players[selection] = Attack(health, damage);
		}
		else
		{
			cout << "No such player!!" << endl;
			selection = AskPlayer();
		}
	}

	for (int i = 0; i < 5; i++)
	{
		cout << "Player - " << i << " - health - " << players[i] << endl;
	}
	//switch (selection)
	//{
	//case(0) :
	//	break;
	//case(1) :
	//	break;
	//case(2) :
	//	break;
	//case(3) :
	//	break;
	//case(4) :
	//	break;
	//default:
	//	break;
	//}

}

int CheckHealth(int health, int damage)
{
	int result = 0;
	if (health > 0)
	{
		result = Attack(health, damage);
		return result;
	}
	else
	{
		return result;
	}
}

int Attack(int health, int damage)
{
	health -= damage;
	return health;
}

int AskPlayer()
{
	int selection = 0;
	cout << "Select a Player (0-4) to Attack: ";
	cin >> selection;
	return selection;
}

void ArrayEx9()
{
	int dragonFood[3][7] = { {1,2,3,4,5,6,7},{8,9,10,11,12,13,14 },{15,16,17,18,19,20,21} };
	//int dragonNorm[21] = {};
	int dragonNorm[21] = { 1,2,3,4,5,6,7,8,9,10,11,42,13,14,15,16,17,18,19,20,21 };
	// ask for user
	// generate report
	// - average amount per day by all
	// - average amount per dragon
	// - most food by which dragon
	// - least food by which dragon
	//for (int row = 0; row < 3; row++)
	//{
	//	int drg = row;
	//	drg++;
	//	cout << "Enter food for dragon: " << drg << endl;
	//	for (int col = 0; col < 7; col++)
	//	{
	//		int day = col;
	//		day++;
	//		cout << "- day " << day << " : ";
	//		cin >> dragonFood[row][col];
	//	}
	//}
	for (int row = 0; row < 3; row++)
	{
		int drg = row;
		drg++;
		cout << "Enter food for dragon: " << drg << endl;
		for (int col = 0; col < 7; col++)
		{
			int day = col;
			day++;
			int i = row;
			i = (i * 7) + col;
			cout << "- day " << day << " : ";
			//cin >>	dragonNorm[i]; 
			//dragonNorm[i] = i;
			cout << endl;
		}
	}
	for (int row = 0; row < 3; row++)
	{
		for (int col = 0; col < 7; col++)
		{
			int i = row;
			i = (i * 7) + col;
			cout << dragonNorm[i] << ",";
		}
		cout << endl;
	}
	AverageNorm(dragonNorm, 21);
	AverageAll(dragonFood, 3, 7);
	AverageEach(dragonNorm, 7);
	MostFood(dragonNorm, 7);
	LeastFood(dragonNorm, 7);
	cout << "Finished!! " << endl;
}
void AverageNorm(int* food, int size)
{
	int average = 0;
	for (int i = 0; i < size; i++)
	{
		average += food[i];
	}
	average /= size;
	cout << "The Average food consumed for all dragons for the week is: " << average << endl;
}
void AverageAll(int food[][7], int row, int col)
{
	int average = 0;
	for (int r = 0; r < row; r++)
	{
		for (int c = 0; c < col; c++)
		{
			average += food[r][c];
		}
	}
	average /= (row * col);
	cout << "The Average food consumed for all dragons for the week is: " << average << endl;
}
void AverageEach(int* food, int days)
{
	int average = 0;
	for (int row = 0; row < 3; row++)
	{
		for (int col = 0; col < 7; col++)
		{
			int i = row;
			i = (i * 7) + col;
			average += food[i];
		}
		average /= days;
		cout << "The Average food consumed for dragon for the week is: " << average << endl;
	}
}

void MostFood(int* food, int days)
{
	int most = 0;
	for (int row = 0; row < 3; row++)
	{
		for (int col = 0; col < 7; col++)
		{
			int i = row;
			i = (i * 7) + col;
			if (most < food[i])
			{
				most = food[i];
			}
			else
			{
				continue;
			}
		}
	}
	cout << "The most food consumed by a dragon for the week is: " << most << endl;
}

void LeastFood(int* food, int days)
{
	int least = 0;
	for (int row = 0; row < 3; row++)
	{
		for (int col = 0; col < 7; col++)
		{
			int i = row;
			i = (i * 7) + col;
			if (least > food[i] || least == 0)
			{
				least = food[i];
			}
			else
			{
				continue;
			}
		}
	}
	cout << "The least food consumed by a dragon for the week is: " << least << endl;
}



