#pragma once
#include "lib.h"
#include "Menu.h"
#include "Enemy.h"
#include "Inocent.h"
#include "Crosshair.h"
#include "GameOver.h"

#ifndef GAME_H
#define GAME_H

class Game {
public:
	Game(RenderWindow* App);
	void cargarAssets();
	void run();
private:
	RenderWindow* App;
	Texture backgroundT;
	Sprite background;
	Font font;
	Text lifeT, scoreT;
	Crosshair crosshair;
	Enemy* vaquero = nullptr;
	Inocent* vaquera = nullptr;
	float vaqueroAppearDelay = 2.0f;
	float vaqueraAppearDelay = 0.7f;


};

#endif
