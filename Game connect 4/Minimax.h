#pragma once
#include "Board.h"
#include "MinimaxData.h"

#define min(a,b) (((a) < (b)) ? (a) : (b))
#define max(a,b) (((a) > (b)) ? (a) : (b))

class Minimax
{
public:
	Minimax();
	MinimaxData MinimaxFunc(Board b, unsigned int depth, unsigned int p);
	//array<int, 2> MinimaxFunc(Board b, unsigned int depth, unsigned int p);
	bool isWinning(Board board, Status activePlayer);
	int ScoreScope(int v[4], unsigned int p);
	int ScoreAllNextPossibleOptions(Board b, unsigned int p);
	int heurFunction(unsigned int g, unsigned int b, unsigned int z);
};

