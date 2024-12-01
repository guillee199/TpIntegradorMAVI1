#include "lib.h"
#include "crosshair.h"

Crosshair::Crosshair() : vidas(3) {}

void Crosshair::cargarAssets()
{
    crossTexture.loadFromFile("./Assets/crosshair.png");
    crossSprite.setTexture(crossTexture);
    crossSprite.setScale(0.3f, 0.3f);
}


void Crosshair::update(Vector2f mousePosition)
{
    FloatRect bounds = crossSprite.getLocalBounds();
    crossSprite.setPosition(
        mousePosition.x - bounds.width * crossSprite.getScale().x / 2.0f,
        mousePosition.y - bounds.height * crossSprite.getScale().y / 2.0f
    );
}

void Crosshair::draw(RenderWindow& App)
{
    App.draw(crossSprite);
}

void Crosshair::reduceLife()
{
    if (vidas > 0) {
        vidas--;
    }
}

int Crosshair::getLives() const
{
    return vidas;
}