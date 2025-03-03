#pragma once
#include "graphics.h"
#include <filesystem>
#include <string>
#include <map>
#include "main.h"

class MyIMAGE
{

public:
	MyIMAGE(const TCHAR* path, int IMAGE_WIDTH, int IMAGE_HEIGHT, std::string name);
	~MyIMAGE();
	IMAGE* MyImageSet[8];
	std::string name;
};

