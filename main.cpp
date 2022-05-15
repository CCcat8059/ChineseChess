#include "GameManager.h"
#include "Button.h"


int main()
{
	// test cccat
	GameManager game;

	while (game.isRunning())
	{
		game.update();
		game.render();
	}
	return EXIT_SUCCESS;
}

