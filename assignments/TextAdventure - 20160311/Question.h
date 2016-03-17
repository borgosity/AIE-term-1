#pragma once
#include "MentalChallenge.h"
#include "StringOO.h"

class Question :
	public MentalChallenge
{
public:
	Question(StringOO Question, StringOO Answer, int difficulty);
	virtual ~Question();
	const char *  GetQuestion();
	const char *  GetAnswer();
};

