#pragma once

#include "graphics.h"
#include "main.h"

class IMAGE_PR
{
public:
	IMAGE_PR(const TCHAR* path);  // ���캯��
	~IMAGE_PR(); // ��������

	// ��ʾԭͼ��
	void ShowOriginImage(int x_vertex, int y_vertex);

	// ͼ������
	void ShowScalingImage(int targetWidth, int targetHeight, int x, int y);
	void ShowScalingImage(int targetHeight, int x, int y, bool isHeightFixed = true);

	int x_Img = 0, y_Img = 0;
	int x_vertex_Img = 0, y_vertex_Img = 0;
	int width_Img = 0, height_Img = 0;

private:
	IMAGE OriginImage;  // ԭʼͼ��
	IMAGE PRImg;   // ������ͼ��

};