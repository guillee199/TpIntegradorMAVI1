#include "lib.h"
#include "Inocent.h"

Inocent::Inocent(const std::string& textureFile) {
    InocentTexture.loadFromFile(textureFile);
    InocentSprite.setTexture(InocentTexture);
    InocentSprite.setScale(1, 1);
    respawn();
}
void Inocent::draw(RenderWindow& App) {
    App.draw(InocentSprite);
}
void Inocent::respawn() {
    int pos = rand() % 5 + 1;
    InocentSprite.setPosition(CoordX[pos - 1], CoordY[pos - 1]);
}

bool Inocent::isClicked(const Vector2f& point) {
    return InocentSprite.getGlobalBounds().contains(point);
}