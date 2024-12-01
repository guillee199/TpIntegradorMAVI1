#pragma once
#include "lib.h"

#ifndef MENU_H
#define MENU_H

class Menu {
public:
    Menu(RenderWindow* App);
    void cargarAssets();
    void run();

private:
    RenderWindow* App;
    Texture backgroundT, titleT, instructionT;
    Sprite background, title, instruction;
};

#endif
