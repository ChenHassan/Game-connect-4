#include "AgainstComputer.h"
using namespace std;

void AgainstComputer::RunGame()
{

	cout << "against computer!!" << endl;
	string statusGame;
	Status firstPlayer = SelectStartedPlayer();
	if ((firstPlayer) == PLAYER1)
	{
		cout << "Player Started Playing!!" << endl;
	}
	else
	{
		cout << "Computer Started Playing!!" << endl;
	}

	while (!isGiveUp())
	{
		if ((firstPlayer) == PLAYER1)
		{
			if (Player1StartedPlaying(true))
				return;
		}
		else
		{
			if (ComputerStartedPlaying())
				return;
		}
	}

}

