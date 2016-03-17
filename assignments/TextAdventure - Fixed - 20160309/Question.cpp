#include "Question.h"



Question::Question(StringOO & Question, StringOO & Answer)
{
	m_Question = Question;
	m_Answer = Answer;
}


Question::~Question()
{
}

StringOO Question::GetQuestion()
{
	return m_Question;
}

StringOO Question::GetAnswer()
{
	return m_Answer;
}
