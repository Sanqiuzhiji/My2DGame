#include "../include/main.h"
#include "../include/IMAGE_PR.h"

void drawStartPage() {

//������Դ
IMAGE_PR startpage_img(_T("..\\resources\\images\\startpage.png"), windowWidth, windowHeight);
IMAGE_PR startbutton_img(_T("..\\resources\\images\\startbutton.png"), STARTBUTTON_WIDTH, STARTBUTTON_HEIGHT);

//��Ⱦ����
//std::cout << GetSystemMetrics(SM_CXSCREEN) << std::endl;
Window MainWindow(windowWidth, windowHeight, 0, 0);

MainWindow.DrawImg(startpage_img, windowWidth / 2, windowHeight / 2);
MainWindow.DrawImg(startbutton_img, STARTBUTTON_X, STARTBUTTON_Y);


}
