#include "../include/startpage.h"
#include "../include/map.h"
#include "../include/player.h"


// ��ȡ��Ļ�Ŀ�Ⱥ͸߶����ô��ڴ�С
int windowWidth = static_cast<int>(GetSystemMetrics(SM_CXSCREEN) * 0.8);
int windowHeight = static_cast<int>(GetSystemMetrics(SM_CYSCREEN) * 0.8);
//Window MainWindow(windowWidth, windowHeight, 0, 0);
//


//������Դ
Resource startpage_img;
Resource startbutton_img;

void drawStartPage()
{
	//startpage_img.imageload(_T("..\\resources\\images\\startpage.png"));
	//startbutton_img.imageload(_T("..\\resources\\images\\startbutton.png"));

	startpage_img.ShowScalingImage(windowWidth, windowWidth); // ֱ������
	startbutton_img.ShowScalingImage(STARTBUTTON_WIDTH, STARTBUTTON_HEIGHT); // ֱ������


	//MainWindow.DrawImg(startpage_img, windowWidth / 2, windowHeight / 2);
	//MainWindow.DrawImg(startbutton_img, windowWidth / 2 - STARTBUTTON_WIDTH / 2, windowHeight *2/3 + STARTBUTTON_HEIGHT / 2);

	// ˢ�´���
	FlushBatchDraw();
	//MainWindow.RunMessageLoop();  // ������Ϣѭ��
	while (true) 
	{
		ExMessage msg;
		if (peekmessage(&msg, EM_MOUSE, true)) 
		{
		std::cout << msg.x<< msg.y << std::endl;			
		if (msg.message == WM_LBUTTONDOWN) 
			{  // ����������
			}
		}
		FlushBatchDraw();  // ˢ�� EasyX ��ͼ����ֹ���濨��
		Sleep(10);
	}
}
