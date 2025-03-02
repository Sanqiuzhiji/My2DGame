#pragma once
#include "main.h"
#include "graphics.h"
class IMAGE_PR
{
public:
	
	IMAGE_PR(const TCHAR* path, int targetWidth, int targetHeight);  // ���캯��
	~IMAGE_PR(); // ��������

	// ͼ������
	void ShowScalingImage(int targetHeight, bool isHeightFixed = true);
	void ShowScalingImage(int targetWidth, int targetHeight);

	IMAGE PRImg;   // ������ͼ��	
private:

IMAGE OriginImage;  // ԭʼͼ��

};