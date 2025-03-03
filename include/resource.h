#pragma once
#include "main.h"
#include "graphics.h"
#include <map>
#include <string>
class Resource
{
private:
	std::map<std::string, IMAGE> images;  // 存储图片资源
public:

	Resource()=default;  // 构造函数
	~Resource()=default; // 析构函数

	void imageload(const TCHAR* path);


	void LoadImage(const std::string& name, const std::string& path);
	IMAGE* GetImage(const std::string& name);

	// 图像缩放
	//void ShowScalingImage(int targetHeight, bool isHeightFixed = true);
	void ShowScalingImage(int targetWidth, int targetHeight);
	IMAGE PRImg;   // 处理后的图像	
	IMAGE OriginImage;  // 原始图像

};