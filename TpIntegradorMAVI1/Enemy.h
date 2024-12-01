#pragma once
#include "lib.h"
#ifndef ENEMY_H
#define ENEMY_H

class Enemy {
public:
    Enemy(const std::string& textureFile);
    void draw(RenderWindow& App);
    void respawn();
    bool isClicked(const Vector2f& point);
private:
    Sprite EnemySprite;
    Texture EnemyTexture;
    vector<int> CoordX = { 207,420,110,285,466 };
    vector<int> CoordY = { 160,160,335,343,335 };
};
#endif
