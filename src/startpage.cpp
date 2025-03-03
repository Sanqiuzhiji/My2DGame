#include "../include/startpage.h"
#include "../include/map.h"
#include "../include/player.h"


// 获取屏幕的宽度和高度设置窗口大小
int windowWidth = static_cast<int>(GetSystemMetrics(SM_CXSCREEN) * 0.8);
int windowHeight = static_cast<int>(GetSystemMetrics(SM_CYSCREEN) * 0.8);
//Window MainWindow(windowWidth, windowHeight, 0, 0);
//


//载入资源
Resource startpage_img;
Resource startbutton_img;

void drawStartPage()
{
	//startpage_img.imageload(_T("..\\resources\\images\\startpage.png"));
	//startbutton_img.imageload(_T("..\\resources\\images\\startbutton.png"));

	startpage_img.ShowScalingImage(windowWidth, windowWidth); // 直接缩放
	startbutton_img.ShowScalingImage(STARTBUTTON_WIDTH, STARTBUTTON_HEIGHT); // 直接缩放


	//MainWindow.DrawImg(startpage_img, windowWidth / 2, windowHeight / 2);
	//MainWindow.DrawImg(startbutton_img, windowWidth / 2 - STARTBUTTON_WIDTH / 2, windowHeight *2/3 + STARTBUTTON_HEIGHT / 2);

	// 刷新窗口
	FlushBatchDraw();
	//MainWindow.RunMessageLoop();  // 启动消息循环
	while (true) 
	{
		ExMessage msg;
		if (peekmessage(&msg, EM_MOUSE, true)) 
		{
		std::cout << msg.x<< msg.y << std::endl;			
		if (msg.message == WM_LBUTTONDOWN) 
			{  // 鼠标左键按下
			}
		}
		FlushBatchDraw();  // 刷新 EasyX 绘图，防止界面卡死
		Sleep(10);
	}
}
