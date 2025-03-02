#pragma once

#include "IMAGE_PR.h"

class player
{
public:
	player(const TCHAR* path);
	~player();

public:
	int map_positionX;
	int map_positionY;

	IMAGE_PR player_image;
};


