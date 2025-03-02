#include "../include/startpage.h"
#include "../include/map.h"
#include "../include/player.h"

Window MainWindow(windowWidth, windowHeight, 0, 0);

//������Դ
IMAGE_PR startpage_img;
IMAGE_PR startbutton_img;
map gamemap(_T(".\\resources\\images\\game_background.png"));
player player1(_T(".\\resources\\images\\player.png"));

//void drawAlpha(IMAGE* picture, int  picture_x, int picture_y) //͸��������
//{
//
//	// ������ʼ��
//	DWORD* dst = GetImageBuffer();    // GetImageBuffer()���������ڻ�ȡ��ͼ�豸���Դ�ָ�룬EASYX�Դ�
//	DWORD* draw = GetImageBuffer();
//	DWORD* src = GetImageBuffer(picture); //��ȡpicture���Դ�ָ��
//	int picture_width = picture->getwidth(); //��ȡpicture�Ŀ�ȣ�EASYX�Դ�
//	int picture_height = picture->getheight(); //��ȡpicture�ĸ߶ȣ�EASYX�Դ�
//	int graphWidth = getwidth();       //��ȡ��ͼ���Ŀ�ȣ�EASYX�Դ�
//	int graphHeight = getheight();     //��ȡ��ͼ���ĸ߶ȣ�EASYX�Դ�
//	int dstX = 0;    //���Դ������صĽǱ�
//
//	// ʵ��͸����ͼ ��ʽ�� Cp=��p*FP+(1-��p)*BP �� ��Ҷ˹���������е���ɫ�ĸ��ʼ���
//	for (int iy = 0; iy < picture_height; iy++)
//	{
//		for (int ix = 0; ix < picture_width; ix++)
//		{
//			int srcX = ix + iy * picture_width; //���Դ������صĽǱ�
//			int sa = ((src[srcX] & 0xff000000) >> 24); //0xAArrggbb;AA��͸����
//			int sr = ((src[srcX] & 0xff0000) >> 16); //��ȡRGB���R
//			int sg = ((src[srcX] & 0xff00) >> 8);   //G
//			int sb = src[srcX] & 0xff;              //B
//			if (ix >= 0 && ix <= graphWidth && iy >= 0 && iy <= graphHeight && dstX <= graphWidth * graphHeight)
//			{
//				dstX = (ix + picture_x) + (iy + picture_y) * graphWidth; //���Դ������صĽǱ�
//				int dr = ((dst[dstX] & 0xff0000) >> 16);
//				int dg = ((dst[dstX] & 0xff00) >> 8);
//				int db = dst[dstX] & 0xff;
//				draw[dstX] = ((sr * sa / 255 + dr * (255 - sa) / 255) << 16)  //��ʽ�� Cp=��p*FP+(1-��p)*BP  �� ��p=sa/255 , FP=sr , BP=dr
//					| ((sg * sa / 255 + dg * (255 - sa) / 255) << 8)         //��p=sa/255 , FP=sg , BP=dg
//					| (sb * sa / 255 + db * (255 - sa) / 255);              //��p=sa/255 , FP=sb , BP=db
//			}
//		}
//	}
//}

// ͸��������������ָ����ɫ��Ϊ͸����
void MakeImageTransparent(IMAGE* img, COLORREF transColor)
{
	int width = img->getwidth();
	int height = img->getheight();
	DWORD* buffer = GetImageBuffer(img);

	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {
			int index = y * width + x;
			if (buffer[index] == transColor) {
				buffer[index] &= 0x00FFFFFF; // ��͸������Ϊ 0����ȫ͸����
			}
		}
	}
}
void drawStartPage()
{
	startpage_img.imageload(_T(".\\resources\\images\\startpage.png"));
	startbutton_img.imageload(_T(".\\resources\\images\\startbutton.png"));

	initgraph(windowWidth, windowHeight); // ��ʼ������

	//startpage_img.ShowScalingImage(windowWidth, windowWidth); // ֱ������
	//startbutton_img.ShowScalingImage(STARTBUTTON_WIDTH, STARTBUTTON_HEIGHT); // ֱ������

	player1.map_positionX = 512 / 4;
	player1.map_positionY = 512 / 8;

	gamemap.get_player_view(player1, 512 / 4 * 2, 512 / 8 * 2);

	MainWindow.DrawImg(gamemap.player_view, windowWidth / 2, windowHeight / 2);
	player1.player_image.ShowScalingImage(240);
	MakeImageTransparent(&player1.player_image.PRImg, RGB(0, 0, 0)); // �趨��ɫΪ͸��
	MainWindow.DrawImg(player1.player_image, windowWidth / 2, windowHeight / 2);


	//putimage(0, 0, &startpage_img.PRImg);

	//MainWindow.DrawImg(startpage_img, windowWidth / 2, windowHeight / 2);
	//MainWindow.DrawImg(startbutton_img, windowWidth / 2 - STARTBUTTON_WIDTH / 2, windowHeight / 2 + STARTBUTTON_HEIGHT / 2);

	//MainWindow.RunMessageLoop();  // ������Ϣѭ��
	while (true) {
		if (_kbhit())
		{
			BeginBatchDraw();  // ��ʼ˫����
			cleardevice();     // ��������ֹ�������
			char key = _getch();
			switch (key)
			{
			case 72: // ��
				player1.map_positionY -= 2;
				break;
			case 80: // ��
				player1.map_positionY += 2;
				break;
			case 75: // ��
				player1.map_positionX -= 2;
				break;
			case 77: // �� 
				player1.map_positionX += 2;
				break;
			case 27: // ESC �˳�
				closegraph();
			}
			// ��ʼ˫����
			std::cout << player1.player_image.PRImg.getheight() << player1.player_image.OriginImage.getheight() << std::endl;
			gamemap.get_player_view(player1, 512 / 4 * 2, 512 / 8 * 2);
			MainWindow.DrawImg(gamemap.player_view, windowWidth / 2, windowHeight / 2);
			MainWindow.DrawImg(player1.player_image, windowWidth / 2, windowHeight / 2);

			EndBatchDraw(); // ����˫���壬ˢ����Ļ
		}
		/*Sleep(10);*/

	}
}
