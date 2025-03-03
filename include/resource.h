#pragma once
#include "main.h"
#include "graphics.h"
#include "MyIMAGE.h"
#include <map>
#include <string>

class MyIMAGE;
class Resource
{
private:

public:
	Resource();  // 构造函数
	~Resource() = default; // 析构函数

	void addimage(MyIMAGE* img);
	IMAGE* GetImage(const std::string& name);

	// 图像缩放
	void ShowScalingImage(int targetWidth, int targetHeight);
	//void ShowScalingImage(int targetHeight, bool isHeightFixed = true);

	IMAGE PRImg;   // 处理后的图像	
	IMAGE OriginImage;  // 原始图像
	std::map<std::string, IMAGE**> images;  // 存储图片资源

};