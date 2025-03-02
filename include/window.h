#pragma once
#ifndef __WINDOW_H__
#define __WINDOW_H__

#include "main.h"
#include "IMAGE_PR.h"

class IMAGE_PR;  //���ǰ�����������߱�������������

class Window {
private:
	HWND hwnd;              // ���ھ��
	bool isFullScreen;      // ��Ǵ����Ƿ���ȫ��ģʽ
	WNDCLASS wc;            // ������ṹ
	RECT originalRect; // ���洰�ڵ�ԭʼλ�úʹ�С

public:
	Window(int Width, int Height, int X, int Y, bool isfullscreen = false);
	~Window();  // ��������

	bool InitWindow(int width, int height);  // ��ʼ������
	void ToggleFullScreen();  // �л�ȫ��ģʽ
	void RunMessageLoop();  // ������Ϣѭ��

	static LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);  // ��̬��Ϣ������
	void SetUserData();  // ���ô��ڵ��û����ݣ�ָ��ǰ����

	void DrawImg(const IMAGE_PR Myimg, int X, int Y);
private:
	LRESULT HandleMessages(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);  // ��Ϣ������
};

#endif	
