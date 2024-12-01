#pragma once
#include "lib.h"
#ifndef INOCENT_H
#define INOCENT_H



class Inocent {
public:
    Inocent(const std::string& textureFile);
    void draw(RenderWindow& App);
    void respawn();
    bool isClicked(const Vector2f& point);
private:
    Sprite InocentSprite;
    Texture InocentTexture;
    vector<int> CoordX = { 207,420,110,285,466 };
    vector<int> CoordY = { 160,160,335,343,335 };
};

#endif
