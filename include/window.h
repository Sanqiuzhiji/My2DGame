#pragma once
#ifndef __WINDOW_H__
#define __WINDOW_H__

#include "main.h"
#include "IMAGE_PR.h"

class IMAGE_PR;  //添加前置声明，告诉编译器这个类存在

class Window {
public:
    bool isFullscreen; // 标记当前是否处于全屏模式
    RECT originalRect; // 保存窗口的原始位置和大小
    HWND name;

    Window(int Width,int Height,int X,int Y,bool isfullscreen=false );
    void DrawImg(const IMAGE_PR Myimg, int X, int Y);
    // 切换全屏模式的函数
    void ToggleFullscreen();
    // 获取当前全屏状态
    bool IsFullscreen();
};

#endif 





