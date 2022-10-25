#pragma once
using namespace std;
#include <iostream>
#define MAX_ROW 6
#define MAX_COULMN 7

enum Status
{
	NONE,
	PLAYER1,
	PLAYER2
};
class Board
{
public:
	Board();
	void   buildboard();
	void   PrintBoard();
	Status GetValue(int row, int coulmn);
	void   SetValue(int row, int coulmn, Status status);
	Board  copyBoard();
private:
	Status boardgame[MAX_ROW][MAX_COULMN];
};

