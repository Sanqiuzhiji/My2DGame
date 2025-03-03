#include "../include/game.h"


Game::Game(int windowWidth, int windowHeight) : window(new Window(windowWidth, windowHeight)),renderer(*window)
{
}
Game::~Game()
{
    // �ͷ���Դ
    delete window;
    delete resource;
    delete renderer;
    std::cout << "Game ��Դ�ͷ�" << std::endl;
}
void Game::Init() {
    window->InitWindow(windowWidth, windowHeight);
    resource->LoadImage("startpage", "..\\resources\\images\\startpage.png");
    std::cout << "��Ϸ��ʼ�����" << std::endl;
}

void Game::Run() {
    while (window->IsOpen()) {  // ������Ϸѭ��
        window->ProcessEvents();  // �����¼�
        renderer->Clear();        // ����
        renderer->DrawImage("startpage", 100, 100);  // ��ȾͼƬ
        renderer->Display();      // ��ʾ��Ⱦ���
    }
}
