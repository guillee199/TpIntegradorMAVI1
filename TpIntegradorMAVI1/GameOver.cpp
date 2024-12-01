#include "GameOver.h"

GameOver::GameOver(RenderWindow* App, int score) : App(App), score(score) {}
GameOver::GameOver() : App(nullptr), score(0) {}
void GameOver::cargarAssets() {
    backgroundT.loadFromFile("./assets/gfondo.jpg");
    background.setTexture(backgroundT);
    gameOverT.loadFromFile("./assets/gameover.png");
    gameOver.setTexture(gameOverT);
    gameOver.setPosition(0, 0);

    font.loadFromFile("./font/Unispace Rg.otf");

    scoreText.setFont(font);
    scoreText.setCharacterSize(30);
    scoreText.setFillColor(Color::White);
    scoreText.setString("Puntaje final: " + to_string(score));
    scoreText.setPosition(180, 200);
}

void GameOver::run() {
    while (App->isOpen()) {
        Event event;
        while (App->pollEvent(event)) {
            switch (event.type) {
            case Event::Closed:
                App->close();
                break;
            }
            if (event.type == Event::KeyPressed && event.key.code == Keyboard::Escape) {
                App->close();
            }
        }
        App->clear();
        App->draw(background);
        App->draw(gameOver);
        App->draw(scoreText);
        App->display();
    }
}