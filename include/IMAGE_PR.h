#pragma once
#include "main.h"
#include "graphics.h"
class IMAGE_PR
{
public:

	IMAGE_PR();  // 构造函数
	~IMAGE_PR(); // 析构函数

	void imageload(const TCHAR* path);

	// 图像缩放
	void ShowScalingImage(int targetHeight, bool isHeightFixed = true);
	void ShowScalingImage(int targetWidth, int targetHeight);
	IMAGE PRImg;   // 处理后的图像	
	IMAGE OriginImage;  // 原始图像
private:

};