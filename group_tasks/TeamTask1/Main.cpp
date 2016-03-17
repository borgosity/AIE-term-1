#include <iostream>

int DoNumbersMatch(int num1, int num2);
int GuessHint(int num, int guess);
void Player1();
void Player2(int number);

using namespace std;

//guess a number
//max 10 guesses
//0 - 1000
//use functions
//bonus - have all input not break things(mash keyboard doesn't break things)

int main()
{
	cout << "Hi Player 1, enter a number  between 0 and 1000 for Player 2 to guess: ";
	Player1();
}

int DoNumbersMatch(int num1, int num2)
{
	int result = 0;
	if (num1 == num2)
	{
		result = 1; //true
		return result;
	}
	else
	{
		return result; //false
	}
}

int GuessHint(int num, int guess)
{
	int result = 0;
	if (guess > num)
	{
		result = 1; 
		cout << "Lower !";
		return result; //lower
	}
	else
	{
		cout << "Higher !";
		return result; //higher
	}
}

void Player1()
{
	int numberToGuess = 0;
	cin >> numberToGuess;
	if ((numberToGuess > 1000) || (numberToGuess < 0))
	{
		cout << "Number was out of range!! Please choose a number between 0 and 1000" << endl;
		cin >> numberToGuess;
		Player1();
	}
	else
	{
		Player2(numberToGuess);
	}
}

void Player2(int number)
{
	int guessedNum = 0;
	cout << "Hi Player 2, you get 10 turns to guess the number Player 1 entered." << endl;
	for (int i = 0; i < 10; i++)
	{
		cout << "Guess number " << i << " :";
		cin >> guessedNum;
		if (DoNumbersMatch(number, guessedNum) == 1)
		{
			cout << "### WINNER!! ###" << endl;
			break;
		}
		else
		{
			GuessHint(number, guessedNum);
		}
	}
}

