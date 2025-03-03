#include "../include/Renderer.h"
#include <graphics.h>

Renderer::Renderer(Window& win) : window(win) {

}


void Renderer::Clear() {
    cleardevice();
}

void Renderer::DrawImage(const std::string& name, int x, int y) {
    IMAGE* img = Resource().GetImage(name);
    if (img) {
        putimage(x, y, img);
    }
}

void Renderer::Display() {
    FlushBatchDraw();  // EasyX Ë¢ÐÂ
}
