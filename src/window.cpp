#include "../include/window.h"
Window::Window(int Width, int Height, int X , int Y,bool isfullscreen ) : isFullscreen(isfullscreen),  originalRect ( { X, Y, X + Width, Y + Height })
{
    // ��ʼ��ʱȫ��״̬Ϊ false
    initgraph(Width, Height);
    name = GetHWnd(); // ��ȡ���ھ��
	MoveWindow(name, X, Y, Width, Height, TRUE);
    
}
void Window::ToggleFullscreen() {
	
    if (!isFullscreen) {
        // ����ȫ��ģʽ
		std::cout << originalRect.left<< std::endl;
        GetWindowRect(name, &originalRect); // ����ԭʼ����λ�úʹ�С
        SetWindowLong(name, GWL_STYLE, WS_POPUP | WS_VISIBLE); // �Ƴ����ڱ߿�
        ShowWindow(name, SW_MAXIMIZE); // ��󻯴���
        isFullscreen = true;
    }
    else {
        // �˳�ȫ��ģʽ
        SetWindowLong(name, GWL_STYLE, WS_OVERLAPPEDWINDOW | WS_VISIBLE); // �ָ����ڱ߿�
        SetWindowPos(name, NULL, originalRect.left, originalRect.top,
            originalRect.right - originalRect.left,
            originalRect.bottom - originalRect.top, SWP_NOZORDER); // �ָ�ԭʼ��С��λ��
        isFullscreen = false;
    }
}


bool Window::IsFullscreen()  {
    return isFullscreen;
}
void Window::DrawImg(const IMAGE_PR Myimg, int X, int Y)
{
    //std::cout << Myimg.width_Img<< Myimg.height_Img << std::endl;
   /* putimage(X, Y, &Myimg.PRImg);*/
    putimage(X- Myimg.PRImg.getwidth()/2, Y- Myimg.PRImg.getheight()/2,&Myimg.PRImg);
}