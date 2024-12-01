#include "lib.h"
#include "Enemy.h"


Enemy::Enemy(const std::string& textureFile) {
    EnemyTexture.loadFromFile(textureFile);
    EnemySprite.setTexture(EnemyTexture);
    EnemySprite.setScale(1, 1);
    respawn();
}
void Enemy::draw(RenderWindow& App) {
    App.draw(EnemySprite);
}
void Enemy::respawn() {
    int pos = rand() % 5 + 1;
    EnemySprite.setPosition(CoordX[pos - 1], CoordY[pos - 1]);
}

bool Enemy::isClicked(const Vector2f& point) {
    return EnemySprite.getGlobalBounds().contains(point);
}