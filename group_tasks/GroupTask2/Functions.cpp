//#include <iostream>
//#include <string>
//#include "Functions.h"
//
//
//using namespace std;
//
//
//char AskUser()
//{
//	char letter;
//	cout << "Guess a letter: ";
//	cin >> letter;
//	return letter;
//}
//
//bool CheckWord(char word[], char guess)
//{
//	int length = strlen(word);
//	for (int i = 0; i < length; i++)
//	{
//		if (word[i] == guess)
//		{
//			return true;
//		}
//	}
//	return false;
//}
//
//void PlaceChar(char word[], char correctGuesses[], char guess)
//{
//	int length = strlen(word);
//	int location = 0;
//	for (int i = 0; i < length; i++)
//	{
//		if (word[i] == guess)
//		{
//			correctGuesses[i] = word[i];
//		}
//	}
//}
//
//void PrintGuessed(char correctGuess[])
//{
//	int length = strlen(correctGuess);
//	for (int i = 0; i < length; i++)
//	{
//		if (correctGuess[i] == 0)
//		{
//			cout << "_ ";
//		}
//		else
//		{
//			cout << correctGuess[i];
//		}
//	}
//}
