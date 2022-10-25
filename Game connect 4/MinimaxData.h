#pragma once
class MinimaxData
{
private:
	int score;
	int coulmn;

public:
	MinimaxData(int coulmn, int score);
	int getScore();
	int getCoulmn();
	void SetScore(int score);
	void SetCoulmn(int coulmn);
};

