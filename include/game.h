#pragma once
#ifndef GAME_H
#define GAME_H
#include "main.h"
#include "window.h"
#include "resource.h"
#include "renderer.h"
// ÓÎÏ·Ö÷Àà
class Window;
class Resource;
class Renderer;
class Game {
private:
    Window* window;
    Resource* resource;
    Renderer renderer;
public:
    Game(int windowWidth, int windowHeight);
    ~Game();

    void Init();
    void Run();


};
#endif
