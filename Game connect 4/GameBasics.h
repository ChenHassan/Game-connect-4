#pragma once
#include <iostream>
#include "string.h"
#include "Board.h"
#include "Minimax.h"

using namespace std;

class GameBasics
{
public:
	bool isGiveUp();
	bool ComputerStartedPlaying();
	bool Player1StartedPlaying(bool isAgainstComputer);
	bool Player2StartedPlaying();
	bool GetPlayerStep(Status currPlayer);
	bool GetComputerStep();
	Status SelectStartedPlayer();
	bool CheckWinner(Status activePlayer);

	int aiMove();
private:
	Board board;
	Minimax minimax;
};

