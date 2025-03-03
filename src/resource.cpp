#include "../include/resource.h"
#include <filesystem>
#include <string>
#include <map>
void Resource::imageload(const TCHAR* path)
{
	// 初始化成员变量
	loadimage(&OriginImage, path);
}
void Resource::LoadImage(const std::string& name, const std::string& path) {
	IMAGE img;
	std::wstring wPath = std::filesystem::path(path).wstring();  // 自动转换
	loadimage(&img, wPath.c_str());
	images[name] = img;
}


IMAGE* Resource::GetImage(const std::string& name) {
	return &images[name];
}


//直接缩放
void Resource::ShowScalingImage(int targetWidth, int targetHeight)
{
	// 1. 确保原始图像存在
	if (OriginImage.getwidth() == 0 || OriginImage.getheight() == 0) {
		std::cerr << "Error: 原始图像无效！" << std::endl;
		return;
	}

	// 2. 重新调整 PRImg 的大小
	PRImg.Resize(targetWidth, targetHeight);

	// 3. 获取原始图像和缩放后图像的 HDC
	HDC hdcSrc = GetImageHDC(&OriginImage);
	HDC hdcDst = GetImageHDC(&PRImg);

	// 4. 设置 HALFTONE 以提高缩放质量
	SetStretchBltMode(hdcDst, HALFTONE);
	SetBrushOrgEx(hdcDst, 0, 0, NULL);  // 让 HALFTONE 正确工作

	// 5. 使用 StretchBlt 进行缩放
	if (!StretchBlt(hdcDst, 0, 0, targetWidth, targetHeight,
		hdcSrc, 0, 0, OriginImage.getwidth(), OriginImage.getheight(),
		SRCCOPY)) {
		std::cerr << "StretchBlt 失败，错误码：" << GetLastError() << std::endl;
	}
}


//// 图像缩放并显示
//void IMAGE_PR::ShowScalingImage(int targetValue, bool isHeightFixed)
//{
//	float Width_Height_Ratio = (float)OriginImage.getwidth() / (float)OriginImage.getheight();  // 原始图像的宽高比
//	int targetWidth = 0, targetHeight = 0;
//	if (isHeightFixed)
//	{
//		targetHeight = targetValue;
//		targetWidth = (int)(targetValue * Width_Height_Ratio);  // 高度固定，宽度按比例缩放
//	}
//	else
//	{
//		targetWidth = targetValue;
//		targetHeight = (int)(targetValue / Width_Height_Ratio);  // 高度固定，宽度按比例缩放
//	}
//
//	// 初始化缩放后的图像大小
//	PRImg.Resize(targetWidth, targetHeight);
//
//	// 获取原始图像和缩放后图像的 HDC
//	HDC hdcSrc = GetImageHDC(&OriginImage);  // 原始图像的 HDC
//	HDC hdcDst = GetImageHDC(&PRImg);   // 缩放后图像的 HDC
//
//	// 使用 StretchBlt 函数进行图像缩放
//	SetStretchBltMode(hdcDst, HALFTONE);  // 设置缩放模式为 HALFTONE，以获得更好的缩放质量
//	StretchBlt(
//		hdcDst, 0, 0, targetWidth, targetHeight,  // 目标区域（缩放后图像）
//		hdcSrc, 0, 0, OriginImage.getwidth(), OriginImage.getheight(),  // 源区域（原始图像）
//		SRCCOPY  // 复制模式
//	);
//}
