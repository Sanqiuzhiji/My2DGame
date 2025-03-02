#include "../include/IMAGE_PR.h"

// ���캯��
//IMAGE_PR::IMAGE_PR(const TCHAR* path)
//{
//	// ��ʼ����Ա����
//	loadimage(&OriginImage, path);
//}

IMAGE_PR::IMAGE_PR(const TCHAR* path, int targetWidth = 0, int targetHeight = 0)
{
	loadimage(&OriginImage, path); // ����ͼ��
	if (targetWidth > 0 && targetHeight > 0)
	{
		ShowScalingImage(targetWidth, targetHeight); // ֱ������
	}
}
// ��������
IMAGE_PR::~IMAGE_PR()
{
	// ������Դ�������Ҫ��

}
//ֱ������
void IMAGE_PR::ShowScalingImage(int targetWidth, int targetHeight)
{
	// ��ʼ�����ź��ͼ���С
	PRImg.Resize(targetWidth, targetHeight);

	// ��ȡԭʼͼ������ź�ͼ��� HDC
	HDC hdcSrc = GetImageHDC(&OriginImage);  // ԭʼͼ��� HDC
	HDC hdcDst = GetImageHDC(&PRImg);   // ���ź�ͼ��� HDC

	// ʹ�� StretchBlt ��������ͼ������
	SetStretchBltMode(hdcDst, HALFTONE);  // ��������ģʽΪ HALFTONE���Ի�ø��õ���������
	StretchBlt(
		hdcDst, 0, 0, targetWidth, targetHeight,  // Ŀ���������ź�ͼ��
		hdcSrc, 0, 0, OriginImage.getwidth(), OriginImage.getheight(),  // Դ����ԭʼͼ��
		SRCCOPY  // ����ģʽ
	);
}

// ͼ�����Ų���ʾ
void IMAGE_PR::ShowScalingImage(int targetValue, bool isHeightFixed)
{
	float Width_Height_Ratio = (float)OriginImage.getwidth() / (float)OriginImage.getheight();  // ԭʼͼ��Ŀ�߱�
	int targetWidth = 0, targetHeight = 0;
	if (isHeightFixed)
	{
		targetHeight = targetValue;
		targetWidth = (int)(targetValue * Width_Height_Ratio);  // �߶ȹ̶�����Ȱ���������
	}
	else
	{
		targetWidth = targetValue;
		targetHeight = (int)(targetValue / Width_Height_Ratio);  // �߶ȹ̶�����Ȱ���������
	}

	// ��ʼ�����ź��ͼ���С
	PRImg.Resize(targetWidth, targetHeight);

	// ��ȡԭʼͼ������ź�ͼ��� HDC
	HDC hdcSrc = GetImageHDC(&OriginImage);  // ԭʼͼ��� HDC
	HDC hdcDst = GetImageHDC(&PRImg);   // ���ź�ͼ��� HDC

	// ʹ�� StretchBlt ��������ͼ������
	SetStretchBltMode(hdcDst, HALFTONE);  // ��������ģʽΪ HALFTONE���Ի�ø��õ���������
	StretchBlt(
		hdcDst, 0, 0, targetWidth, targetHeight,  // Ŀ���������ź�ͼ��
		hdcSrc, 0, 0, OriginImage.getwidth(), OriginImage.getheight(),  // Դ����ԭʼͼ��
		SRCCOPY  // ����ģʽ
	);
}
