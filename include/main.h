#ifndef __MAIN_H__
#define __MAIN_H__
#include <windows.h>
#include "mainpage.h"
#include "startpage.h"
#include "IMAGE_PR.h"
#include "window.h"
#include "graphics.h"
#include "iostream"
#include <conio.h>     


// 获取屏幕的宽度和高度设置窗口大小
const int windowWidth = static_cast<int>(GetSystemMetrics(SM_CXSCREEN) * 0.8);
const int windowHeight = static_cast<int>(GetSystemMetrics(SM_CYSCREEN) * 0.8);


#endif 