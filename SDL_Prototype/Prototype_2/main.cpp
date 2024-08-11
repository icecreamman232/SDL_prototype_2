#include <iostream>
#include "Core.h"

int main(int argc, char* arg[])
{

	Core::Game game;

	game.Initialize("Prototype", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,800,600);



	while (game.IsRunning())
	{
		game.Update();
		game.Render();
	}


	return 0;
}
