#pragma once
#include "main.h"
#include "graphics.h"
class IMAGE_PR
{
public:

	IMAGE_PR();  // ���캯��
	~IMAGE_PR(); // ��������

	void imageload(const TCHAR* path);

	// ͼ������
	void ShowScalingImage(int targetHeight, bool isHeightFixed = true);
	void ShowScalingImage(int targetWidth, int targetHeight);
	IMAGE PRImg;   // ������ͼ��	
	IMAGE OriginImage;  // ԭʼͼ��
private:

};