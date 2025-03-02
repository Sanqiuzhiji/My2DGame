#include "../include/startpage.h"
#include "../include/map.h"
#include "../include/player.h"

Window MainWindow(windowWidth, windowHeight, 0, 0);

//载入资源
IMAGE_PR startpage_img;
IMAGE_PR startbutton_img;
map gamemap(_T(".\\resources\\images\\game_background.png"));
player player1(_T(".\\resources\\images\\player.png"));

//void drawAlpha(IMAGE* picture, int  picture_x, int picture_y) //透明化函数
//{
//
//	// 变量初始化
//	DWORD* dst = GetImageBuffer();    // GetImageBuffer()函数，用于获取绘图设备的显存指针，EASYX自带
//	DWORD* draw = GetImageBuffer();
//	DWORD* src = GetImageBuffer(picture); //获取picture的显存指针
//	int picture_width = picture->getwidth(); //获取picture的宽度，EASYX自带
//	int picture_height = picture->getheight(); //获取picture的高度，EASYX自带
//	int graphWidth = getwidth();       //获取绘图区的宽度，EASYX自带
//	int graphHeight = getheight();     //获取绘图区的高度，EASYX自带
//	int dstX = 0;    //在显存里像素的角标
//
//	// 实现透明贴图 公式： Cp=αp*FP+(1-αp)*BP ， 贝叶斯定理来进行点颜色的概率计算
//	for (int iy = 0; iy < picture_height; iy++)
//	{
//		for (int ix = 0; ix < picture_width; ix++)
//		{
//			int srcX = ix + iy * picture_width; //在显存里像素的角标
//			int sa = ((src[srcX] & 0xff000000) >> 24); //0xAArrggbb;AA是透明度
//			int sr = ((src[srcX] & 0xff0000) >> 16); //获取RGB里的R
//			int sg = ((src[srcX] & 0xff00) >> 8);   //G
//			int sb = src[srcX] & 0xff;              //B
//			if (ix >= 0 && ix <= graphWidth && iy >= 0 && iy <= graphHeight && dstX <= graphWidth * graphHeight)
//			{
//				dstX = (ix + picture_x) + (iy + picture_y) * graphWidth; //在显存里像素的角标
//				int dr = ((dst[dstX] & 0xff0000) >> 16);
//				int dg = ((dst[dstX] & 0xff00) >> 8);
//				int db = dst[dstX] & 0xff;
//				draw[dstX] = ((sr * sa / 255 + dr * (255 - sa) / 255) << 16)  //公式： Cp=αp*FP+(1-αp)*BP  ； αp=sa/255 , FP=sr , BP=dr
//					| ((sg * sa / 255 + dg * (255 - sa) / 255) << 8)         //αp=sa/255 , FP=sg , BP=dg
//					| (sb * sa / 255 + db * (255 - sa) / 255);              //αp=sa/255 , FP=sb , BP=db
//			}
//		}
//	}
//}

// 透明化处理函数（将指定颜色设为透明）
void MakeImageTransparent(IMAGE* img, COLORREF transColor)
{
	int width = img->getwidth();
	int height = img->getheight();
	DWORD* buffer = GetImageBuffer(img);

	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {
			int index = y * width + x;
			if (buffer[index] == transColor) {
				buffer[index] &= 0x00FFFFFF; // 将透明度设为 0（完全透明）
			}
		}
	}
}
void drawStartPage()
{
	startpage_img.imageload(_T(".\\resources\\images\\startpage.png"));
	startbutton_img.imageload(_T(".\\resources\\images\\startbutton.png"));

	initgraph(windowWidth, windowHeight); // 初始化窗口

	//startpage_img.ShowScalingImage(windowWidth, windowWidth); // 直接缩放
	//startbutton_img.ShowScalingImage(STARTBUTTON_WIDTH, STARTBUTTON_HEIGHT); // 直接缩放

	player1.map_positionX = 512 / 4;
	player1.map_positionY = 512 / 8;

	gamemap.get_player_view(player1, 512 / 4 * 2, 512 / 8 * 2);

	MainWindow.DrawImg(gamemap.player_view, windowWidth / 2, windowHeight / 2);
	player1.player_image.ShowScalingImage(240);
	MakeImageTransparent(&player1.player_image.PRImg, RGB(0, 0, 0)); // 设定白色为透明
	MainWindow.DrawImg(player1.player_image, windowWidth / 2, windowHeight / 2);


	//putimage(0, 0, &startpage_img.PRImg);

	//MainWindow.DrawImg(startpage_img, windowWidth / 2, windowHeight / 2);
	//MainWindow.DrawImg(startbutton_img, windowWidth / 2 - STARTBUTTON_WIDTH / 2, windowHeight / 2 + STARTBUTTON_HEIGHT / 2);

	//MainWindow.RunMessageLoop();  // 启动消息循环
	while (true) {
		if (_kbhit())
		{
			BeginBatchDraw();  // 开始双缓冲
			cleardevice();     // 清屏，防止画面残留
			char key = _getch();
			switch (key)
			{
			case 72: // ↑
				player1.map_positionY -= 2;
				break;
			case 80: // ↓
				player1.map_positionY += 2;
				break;
			case 75: // ←
				player1.map_positionX -= 2;
				break;
			case 77: // → 
				player1.map_positionX += 2;
				break;
			case 27: // ESC 退出
				closegraph();
			}
			// 开始双缓冲
			std::cout << player1.player_image.PRImg.getheight() << player1.player_image.OriginImage.getheight() << std::endl;
			gamemap.get_player_view(player1, 512 / 4 * 2, 512 / 8 * 2);
			MainWindow.DrawImg(gamemap.player_view, windowWidth / 2, windowHeight / 2);
			MainWindow.DrawImg(player1.player_image, windowWidth / 2, windowHeight / 2);

			EndBatchDraw(); // 结束双缓冲，刷新屏幕
		}
		/*Sleep(10);*/

	}
}
