#include "main.h"
#include "../include/IMAGE_PR.h"

void drawMainPage()
{
	// ��ʼ������
	initgraph(screenWidth, screenHeight);

	int viewportX = 0, viewportY = 0, MOVE_STEP = 10;
	int  MAP_WIDTH = screenWidth * 3, MAP_HEIGHT = screenHeight * 3;
	int  VIEW_WIDTH = screenWidth, VIEW_HEIGHT = screenHeight;
	// ����ͼ��
	IMAGE_PR gamebackground_img(_T(".\\resources\\images\\game_background.png"));
	gamebackground_img.ShowScalingImage(screenWidth * 3, screenHeight * 3, screenWidth * 3 / 2, screenHeight * 3 / 2);

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
			gamebackground_img.ShowScalingImage(screenWidth * 3, screenHeight * 3, screenWidth * 3 / 2 + viewportX, screenHeight * 3 / 2 + viewportY);
			EndBatchDraw(); // ����˫���壬ˢ����Ļ
		}
		/*Sleep(10);*/
	}
}

