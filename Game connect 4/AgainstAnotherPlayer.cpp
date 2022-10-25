#include "AgainstAnotherPlayer.h"
using namespace std;

void AgainstAnotherPlayer::RunGame() {

	cout << "against another player!!" << endl;
	string statusGame;
	Status firstPlayer = SelectStartedPlayer();
	if ((firstPlayer) == PLAYER1)
	{
		cout << "Player1 Started Playing!!" << endl;
	}
	else
	{
		cout << "Player2 Started Playing!!" << endl;
	}

	while (!isGiveUp())
	{
		if ((firstPlayer) == PLAYER1)
		{
			if (Player1StartedPlaying(false))
				return;
		}
		else
		{
			if (Player2StartedPlaying())
				return;
		}
	}
}
