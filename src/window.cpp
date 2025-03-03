#include "../include/window.h"


// 构造函数
Window::Window(int w, int h)
	: width(w), height(h), hwnd(nullptr){
	std::cout << "Window 对象已创建!" << std::endl;
}
// 析构函数
Window::~Window() {
	closegraph();  // 关闭 EasyX 图形窗口
}

bool Window::InitWindow(int width, int height)
{
	//// **使用 EasyX 创建窗口**
	//initgraph(width, height);

	//LONG style = GetWindowLong(hwnd, GWL_STYLE);
	//style |= WS_MAXIMIZEBOX | WS_SIZEBOX;  // 允许最大化、调整大小
	//SetWindowLong(hwnd, GWL_STYLE, style);

	////设置窗口过程
	//SetWindowLongPtr(hwnd, GWLP_WNDPROC, (LONG_PTR)WindowProc);
	//// 设置 GWLP_USERDATA 为当前 Window 对象指针
	//SetWindowLongPtr(hwnd, GWLP_USERDATA, reinterpret_cast<LONG_PTR>(this));
	//// 显示窗口
	//ShowWindow(hwnd, SW_SHOW);

	initgraph(width, height);  // 初始化 EasyX 图形窗口
	hwnd = GetHWnd();  // 获取 EasyX 创建的窗口句柄	
	//// 确保 hwnd 被正确初始化
	//if (hwnd == nullptr) {
	//	std::cout << "获取窗口句柄失败!" << std::endl;
	//	return false;
	//}
	//SetForegroundWindow(hwnd);   // 让窗口置顶
	//SetFocus(hwnd);              // 让窗口获取焦点
	setbkcolor(WHITE);         // 设置背景颜色
	std::cout << "窗口初始化完成: " << std::endl;
	return true;
}

// 处理事件（鼠标、键盘等）
void Window::ProcessEvents() {
	ExMessage msg;
	if (peekmessage(&msg, EM_MOUSE | EM_KEY)) {  // 监听鼠标和键盘事件
		if (msg.message == WM_LBUTTONDOWN) {
			std::cout << "鼠标点击: (" << msg.x << ", " << msg.y << ")" << std::endl;
		}
		if (msg.message == WM_KEYDOWN) {
			std::cout << "按键按下: " << msg.vkcode << std::endl;
			if (msg.vkcode == VK_ESCAPE) {
				closegraph();
				exit(0);
			}
		}
	}
}

void Window::DestroyWindow() {
	if (hwnd) {
		// 销毁窗口的代码
		closegraph();
		hwnd = nullptr;  // 确保销毁后指针置为 nullptr
	}
}
 //窗口是否仍然打开
bool Window::IsOpen()
{
	if (hwnd == nullptr) 
	{
		return false;  // 窗口未打开
	}
	// 这里可以加一些额外的逻辑检查 hwnd 是否仍然有效
	return true;
}
//void Window::ToggleFullScreen()
//{
//	RECT rect;
//	if (isFullScreen) {
//		// 如果当前是全屏状态，恢复为普通窗口
//		isFullScreen = false;
//
//		closegraph();
//		InitWindow();
//		// 加载并绘制全屏图片（此时窗口已经为全屏）
//	/*	startpage_img.ShowScalingImage(windowWidth, windowHeight);
//		DrawImg(startpage_img, windowWidth / 2, windowHeight / 2);*/
//
//		// 恢复原始窗口位置和大小
//		SetWindowLong(hwnd, GWL_STYLE, WS_OVERLAPPEDWINDOW);  // 恢复边框
//		SetWindowPos(hwnd, HWND_TOP, originalRect.left, originalRect.top,
//			originalRect.right - originalRect.left,
//			originalRect.bottom - originalRect.top, SWP_NOZORDER);
//
//		ShowWindow(hwnd, SW_RESTORE); // 恢复窗口
//	}
//	else {
//		// 进入全屏模式
//		isFullScreen = true;
//
//		closegraph();
//		InitWindow();
//
//		// 加载并绘制全屏图片（此时窗口已经为全屏）
//		//startpage_img.ShowScalingImage(GetSystemMetrics(SM_CXSCREEN), GetSystemMetrics(SM_CYSCREEN));
//		//DrawImg(startpage_img, GetSystemMetrics(SM_CXSCREEN) / 2, GetSystemMetrics(SM_CYSCREEN) / 2);
//
//		// 获取屏幕的工作区（不包括任务栏）
//		SystemParametersInfo(SPI_GETWORKAREA, 0, &rect, 0);
//
//		// 去掉窗口边框
//		//SetWindowLong(hwnd, GWL_STYLE, GetWindowLong(hwnd, GWL_STYLE) & ~WS_OVERLAPPEDWINDOW);
//
//		// 设置窗口为全屏，覆盖整个屏幕
//		SetWindowPos(hwnd, HWND_TOP, rect.left, rect.top,
//			rect.right - rect.left, rect.bottom - rect.top, SWP_NOZORDER);
//
//		ShowWindow(hwnd, SW_MAXIMIZE); // 显示全屏状态
//	}
//}

//void Window::RunMessageLoop()
//{
//	MSG msg;
//	while (GetMessage(&msg, NULL, 0, 0))
//	{
//		TranslateMessage(&msg);
//		DispatchMessage(&msg);
//	}
//}
//
//LRESULT CALLBACK Window::WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
//{
//	Window* pWnd = reinterpret_cast<Window*>(GetWindowLongPtr(hwnd, GWLP_USERDATA));
//	if (!pWnd)
//		return DefWindowProc(hwnd, uMsg, wParam, lParam);
//	switch (uMsg) {
//	case WM_KEYDOWN:
//		if (wParam == VK_F11)
//		{
//			pWnd->ToggleFullScreen();
//		}
//		break;
//
//	case WM_SYSCOMMAND:
//		if ((wParam & 0xFFF0) == SC_MAXIMIZE)
//		{
//			pWnd->ToggleFullScreen();
//		}
//		else if ((wParam & 0xFFF0) == SC_RESTORE)
//		{
//			pWnd->ToggleFullScreen();
//		}
//		else return DefWindowProc(hwnd, uMsg, wParam, lParam); // 处理其他系统命令
//		break;
//	case WM_DESTROY:
//		PostQuitMessage(0);
//		break;
//
//	default:
//		return DefWindowProc(hwnd, uMsg, wParam, lParam);
//	}
//	return 0;
//}
//
//LRESULT Window::HandleMessages(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
//{
//	std::cout << "WindowProc" << std::endl;
//	switch (uMsg) {
//	case WM_SIZE:
//		if (wParam == SIZE_MAXIMIZED) {
//			// 如果窗口被最大化，进入全屏模式
//			if (!isFullScreen) {
//				ToggleFullScreen();
//			}
//		}
//		else if (wParam == SIZE_RESTORED) {
//			// 如果窗口被恢复，退出全屏模式
//			if (isFullScreen) {
//				ToggleFullScreen();
//			}
//		}
//		break;
//
//	case WM_DESTROY:
//		PostQuitMessage(0);  // 关闭窗口时退出应用程序
//		break;
//
//	default:
//		return DefWindowProc(hwnd, uMsg, wParam, lParam);
//	}
//	return 0;
//}


//void Window::DrawImg(IMAGE_PR& Myimg, int X, int Y)
//{
//	image_positionX = X;
//	image_positionY = Y;
//	FlushBatchDraw();  // 先刷新一下，确保窗口状态正常
//	putimage(X - Myimg.PRImg.getwidth() / 2, Y - Myimg.PRImg.getheight() / 2, &Myimg.PRImg);
//}

