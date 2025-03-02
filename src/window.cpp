#include "../include/window.h"
Window::Window(int Width, int Height, int X , int Y,bool isfullscreen ) : isFullscreen(isfullscreen),  originalRect ( { X, Y, X + Width, Y + Height })
{
    // 初始化时全屏状态为 false
    initgraph(Width, Height);
    name = GetHWnd(); // 获取窗口句柄
	MoveWindow(name, X, Y, Width, Height, TRUE);
    
}
void Window::ToggleFullscreen() {
	
    if (!isFullscreen) {
        // 进入全屏模式
		std::cout << originalRect.left<< std::endl;
        GetWindowRect(name, &originalRect); // 保存原始窗口位置和大小
        SetWindowLong(name, GWL_STYLE, WS_POPUP | WS_VISIBLE); // 移除窗口边框
        ShowWindow(name, SW_MAXIMIZE); // 最大化窗口
        isFullscreen = true;
    }
    else {
        // 退出全屏模式
        SetWindowLong(name, GWL_STYLE, WS_OVERLAPPEDWINDOW | WS_VISIBLE); // 恢复窗口边框
        SetWindowPos(name, NULL, originalRect.left, originalRect.top,
            originalRect.right - originalRect.left,
            originalRect.bottom - originalRect.top, SWP_NOZORDER); // 恢复原始大小和位置
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