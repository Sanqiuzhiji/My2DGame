#include "../include/startpage.h"
#include "../include/map.h"
#include "../include/player.h"
//������Դ
Resource  mainpage_img;
void drawMainPage()
{
	//mainpage_img.imageload(_T("..\\resources\\images\\mainpage.png"));
	initgraph(windowWidth, windowHeight); // ��ʼ������

	//startpage_img.ShowScalingImage(windowWidth, windowWidth); // ֱ������
	//MainWindow.RunMessageLoop();  // ������Ϣѭ��
	while (true)
	{
		ExMessage msg;
		if (peekmessage(&msg, EM_MOUSE))
		{  // ��������¼�
			if (msg.message == WM_LBUTTONDOWN)
			{  // ����������
			}
		}
	}
}
