#pragma once
#ifndef __WINDOW_H__
#define __WINDOW_H__

#include "main.h"
#include "IMAGE_PR.h"

class IMAGE_PR;  //���ǰ�����������߱�������������

class Window {
public:
    bool isFullscreen; // ��ǵ�ǰ�Ƿ���ȫ��ģʽ
    RECT originalRect; // ���洰�ڵ�ԭʼλ�úʹ�С
    HWND name;

    Window(int Width,int Height,int X,int Y,bool isfullscreen=false );
    void DrawImg(const IMAGE_PR Myimg, int X, int Y);
    // �л�ȫ��ģʽ�ĺ���
    void ToggleFullscreen();
    // ��ȡ��ǰȫ��״̬
    bool IsFullscreen();
};

#endif 





