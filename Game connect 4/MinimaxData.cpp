#include "MinimaxData.h"

MinimaxData::MinimaxData(int c, int s)
	:score(s), coulmn(c)
{
}
int  MinimaxData::getScore()
{
	return this->score;
}
int  MinimaxData::getCoulmn()
{
	return this->coulmn;
}
void MinimaxData::SetScore(int score)
{
	this->score = score;
}
void MinimaxData::SetCoulmn(int coulmn)
{
	this->coulmn = coulmn;
}