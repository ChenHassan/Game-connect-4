#include "Game.h"
#include "AgainstAnotherPlayer.h"
#include "AgainstComputer.h"

Game::Game()
	:gameType(NULL)
{


}

void Game::StartGame()
{
	string player_option;
	cout << "Did you want to challenge another player?(yes or no)";
	cin >> player_option;
	if (!strcmp(player_option.c_str(), "yes"))
	{
		//Run the function that manage game against player
		gameType = new AgainstAnotherPlayer();
		gameType->RunGame();
	}
	else if (!strcmp(player_option.c_str(), "no"))
	{
		//Run the function that manage game against computer
		gameType = new AgainstComputer();
		gameType->RunGame();
	}
	else
	{
		cout << "Sorry but you choiced wrong option" << endl;
	}
}