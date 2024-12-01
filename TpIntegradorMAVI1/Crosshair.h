#pragma once
#include "lib.h"
#ifndef CROSSHAIR_H
#define CROSSHAIR_H

class Crosshair {
public:
    Crosshair();
    void cargarAssets();
    void update(Vector2f mousePosition);
    void draw(RenderWindow& App);
    void reduceLife();
    int getLives() const;
private:
    Sprite crossSprite;
    Texture crossTexture;
    int vidas;
};
#endif
