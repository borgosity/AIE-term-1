#include "Question.h"



Question::Question(StringOO & Question, StringOO & Answer, int difficulty)
{
	m_Question = Question;
	m_Answer = Answer;
	m_difficulty = difficulty;
	m_type = "mental";
}


Question::~Question()
{
}
/*******************************************************************************************************
*
*******************************************************************************************************/
StringOO Question::GetQuestion()
{
	return m_Question.GetString();
}
/*******************************************************************************************************
*
*******************************************************************************************************/
StringOO Question::GetAnswer()
{
	return m_Answer.GetString();
}
