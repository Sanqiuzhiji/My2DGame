#include "../include/player.h"

player::player(IMAGE* img, std::string _name, int x, int y):OBJECT(img, _name, x, y)
{
	/*player_image.imageload(path);*/
	std::cout << "Player created" << std::endl;
}

player::~player()
{

}

