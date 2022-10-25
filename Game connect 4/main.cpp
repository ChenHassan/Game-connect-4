#include <stdio.h>
#include <iostream>
#include <vector>
#include <limits.h>
#include <array>
#include <sstream>
#include "Board.h"
#include "Game.h"



using namespace std;

int main(int argc, char** argv) {
	cout << "1.start game"<<endl;
	cout << "2.exit"<<endl;
	int option;
	cin >> option;
	for (; ; )
	{


		switch (option)
		{
		case 1: {
			Game game;
			game.StartGame();
			break;
		}
		case 2: {
			return -1;
			break;
		}
		default:
			break;
		}

	}
}