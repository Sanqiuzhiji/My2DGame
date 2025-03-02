#include "../include/window.h"

Window::Window(int Width, int Height, int X, int Y, bool fullscreen) : isFullScreen(fullscreen), originalRect({ X, Y, X + Width, Y + Height })
{
}

Window::~Window()
{
	// 窗口销毁时的清理工作（如需要）
}

bool Window::InitWindow(int width, int height)
{
	// **使用 EasyX 创建窗口**
	initgraph(width, height);
	hwnd = GetHWnd();  // 获取 EasyX 创建的窗口句柄

	LONG style = GetWindowLong(hwnd, GWL_STYLE);
	style |= WS_MAXIMIZEBOX | WS_SIZEBOX;  // 允许最大化、调整大小
	SetWindowLong(hwnd, GWL_STYLE, style);

	//设置窗口过程
	SetWindowLongPtr(hwnd, GWLP_WNDPROC, (LONG_PTR)WindowProc);
	// 设置 GWLP_USERDATA 为当前 Window 对象指针
	SetWindowLongPtr(hwnd, GWLP_USERDATA, reinterpret_cast<LONG_PTR>(this));
	// 显示窗口
	ShowWindow(hwnd, SW_SHOW);

	return true;
}

void Window::ToggleFullScreen()
{
	RECT rect;
	if (isFullScreen) {
		// 如果当前是全屏状态，恢复为普通窗口
		isFullScreen = false;

		closegraph();
		InitWindow(windowWidth, windowHeight);

		// 加载并绘制全屏图片（此时窗口已经为全屏）
		startpage_img.ShowScalingImage(windowWidth, windowHeight);
		DrawImg(startpage_img, windowWidth / 2, windowHeight / 2);

		// 恢复原始窗口位置和大小
		SetWindowLong(hwnd, GWL_STYLE, WS_OVERLAPPEDWINDOW);  // 恢复边框
		SetWindowPos(hwnd, HWND_TOP, originalRect.left, originalRect.top,
			originalRect.right - originalRect.left,
			originalRect.bottom - originalRect.top, SWP_NOZORDER);

		ShowWindow(hwnd, SW_RESTORE); // 恢复窗口
	}
	else {
		// 进入全屏模式
		isFullScreen = true;

		closegraph();
		InitWindow(GetSystemMetrics(SM_CXSCREEN), GetSystemMetrics(SM_CYSCREEN));

		// 加载并绘制全屏图片（此时窗口已经为全屏）
		startpage_img.ShowScalingImage(GetSystemMetrics(SM_CXSCREEN), GetSystemMetrics(SM_CYSCREEN));
		DrawImg(startpage_img, GetSystemMetrics(SM_CXSCREEN) / 2, GetSystemMetrics(SM_CYSCREEN) / 2);

		// 获取屏幕的工作区（不包括任务栏）
		SystemParametersInfo(SPI_GETWORKAREA, 0, &rect, 0);

		// 去掉窗口边框
		//SetWindowLong(hwnd, GWL_STYLE, GetWindowLong(hwnd, GWL_STYLE) & ~WS_OVERLAPPEDWINDOW);

		// 设置窗口为全屏，覆盖整个屏幕
		SetWindowPos(hwnd, HWND_TOP, rect.left, rect.top,
			rect.right - rect.left, rect.bottom - rect.top, SWP_NOZORDER);

		ShowWindow(hwnd, SW_MAXIMIZE); // 显示全屏状态
	}
}

void Window::RunMessageLoop()
{
	MSG msg;
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
}

LRESULT CALLBACK Window::WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	Window* pWnd = reinterpret_cast<Window*>(GetWindowLongPtr(hwnd, GWLP_USERDATA));
	if (!pWnd)
		return DefWindowProc(hwnd, uMsg, wParam, lParam);
	switch (uMsg) {
	case WM_KEYDOWN:
		if (wParam == VK_F11)
		{
			pWnd->ToggleFullScreen();
		}
		break;

	case WM_SYSCOMMAND:
		if ((wParam & 0xFFF0) == SC_MAXIMIZE)
		{
			pWnd->ToggleFullScreen();
		}
		else if ((wParam & 0xFFF0) == SC_RESTORE)
		{
			pWnd->ToggleFullScreen();
		}
		else return DefWindowProc(hwnd, uMsg, wParam, lParam); // 处理其他系统命令
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;

	default:
		return DefWindowProc(hwnd, uMsg, wParam, lParam);
	}
	return 0;
}

LRESULT Window::HandleMessages(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	std::cout << "WindowProc" << std::endl;
	switch (uMsg) {
	case WM_SIZE:
		if (wParam == SIZE_MAXIMIZED) {
			// 如果窗口被最大化，进入全屏模式
			if (!isFullScreen) {
				ToggleFullScreen();
			}
		}
		else if (wParam == SIZE_RESTORED) {
			// 如果窗口被恢复，退出全屏模式
			if (isFullScreen) {
				ToggleFullScreen();
			}
		}
		break;

	case WM_DESTROY:
		PostQuitMessage(0);  // 关闭窗口时退出应用程序
		break;

	default:
		return DefWindowProc(hwnd, uMsg, wParam, lParam);
	}
	return 0;
}


void Window::DrawImg(const IMAGE_PR Myimg, int X, int Y)
{
	putimage(X - Myimg.PRImg.getwidth() / 2, Y - Myimg.PRImg.getheight() / 2, &Myimg.PRImg);
}

