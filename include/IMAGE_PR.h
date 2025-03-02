#pragma once
#include "main.h"
#include "graphics.h"
class IMAGE_PR
{
public:
	
	IMAGE_PR(const TCHAR* path, int targetWidth, int targetHeight);  // 构造函数
	~IMAGE_PR(); // 析构函数

	// 图像缩放
	void ShowScalingImage(int targetHeight, bool isHeightFixed = true);
	void ShowScalingImage(int targetWidth, int targetHeight);

	IMAGE PRImg;   // 处理后的图像	
private:

IMAGE OriginImage;  // 原始图像

};