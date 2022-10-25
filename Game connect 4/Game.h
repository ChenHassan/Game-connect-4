#pragma once
using namespace std;

#include "Board.h"
#include <iostream>
#include "GameType.h"
class Game
{
public:
	Game();
	void StartGame();

private:
	Board board;
	GameType* gameType;
};

