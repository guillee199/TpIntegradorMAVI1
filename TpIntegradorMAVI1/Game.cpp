#include "Game.h"
#include "lib.h"

Game::Game(RenderWindow* App) : App(App) {}

void Game::cargarAssets() {
	backgroundT.loadFromFile("./assets/gfondo.jpg");
	background.setTexture(backgroundT);

	font.loadFromFile("./font/Unispace Rg.otf");

	scoreT.setFont(font);
	scoreT.setCharacterSize(24);
	scoreT.setFillColor(Color::Red);
	scoreT.setPosition(500, 10);
	scoreT.setString("Bajas: 0");

	lifeT.setFont(font);
	lifeT.setCharacterSize(24);
	lifeT.setFillColor(Color::Red);
	lifeT.setPosition(10, 10);
	lifeT.setString("Vidas: " + to_string(crosshair.getLives()));

	crosshair.cargarAssets();
	vaquero = new Enemy("./assets/enemigo.png");
	vaquera = new Inocent("./assets/inocente.png");
};

void Game::run() {
	Clock vaqueroClock;
	Clock vaqueraClock;
	int score = 0;
	int vaquerasDisparadas = 0;
	while (App->isOpen()) {
		Event event;
		while (App->pollEvent(event)) {
			if (event.type == Event::Closed) {
				App->close();
			}
			if (event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left) {
				Vector2f mousePosition = App->mapPixelToCoords(Mouse::getPosition(*App));


				if (vaquero->isClicked(mousePosition)) {
					vaquero->respawn();
					score++;
					scoreT.setString("Bajas: " + to_string(score));
					vaqueroClock.restart();
				}
				if (vaquera->isClicked(mousePosition)) {
					vaquera->respawn();
					crosshair.reduceLife();
					lifeT.setString("Vidas: " + to_string(crosshair.getLives()));
					vaquerasDisparadas++;
					vaqueroClock.restart();
				}
				if (crosshair.getLives() == 0) {
					int scoreFinal = score - (vaquerasDisparadas * 2);
					GameOver gameOver(App, scoreFinal);
					gameOver.cargarAssets();
					gameOver.run();
					return;
				}
			}

		}

		App->setMouseCursorVisible(false);
		App->clear();
		App->draw(background);
		vaquero->draw(*App);
		vaquera->draw(*App);

		if (vaqueroClock.getElapsedTime().asSeconds() > vaqueroAppearDelay) {
			vaquero->respawn();
			crosshair.reduceLife();
			lifeT.setString("Vidas: " + to_string(crosshair.getLives()));
			vaqueroClock.restart();
		}
		if (vaqueraClock.getElapsedTime().asSeconds() > vaqueraAppearDelay) {
			vaquera->respawn();
			vaqueraClock.restart();
		}
		crosshair.draw(*App);
		Vector2f mousePosition = App->mapPixelToCoords(Mouse::getPosition(*App));
		crosshair.update(mousePosition);
		App->draw(lifeT);
		App->draw(scoreT);
		App->display();
	}
};