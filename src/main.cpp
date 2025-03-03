#include "../include/main.h"
int main()
{ 
    Game game(800, 600);
    game.Init();
    game.Run();
    std::cout << "Game Over" << std::endl;
    while (true) {};
    closegraph();
    return 0;
}
