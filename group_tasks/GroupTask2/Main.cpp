#include <iostream>
#include <string>

using namespace std;


char AskUser()
{
	char letter;
	cout << "Guess a letter: ";
	cin >> letter;
	return letter;
}

bool CheckWord(char word[], char guess)
{
	int length = strlen(word);
	for (int i = 0; i < length; i++)
	{
		if (word[i] == guess)
		{
			cout << word[i] << "," << guess << endl;
			return true;
		}
	}
	return false;
}

void PlaceChar(char word[], char correctGuesses[], char guess)
{
	int length = strlen(word);
	int location = 0;
	for (int i = 0; i < length; i++)
	{
		if (word[i] == guess)
		{
			correctGuesses[i] = word[i];
		}
	}
}

void PrintGuessed(char correctGuess[])
{
	int length = strlen(correctGuess);
	int guess = 0;
	for (int i = 0; i < length; i++)
	{
		guess = correctGuess[i];
		if (CheckWord(correctGuess, guess))
		{
			cout << correctGuess[i];
		}
		else
		{
			cout << "_ ";
		}
	}
	cout << endl;
}

void PrintUnderscores(char word[], char correctGuesses[])
{
	for (int i = 0; i < strlen(word); i++)
	{
		//cout << correctGuesses[i] << " - print under scores" << endl;
		if (CheckWord(correctGuesses, word[i]))
		{
			cout << word[i];
		}
		else
		{
			cout << '_';
		}
	}
}

int main()
{
	//
	char word[10] = "something";
	char wrongGuesses[20] = "";
	char correctGuess[10] = "";
	char guess;
	int wrongGuessCount = 0;

	while (true)
	{
		guess = AskUser();
		

		if (CheckWord(word, guess))
		{
			cout << " correct letter" << endl;
			PlaceChar(word, correctGuess, guess);
		}
		else
		{
			cout << "wrong guess" << endl;
			wrongGuessCount++;
			wrongGuesses[wrongGuessCount] = guess;
		}
		//PrintGuessed(correctGuess);
		PrintUnderscores(word, correctGuess);
		cout << ' ' << endl;
	}

	return 0;
}