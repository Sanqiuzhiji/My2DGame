#pragma once

#include "graphics.h"
#include "main.h"

class IMAGE_PR
{
public:
	IMAGE_PR(const TCHAR* path);  // 构造函数
	~IMAGE_PR(); // 析构函数

	// 显示原图像
	void ShowOriginImage(int x_vertex, int y_vertex);

	// 图像缩放
	void ShowScalingImage(int targetWidth, int targetHeight, int x, int y);
	void ShowScalingImage(int targetHeight, int x, int y, bool isHeightFixed = true);

	int x_Img = 0, y_Img = 0;
	int x_vertex_Img = 0, y_vertex_Img = 0;
	int width_Img = 0, height_Img = 0;

private:
	IMAGE OriginImage;  // 原始图像
	IMAGE PRImg;   // 处理后的图像

};