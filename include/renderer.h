#pragma once
#ifndef RENDERER_H
#define RENDERER_H
#include <memory>
#include "Window.h"
#include "Resource.h"

class Window;

class Renderer {

public:
	Renderer(Window& win);
	Window& window;
	void Clear();
	void DrawImage(const std::string& name, int x, int y);
	void Display();
};

#endif  // RENDERER_H
