#include "Board.h"
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

Board::Board()
{
	buildboard();
}


void Board::buildboard() {
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			boardgame[i][j] = NONE;
		}
	}
}

void Board::PrintBoard()
{
	cout << "  0   1   2   3   4   5   6 " << endl;
	cout << "|---------------------------|" << endl;
	for (int r = 0; r < MAX_ROW; r++)
	{
		cout << "| ";
		for (int c = 0; c < 7; c++)
		{
			cout << boardgame[r][c];
			cout << " | ";
		}
		cout << endl << "|---------------------------|" << endl;
	}
}

Status Board::GetValue(int row, int coulmn)
{
	if (row >= 0 && row < MAX_ROW &&
		coulmn >= 0 && coulmn < MAX_COULMN)
		return boardgame[row][coulmn];

	return NONE;
}

void Board::SetValue(int row, int coulmn, Status status)
{
	boardgame[row][coulmn] = status;
}

Board Board::copyBoard() {
	Board newBoard;
	for (unsigned int r = 0; r < MAX_ROW; r++) {
		for (unsigned int c = 0; c < MAX_COULMN; c++) {
			newBoard.SetValue(r, c, boardgame[r][c]); // just straight copy
		}
	}
	return newBoard;
}