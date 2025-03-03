#include "../include/game.h"


Game::Game(int windowWidth, int windowHeight) : 
    window(new Window(windowWidth, windowHeight)),
    resource(new Resource())
{
}

Game::~Game()
{
    // 释放资源
    delete window;
    delete resource;
    delete renderer;
    std::cout << "Game 资源释放" << std::endl;
}

void Game::Init() {
    window->InitWindow(windowWidth, windowHeight);
    MyIMAGE DF(_T("..\resources\images\daifu"), 180, 50, "df");
    Resource *res = new Resource();
    res->addimage(&DF);
    std::cout << "游戏初始化完成" << std::endl;
}

void Game::Run() {

    while (window->IsOpen()) 
    {  // 进入游戏循环
        window->ProcessEvents();  // 处理事件
        renderer->Clear();        // 清屏
        renderer->DrawImage("startpage", 100, 100);  // 渲染图片
        renderer->Display();      // 显示渲染结果
    }

}
