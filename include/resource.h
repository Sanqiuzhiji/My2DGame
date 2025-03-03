#pragma once
#include "main.h"
#include "graphics.h"
#include <map>
#include <string>
class Resource
{
private:
	std::map<std::string, IMAGE> images;  // �洢ͼƬ��Դ
public:

	Resource()=default;  // ���캯��
	~Resource()=default; // ��������

	void imageload(const TCHAR* path);


	void LoadImage(const std::string& name, const std::string& path);
	IMAGE* GetImage(const std::string& name);

	// ͼ������
	//void ShowScalingImage(int targetHeight, bool isHeightFixed = true);
	void ShowScalingImage(int targetWidth, int targetHeight);
	IMAGE PRImg;   // ������ͼ��	
	IMAGE OriginImage;  // ԭʼͼ��

};