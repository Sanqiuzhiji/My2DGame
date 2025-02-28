#include "main.h"
#include "../include/IMAGE_PR.h"

void drawStartPage()
{
	// ��ʼ������
	initgraph(screenWidth, screenHeight);

	// ����ͼ��
	IMAGE_PR startpage_img(_T(".\\resources\\images\\startpage.png"));
	startpage_img.ShowOriginImage(0, 0);

	IMAGE_PR startbutton_img(_T(".\\resources\\images\\startbutton.png"));
	startbutton_img.ShowScalingImage(50, STARTBUTTON_X, STARTBUTTON_Y);

	while (true)
	{
		if (MouseHit())
		{  // ����Ƿ��������Ϣ
			MOUSEMSG m = GetMouseMsg();  // ��ȡ�����Ϣ
			if (m.x > startbutton_img.x_vertex_Img && m.x < startbutton_img.x_vertex_Img + startbutton_img.width_Img 
				&& m.y > startbutton_img.y_vertex_Img && m.y < startbutton_img.y_vertex_Img + startbutton_img.height_Img 
				&& m.uMsg == WM_LBUTTONDOWN)
			{
				// ������ҳ��
				drawMainPage();
			}
		}
		Sleep(10);
	}

}
