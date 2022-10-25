#include "Minimax.h"
#include "Board.h"
#include <array>


Minimax::Minimax()
{
}

bool Minimax::isWinning(Board board, Status activePlayer)
{
	for (int row = MAX_ROW - 1; row >= 0; row--)
	{
		for (int coulmn = 0; coulmn < MAX_COULMN; coulmn++)
		{
			if (board.GetValue(row, coulmn) == activePlayer &&
				board.GetValue(row - 1, coulmn - 1) == activePlayer &&
				board.GetValue(row - 2, coulmn - 2) == activePlayer &&
				board.GetValue(row - 3, coulmn - 3) == activePlayer)
			{
				return true;
			}


			if (board.GetValue(row, coulmn) == activePlayer &&
				board.GetValue(row, coulmn - 1) == activePlayer &&
				board.GetValue(row, coulmn - 2) == activePlayer &&
				board.GetValue(row, coulmn - 3) == activePlayer)
			{
				return true;
			}

			if (board.GetValue(row, coulmn) == activePlayer &&
				board.GetValue(row - 1, coulmn) == activePlayer &&
				board.GetValue(row - 2, coulmn) == activePlayer &&
				board.GetValue(row - 3, coulmn) == activePlayer)
			{
				return true;
			}

			if (board.GetValue(row, coulmn) == activePlayer &&
				board.GetValue(row - 1, coulmn + 1) == activePlayer &&
				board.GetValue(row - 2, coulmn + 2) == activePlayer &&
				board.GetValue(row - 3, coulmn + 3) == activePlayer)
			{
				return true;
			}

			if (board.GetValue(row, coulmn) == activePlayer &&
				board.GetValue(row, coulmn + 1) == activePlayer &&
				board.GetValue(row, coulmn + 2) == activePlayer &&
				board.GetValue(row, coulmn + 3) == activePlayer)
			{
				return true;
			}
		}

	}
	return false;
}

// GetColumn of minimax
MinimaxData Minimax::MinimaxFunc(Board board, unsigned int depth, unsigned int p) {

	if (depth == 0)
	{
		return MinimaxData(-1, ScoreAllNextPossibleOptions(board, PLAYER2));
	}
	// if Computer turn
	if (p == PLAYER2)
	{
		MinimaxData moveSoFar(-1, INT_MIN);
		if (isWinning(board, PLAYER1)) {
			return moveSoFar;
		}

		for (unsigned int c = 0; c < MAX_COULMN; c++)
		{
			if (board.GetValue(0, c) == 0)
			{
				Board newBoard = board.copyBoard(); // make a copy of the board
				for (unsigned int r = MAX_ROW - 1; r >= 0; r--)
				{
					if (newBoard.GetValue(r, c) == 0)
					{
						newBoard.SetValue(r, c, p == 1 ? PLAYER1 : PLAYER2);
						break;
					}
				}
				int score = MinimaxFunc(newBoard, depth - 1, PLAYER1).getScore();
				if (score > moveSoFar.getScore())
				{
					moveSoFar.SetScore(score);
					moveSoFar.SetCoulmn(c);
				}
			}
		}
		return moveSoFar;
	}
	else
	{
		MinimaxData moveSoFar(-1, INT_MAX);
		if (isWinning(board, PLAYER2))
		{
			return moveSoFar;
		}
		for (unsigned int c = 0; c < MAX_COULMN; c++)
		{
			if (board.GetValue(0, c) == 0) {
				Board newBoard = board.copyBoard();
				for (unsigned int r = MAX_ROW - 1; r >= 0; r--) {
					if (newBoard.GetValue(r, c) == 0)
					{
						newBoard.SetValue(r, c, p == 1 ? PLAYER1 : PLAYER2); // set piece
						break;
					}
				}
				int score = MinimaxFunc(newBoard, depth - 1, PLAYER2).getScore();
				if (score < moveSoFar.getScore())
				{
					moveSoFar.SetScore(score);
					moveSoFar.SetCoulmn(c);
				}
			}
		}
		return moveSoFar;
	}
}
int Minimax::ScoreScope(int v[4], unsigned int p) {
	unsigned int good = 0;
	unsigned int bad = 0;
	unsigned int empty = 0;
	for (unsigned int i = 0; i < 4; i++)
	{
		good += (v[i] == p) ? 1 : 0;
		bad += (v[i] == PLAYER1 || v[i] == PLAYER2) ? 1 : 0;
		empty += (v[i] == 0) ? 1 : 0;
	}
	// bad was calculated as (bad + good), so remove good
	bad -= good;
	return heurFunction(good, bad, empty);
}

int Minimax::ScoreAllNextPossibleOptions(Board b, unsigned int p)
{
	int score = 0;
	int rs[MAX_COULMN];
	int cs[MAX_ROW];
	int set[4];

	/**
	 * horizontal checks, we're looking for sequences of 4
	 * containing any combination of AI, PLAYER, and empty pieces
	 */
	for (unsigned int r = 0; r < MAX_ROW; r++) {
		for (unsigned int c = 0; c < MAX_COULMN; c++) {
			rs[c] = b.GetValue(r, c); // this is a distinct row alone
		}
		for (unsigned int c = 0; c < MAX_COULMN - 3; c++) {
			for (int i = 0; i < 4; i++) {
				set[i] = rs[c + i]; // for each possible "set" of 4 spots from that row
			}
			score += ScoreScope(set, p); // find score
		}
	}
	// vertical
	for (unsigned int c = 0; c < MAX_COULMN; c++) {
		for (unsigned int r = 0; r < MAX_ROW; r++) {
			cs[r] = b.GetValue(r, c);
		}
		for (unsigned int r = 0; r < MAX_ROW - 3; r++) {
			for (int i = 0; i < 4; i++) {
				set[i] = cs[r + i];
			}
			score += ScoreScope(set, p);
		}
	}
	// diagonals
	for (unsigned int r = 0; r < MAX_ROW - 3; r++) {
		for (unsigned int c = 0; c < MAX_COULMN; c++) {
			rs[c] = b.GetValue(r, c);
		}
		for (unsigned int c = 0; c < MAX_COULMN - 3; c++) {
			for (int i = 0; i < 4; i++) {
				set[i] = b.GetValue(r + i, c + i);
			}
			score += ScoreScope(set, p);
		}
	}
	for (unsigned int r = 0; r < MAX_ROW - 3; r++) {
		for (unsigned int c = 0; c < MAX_COULMN; c++) {
			rs[c] = b.GetValue(r, c);
		}
		for (unsigned int c = 0; c < MAX_COULMN - 3; c++) {
			for (int i = 0; i < 4; i++) {
				set[i] = b.GetValue(r + 3 - i, c + i);
			}
			score += ScoreScope(set, p);
		}
	}
	return score;
}

int Minimax::heurFunction(unsigned int g, unsigned int b, unsigned int z) {
	int score = 0;
	if (g == 4) { score += 100001; } // preference to go for winning move vs. block
	else if (g == 3 && z == 1) { score += 1000; }
	else if (g == 2 && z == 2) { score += 100; }
	else if (b == 2 && z == 2) { score -= 101; } // preference to block
	else if (b == 3 && z == 1) { score -= 1001; } // preference to block
	else if (b == 4) { score -= 100000; }
	return score;
}
