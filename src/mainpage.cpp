#include "../include/startpage.h"
#include "../include/map.h"
#include "../include/player.h"
//载入资源
Resource  mainpage_img;
void drawMainPage()
{
	//mainpage_img.imageload(_T("..\\resources\\images\\mainpage.png"));
	initgraph(windowWidth, windowHeight); // 初始化窗口

	//startpage_img.ShowScalingImage(windowWidth, windowWidth); // 直接缩放
	//MainWindow.RunMessageLoop();  // 启动消息循环
	while (true)
	{
		ExMessage msg;
		if (peekmessage(&msg, EM_MOUSE))
		{  // 监听鼠标事件
			if (msg.message == WM_LBUTTONDOWN)
			{  // 鼠标左键按下
			}
		}
	}
}
