#include "../include/main.h"
#include "../include/IMAGE_PR.h"

void drawStartPage() {

//载入资源
IMAGE_PR startpage_img(_T("..\\resources\\images\\startpage.png"), windowWidth, windowHeight);
IMAGE_PR startbutton_img(_T("..\\resources\\images\\startbutton.png"), STARTBUTTON_WIDTH, STARTBUTTON_HEIGHT);

//渲染窗口
//std::cout << GetSystemMetrics(SM_CXSCREEN) << std::endl;
Window MainWindow(windowWidth, windowHeight, 0, 0);

MainWindow.DrawImg(startpage_img, windowWidth / 2, windowHeight / 2);
MainWindow.DrawImg(startbutton_img, STARTBUTTON_X, STARTBUTTON_Y);


}
