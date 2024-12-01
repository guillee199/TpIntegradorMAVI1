#include "lib.h"
#include "Game.h"

int main() {
	RenderWindow App(VideoMode(640, 480), "WATCHOUT");
	Menu menu(&App);
	menu.cargarAssets();
	menu.run();
	srand(time(0));
	Game game(&App);
	game.cargarAssets();
	game.run();


	return 0;
}