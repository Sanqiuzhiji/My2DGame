#pragma once
#ifndef __WINDOW_H__
#define __WINDOW_H__

#include "main.h"
#include "IMAGE_PR.h"

class IMAGE_PR;  //添加前置声明，告诉编译器这个类存在

class Window {
private:
	HWND hwnd;              // 窗口句柄
	bool isFullScreen;      // 标记窗口是否处于全屏模式
	WNDCLASS wc;            // 窗口类结构
	RECT originalRect; // 保存窗口的原始位置和大小

public:
	Window(int Width, int Height, int X, int Y, bool isfullscreen = false);
	~Window();  // 析构函数

	bool InitWindow(int width, int height);  // 初始化窗口
	void ToggleFullScreen();  // 切换全屏模式
	void RunMessageLoop();  // 运行消息循环

	static LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);  // 静态消息处理函数
	void SetUserData();  // 设置窗口的用户数据（指向当前对象）

	void DrawImg(const IMAGE_PR Myimg, int X, int Y);
private:
	LRESULT HandleMessages(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);  // 消息处理函数
};

#endif	
