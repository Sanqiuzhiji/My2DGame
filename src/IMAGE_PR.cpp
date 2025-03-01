#include "../include/IMAGE_PR.h"

// 构造函数
IMAGE_PR::IMAGE_PR(const TCHAR* path)
{
	// 初始化成员变量
	loadimage(&OriginImage, path);
}

// 析构函数
IMAGE_PR::~IMAGE_PR()
{
	// 清理资源（如果需要）
}


// 显示图像
void IMAGE_PR::ShowOriginImage(int x_vertex, int y_vertex)
{
	putimage(x_vertex, y_vertex, &OriginImage);  // 在指定位置显示原始图像
	width_Img = OriginImage.getwidth();
	height_Img = OriginImage.getheight();
	x_vertex_Img = x_vertex;
	y_vertex_Img = y_vertex;
	x_Img = x_vertex + width_Img / 2;
	y_Img = y_vertex + height_Img / 2;
}

// 图像缩放并显示
void IMAGE_PR::ShowScalingImage(int targetWidth, int targetHeight, int x, int y)
{
	// 初始化缩放后的图像大小
	PRImg.Resize(targetWidth, targetHeight);

	// 获取原始图像和缩放后图像的 HDC
	HDC hdcSrc = GetImageHDC(&OriginImage);  // 原始图像的 HDC
	HDC hdcDst = GetImageHDC(&PRImg);   // 缩放后图像的 HDC

	// 使用 StretchBlt 函数进行图像缩放
	SetStretchBltMode(hdcDst, HALFTONE);  // 设置缩放模式为 HALFTONE，以获得更好的缩放质量
	StretchBlt(
		hdcDst, 0, 0, targetHeight, targetHeight,  // 目标区域（缩放后图像）
		hdcSrc, 0, 0, OriginImage.getwidth(), OriginImage.getheight(),  // 源区域（原始图像）
		SRCCOPY  // 复制模式
	);
	width_Img = PRImg.getwidth();
	height_Img = PRImg.getheight();
	x_Img = x;
	y_Img = y;
	x_vertex_Img = x - width_Img / 2;
	y_vertex_Img = y - height_Img / 2;

	putimage(x_vertex_Img, y_vertex_Img, &PRImg);  // 在窗口的 (250, 200) 坐标处显示图片


}

// 图像缩放并显示
void IMAGE_PR::ShowScalingImage(int targetValue, int x, int y, bool isHeightFixed)
{
	float Width_Height_Ratio = (float)OriginImage.getwidth() / (float)OriginImage.getheight();  // 原始图像的宽高比
	int targetWidth = 0, targetHeight = 0;
	if (isHeightFixed)
	{
		targetHeight = targetValue;
		targetWidth = (int)(targetValue * Width_Height_Ratio);  // 高度固定，宽度按比例缩放
	}
	else
	{
		targetWidth = targetValue;
		targetHeight = (int)(targetValue / Width_Height_Ratio);  // 高度固定，宽度按比例缩放
	}

	// 初始化缩放后的图像大小
	PRImg.Resize(targetWidth, targetHeight);

	// 获取原始图像和缩放后图像的 HDC
	HDC hdcSrc = GetImageHDC(&OriginImage);  // 原始图像的 HDC
	HDC hdcDst = GetImageHDC(&PRImg);   // 缩放后图像的 HDC

	// 使用 StretchBlt 函数进行图像缩放
	SetStretchBltMode(hdcDst, HALFTONE);  // 设置缩放模式为 HALFTONE，以获得更好的缩放质量
	StretchBlt(
		hdcDst, 0, 0, targetWidth, targetHeight,  // 目标区域（缩放后图像）
		hdcSrc, 0, 0, OriginImage.getwidth(), OriginImage.getheight(),  // 源区域（原始图像）
		SRCCOPY  // 复制模式
	);

	width_Img = PRImg.getwidth();
	height_Img = PRImg.getheight();
	x_Img = x;
	y_Img = y;
	x_vertex_Img = x - width_Img / 2;
	y_vertex_Img = y - height_Img / 2;

	putimage(x_vertex_Img, y_vertex_Img, &PRImg);  // 在窗口的 (250, 200) 坐标处显示图片

}
