#pragma once
#include <string>
#include "graphics.h"
#include "main.h"

class OBJECT
{

public:
	OBJECT(IMAGE* img ,std::string _name, int x=0, int y=0);
	~OBJECT();
	IMAGE* object_image;
	std::string name;
	int x, y;
};

