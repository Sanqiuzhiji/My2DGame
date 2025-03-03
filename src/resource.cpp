#include "../include/resource.h"
#include <filesystem>
#include <string>
#include <map>
void Resource::imageload(const TCHAR* path)
{
	// ��ʼ����Ա����
	loadimage(&OriginImage, path);
}
void Resource::LoadImage(const std::string& name, const std::string& path) {
	IMAGE img;
	std::wstring wPath = std::filesystem::path(path).wstring();  // �Զ�ת��
	loadimage(&img, wPath.c_str());
	images[name] = img;
}


IMAGE* Resource::GetImage(const std::string& name) {
	return &images[name];
}


//ֱ������
void Resource::ShowScalingImage(int targetWidth, int targetHeight)
{
	// 1. ȷ��ԭʼͼ�����
	if (OriginImage.getwidth() == 0 || OriginImage.getheight() == 0) {
		std::cerr << "Error: ԭʼͼ����Ч��" << std::endl;
		return;
	}

	// 2. ���µ��� PRImg �Ĵ�С
	PRImg.Resize(targetWidth, targetHeight);

	// 3. ��ȡԭʼͼ������ź�ͼ��� HDC
	HDC hdcSrc = GetImageHDC(&OriginImage);
	HDC hdcDst = GetImageHDC(&PRImg);

	// 4. ���� HALFTONE �������������
	SetStretchBltMode(hdcDst, HALFTONE);
	SetBrushOrgEx(hdcDst, 0, 0, NULL);  // �� HALFTONE ��ȷ����

	// 5. ʹ�� StretchBlt ��������
	if (!StretchBlt(hdcDst, 0, 0, targetWidth, targetHeight,
		hdcSrc, 0, 0, OriginImage.getwidth(), OriginImage.getheight(),
		SRCCOPY)) {
		std::cerr << "StretchBlt ʧ�ܣ������룺" << GetLastError() << std::endl;
	}
}


//// ͼ�����Ų���ʾ
//void IMAGE_PR::ShowScalingImage(int targetValue, bool isHeightFixed)
//{
//	float Width_Height_Ratio = (float)OriginImage.getwidth() / (float)OriginImage.getheight();  // ԭʼͼ��Ŀ�߱�
//	int targetWidth = 0, targetHeight = 0;
//	if (isHeightFixed)
//	{
//		targetHeight = targetValue;
//		targetWidth = (int)(targetValue * Width_Height_Ratio);  // �߶ȹ̶�����Ȱ���������
//	}
//	else
//	{
//		targetWidth = targetValue;
//		targetHeight = (int)(targetValue / Width_Height_Ratio);  // �߶ȹ̶�����Ȱ���������
//	}
//
//	// ��ʼ�����ź��ͼ���С
//	PRImg.Resize(targetWidth, targetHeight);
//
//	// ��ȡԭʼͼ������ź�ͼ��� HDC
//	HDC hdcSrc = GetImageHDC(&OriginImage);  // ԭʼͼ��� HDC
//	HDC hdcDst = GetImageHDC(&PRImg);   // ���ź�ͼ��� HDC
//
//	// ʹ�� StretchBlt ��������ͼ������
//	SetStretchBltMode(hdcDst, HALFTONE);  // ��������ģʽΪ HALFTONE���Ի�ø��õ���������
//	StretchBlt(
//		hdcDst, 0, 0, targetWidth, targetHeight,  // Ŀ���������ź�ͼ��
//		hdcSrc, 0, 0, OriginImage.getwidth(), OriginImage.getheight(),  // Դ����ԭʼͼ��
//		SRCCOPY  // ����ģʽ
//	);
//}
