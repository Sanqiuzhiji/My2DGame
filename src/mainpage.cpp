#include "../include/main.h"

void drawMainPage()
{
	// ��ʼ������
	initgraph(windowWidth, windowHeight);

	int viewportX = 0, viewportY = 0, MOVE_STEP = 10;
	double  MAP_WIDTH = windowWidth * 3, MAP_HEIGHT = windowHeight * 3;
	double  VIEW_WIDTH = windowWidth, VIEW_HEIGHT = windowHeight;

	while (true) {
		if (_kbhit())
		{
			BeginBatchDraw();  // ��ʼ˫����
			cleardevice();     // ��������ֹ�������
			char key = _getch();
			switch (key)
			{
			case 72: // ��
				viewportY += MOVE_STEP;
				break;
			case 80: // ��
				viewportY -= MOVE_STEP;
				break;
			case 75: // ��
				viewportX += MOVE_STEP;
				break;
			case 77: // �� 
				viewportX -= MOVE_STEP;
				break;
			case 27: // ESC �˳�
				closegraph();
			}
			// ��ʼ˫����
		/*	gamebackground_img.ShowScalingImage(screenWidth * 3, screenHeight * 3, screenWidth * 3 / 2 + viewportX, screenHeight * 3 / 2 + viewportY);*/
			EndBatchDraw(); // ����˫���壬ˢ����Ļ
		}
		/*Sleep(10);*/
	}
}

