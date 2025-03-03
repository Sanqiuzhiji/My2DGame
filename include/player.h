#pragma once

#include "OBJECT.h"
class player: public OBJECT
{

public:
	player(IMAGE* img, std::string _name, int x, int y);
	~player();
	int player_health;

};

