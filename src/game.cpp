#include "../include/game.h"


Game::Game(int windowWidth, int windowHeight) : 
    window(new Window(windowWidth, windowHeight)),
    resource(new Resource())
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
    MyIMAGE DF(_T("..\resources\images\daifu"), 180, 50, "df");
    Resource *res = new Resource();
    res->addimage(&DF);
    std::cout << "��Ϸ��ʼ�����" << std::endl;
}

void Game::Run() {

    while (window->IsOpen()) 
    {  // ������Ϸѭ��
        window->ProcessEvents();  // �����¼�
        renderer->Clear();        // ����
        renderer->DrawImage("startpage", 100, 100);  // ��ȾͼƬ
        renderer->Display();      // ��ʾ��Ⱦ���
    }

}
