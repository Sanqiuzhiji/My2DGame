#include "../include/IMAGE_PR.h"

// ���캯��
IMAGE_PR::IMAGE_PR(const TCHAR* path)
{
	// ��ʼ����Ա����
	loadimage(&OriginImage, path);
}

// ��������
IMAGE_PR::~IMAGE_PR()
{
	// ������Դ�������Ҫ��
}


// ��ʾͼ��
void IMAGE_PR::ShowOriginImage(int x_vertex, int y_vertex)
{
	putimage(x_vertex, y_vertex, &OriginImage);  // ��ָ��λ����ʾԭʼͼ��
	width_Img = OriginImage.getwidth();
	height_Img = OriginImage.getheight();
	x_vertex_Img = x_vertex;
	y_vertex_Img = y_vertex;
	x_Img = x_vertex + width_Img / 2;
	y_Img = y_vertex + height_Img / 2;
}

// ͼ�����Ų���ʾ
void IMAGE_PR::ShowScalingImage(int targetWidth, int targetHeight, int x, int y)
{
	// ��ʼ�����ź��ͼ���С
	PRImg.Resize(targetWidth, targetHeight);

	// ��ȡԭʼͼ������ź�ͼ��� HDC
	HDC hdcSrc = GetImageHDC(&OriginImage);  // ԭʼͼ��� HDC
	HDC hdcDst = GetImageHDC(&PRImg);   // ���ź�ͼ��� HDC

	// ʹ�� StretchBlt ��������ͼ������
	SetStretchBltMode(hdcDst, HALFTONE);  // ��������ģʽΪ HALFTONE���Ի�ø��õ���������
	StretchBlt(
		hdcDst, 0, 0, targetHeight, targetHeight,  // Ŀ���������ź�ͼ��
		hdcSrc, 0, 0, OriginImage.getwidth(), OriginImage.getheight(),  // Դ����ԭʼͼ��
		SRCCOPY  // ����ģʽ
	);
	width_Img = PRImg.getwidth();
	height_Img = PRImg.getheight();
	x_Img = x;
	y_Img = y;
	x_vertex_Img = x - width_Img / 2;
	y_vertex_Img = y - height_Img / 2;

	putimage(x_vertex_Img, y_vertex_Img, &PRImg);  // �ڴ��ڵ� (250, 200) ���괦��ʾͼƬ


}

// ͼ�����Ų���ʾ
void IMAGE_PR::ShowScalingImage(int targetValue, int x, int y, bool isHeightFixed)
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

	width_Img = PRImg.getwidth();
	height_Img = PRImg.getheight();
	x_Img = x;
	y_Img = y;
	x_vertex_Img = x - width_Img / 2;
	y_vertex_Img = y - height_Img / 2;

	putimage(x_vertex_Img, y_vertex_Img, &PRImg);  // �ڴ��ڵ� (250, 200) ���괦��ʾͼƬ

}
