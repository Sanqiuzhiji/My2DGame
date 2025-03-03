#pragma once
#ifndef __WINDOW_H__
#define __WINDOW_H__
#include <windows.h>
#include "main.h"
#include <string>
class Resource;  //���ǰ�����������߱�������������
class Window {
private:
	HWND hwnd;		
	//bool isFullScreen;      // ��Ǵ����Ƿ���ȫ��ģʽ
	//WNDCLASS wc;            // ������ṹ
	//RECT originalRect; // ���洰�ڵ�ԭʼλ�úʹ�С
	std::string title;
	//LRESULT HandleMessages(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);  // ��Ϣ������	
	int width,height;  // ��Ļ�ֱ���
public:

	Window(int Width, int Height);
	~Window();  // ��������

	bool InitWindow(int Width, int Height);  // ��ʼ������
	bool IsOpen();  // �жϴ����Ƿ��
	void DestroyWindow();
	void ProcessEvents();
	//void ToggleFullScreen();  // �л�ȫ��ģʽ
	//void RunMessageLoop();  // ������Ϣѭ��

	//static LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);  // ��̬��Ϣ������
	////void SetUserData();  // ���ô��ڵ��û����ݣ�ָ��ǰ����
	///*void DrawImg(IMAGE_PR& Myimg, int X, int Y);*/
	//int image_positionX;
	//int image_positionY;
};
#endif	
