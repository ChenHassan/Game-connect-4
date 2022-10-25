#pragma once
#include "GameType.h"
#include "Board.h"
#include "GameBasics.h"

class AgainstComputer :public  GameType, public GameBasics {
public:
	void RunGame();


private:
	Board board;

};