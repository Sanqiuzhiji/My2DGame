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
	Resource();  // ���캯��
	~Resource() = default; // ��������

	void addimage(MyIMAGE* img);
	IMAGE* GetImage(const std::string& name);

	// ͼ������
	void ShowScalingImage(int targetWidth, int targetHeight);
	//void ShowScalingImage(int targetHeight, bool isHeightFixed = true);

	IMAGE PRImg;   // ������ͼ��	
	IMAGE OriginImage;  // ԭʼͼ��
	std::map<std::string, IMAGE**> images;  // �洢ͼƬ��Դ

};