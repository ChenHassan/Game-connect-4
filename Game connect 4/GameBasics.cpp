#include "GameBasics.h"
#include <array>

Status GameBasics::SelectStartedPlayer()
{
	srand(time(NULL));
	int indexOfStartedPlayer = rand() % 2 + 1;
	if (indexOfStartedPlayer == 1)
		return PLAYER1;
	else if (indexOfStartedPlayer == 2)
		return PLAYER2;
	return NONE;
}


bool GameBasics::isGiveUp()
{
	string choice;
	cout << "Did you want to Give Up?(yes/no) ";
	cin >> choice;
	if (!strcmp(choice.c_str(), "yes"))
	{
		return true;
	}
	return false;
}

bool GameBasics::ComputerStartedPlaying()
{
	board.PrintBoard();
	while (!GetComputerStep())
	{
		GetComputerStep();

		if (CheckWinner(PLAYER2))
		{
			board.PrintBoard();
			cout << "Computer Win!!" << endl;
			return true;
		}
	}
	board.PrintBoard();
	if (CheckWinner(PLAYER2))
	{
		board.PrintBoard();
		cout << "Computer Win!!" << endl;
		return true;
	}

	board.PrintBoard();
	while (!GetPlayerStep(PLAYER1))
	{
		GetPlayerStep(PLAYER1);
		if (CheckWinner(PLAYER1))
		{
			board.PrintBoard();
			cout << "Player1 Win!!" << endl;
			return true;
		}
	}

	board.PrintBoard();

	if (CheckWinner(PLAYER1))
	{
		board.PrintBoard();
		cout << "Player1 Win!!" << endl;
		return true;
	}
	board.PrintBoard();

	return false;
}

bool GameBasics::Player1StartedPlaying(bool isAgainstComputer)
{
	board.PrintBoard();
	while (!GetPlayerStep(PLAYER1))
	{
		GetPlayerStep(PLAYER1);

		if (CheckWinner(PLAYER1))
		{
			board.PrintBoard();
			cout << "Player1 Win!!" << endl;
			return true;
		}
	}
	board.PrintBoard();

	if (CheckWinner(PLAYER1))
	{
		board.PrintBoard();
		cout << "Player1 Win!!" << endl;
		return true;
	}
	board.PrintBoard();
	if (isAgainstComputer)
	{
		while (!GetComputerStep())
		{
			GetComputerStep();
			if (CheckWinner(PLAYER2))
			{
				board.PrintBoard();
				cout << "Computer Win!!" << endl;
				return true;
			}
		}
		board.PrintBoard();

		if (CheckWinner(PLAYER2))
		{
			board.PrintBoard();
			cout << "Computer Win!!" << endl;
			return true;
		}
	}
	else
	{
		while (!GetPlayerStep(PLAYER2))
		{
			GetPlayerStep(PLAYER2);
			if (CheckWinner(PLAYER2))
			{
				board.PrintBoard();
				cout << "Player2 Win!!" << endl;
				return true;
			}
		}
		board.PrintBoard();

		if (CheckWinner(PLAYER2))
		{
			board.PrintBoard();
			cout << "Player2 Win!!" << endl;
			return true;
		}
	}
	board.PrintBoard();

	return false;
}

bool GameBasics::Player2StartedPlaying()
{
	board.PrintBoard();
	while (!GetPlayerStep(PLAYER2))
	{
		GetPlayerStep(PLAYER2);
		if (CheckWinner(PLAYER2))
		{
			board.PrintBoard();
			cout << "Player2 Win!!" << endl;
			return true;
		}
	}

	if (CheckWinner(PLAYER2))
	{
		board.PrintBoard();
		cout << "Player Win!!" << endl;
		return true;
	}
	board.PrintBoard();

	while (!GetPlayerStep(PLAYER1))
	{
		GetPlayerStep(PLAYER1);
		if (CheckWinner(PLAYER1))
		{
			board.PrintBoard();
			cout << "Player1 Win!!" << endl;
			return true;
		}
	}

	if (CheckWinner(PLAYER1))
	{
		board.PrintBoard();
		cout << "Player1 Win!!" << endl;
		return true;
	}
	board.PrintBoard();

	return false;
}

bool GameBasics::GetPlayerStep(Status currPlayer)
{
	string choice;
	if (currPlayer == PLAYER1)
	{
		cout << "PLAYER1 Turn, ";
	}
	else if (currPlayer == PLAYER2)
	{
		cout << "PLAYER2 Turn, ";
	}

	cout << "Please Select Coulmn Number  ";
	cin >> choice;
	if (choice.size() == 1)
	{
		int ch = atoi(choice.c_str());
		for (int i = MAX_ROW - 1; i >= 0; i--)
		{
			if (board.GetValue(i, ch) == NONE)
			{
				board.SetValue(i, ch, currPlayer);
				break;
			}
		}
		return true;
	}
	return false;
}

int GameBasics::aiMove()
{
	cout << "thinking about a move..." << endl;
	return minimax.MinimaxFunc(board, 5, PLAYER2).getCoulmn();
}

bool GameBasics::GetComputerStep()
{
	int c = aiMove();
	if (c != -1)
	{
		for (unsigned int r = MAX_ROW - 1; r >= 0; r--) {

			if (board.GetValue(r, c) == 0) { // first available spot
				board.SetValue(r, c, PLAYER2); // set piece
				return true;
			}
		}
	}
	return false;
}

bool GameBasics::CheckWinner(Status activePlayer)
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
