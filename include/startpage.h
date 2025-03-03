#ifndef __STARTPAGE_H__
#define __STARTPAGE_H__

#include "main.h"
#include "Resource.h"
#include "window.h"

void drawStartPage();

#define STARTBUTTON_WIDTH windowWidth/10
#define STARTBUTTON_HEIGHT STARTBUTTON_WIDTH/3
#define STARTBUTTON_X windowWidth/2
#define STARTBUTTON_Y windowHeight*4/5

//extern IMAGE_PR startpage_img;
//extern IMAGE_PR startbutton_img;

extern int windowWidth;  // 全局变量，保存程序实例句柄
extern int windowHeight;  // 全局变量，保存程序实例句柄
#endif 
