#include "menu.h"
#include "lib.h"
Menu::Menu(RenderWindow* App) : App(App) {}
void Menu::cargarAssets() {

    backgroundT.loadFromFile("./assets/mfondo.jpg");
    titleT.loadFromFile("./assets/titulo.png");
    instructionT.loadFromFile("./assets/instruc.png");

    background.setTexture(backgroundT);
    title.setTexture(titleT);
    title.setPosition(100, -50);
    instruction.setTexture(instructionT);
    instruction.setPosition(10, 150);
    instruction.setScale(0.8f, 0.8f);


}

void Menu::run() {
    App->setMouseCursorVisible(false);
    while (App->isOpen()) {
        Event event;
        while (App->pollEvent(event)) {
            switch (event.type) {
            case Event::Closed:
                App->close();
                break;
            }
            if (event.type == Event::KeyPressed) {
                if (event.key.code == Keyboard::Space) {
                    return;
                }
                if (event.key.code == Keyboard::Escape) {
                    App->close();
                }
            }
        }

        App->clear();
        App->draw(background);
        App->draw(title);
        App->draw(instruction);
        App->display();
    }
}