#pragma once
#include "MentalChallenge.h"
#include "StringOO.h"

class Question :
	public MentalChallenge
{
public:
	Question(StringOO & Question, StringOO & Answer);
	virtual ~Question();
	virtual StringOO GetQuestion();
	virtual StringOO GetAnswer();
private:
	StringOO m_Question;
	StringOO m_Answer;
};

