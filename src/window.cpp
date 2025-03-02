#include "../include/window.h"

Window::Window(int Width, int Height, int X, int Y, bool fullscreen) : isFullScreen(fullscreen), originalRect({ X, Y, X + Width, Y + Height })
{
}

Window::~Window()
{
	// ��������ʱ��������������Ҫ��
}

bool Window::InitWindow(int width, int height)
{
	// **ʹ�� EasyX ��������**
	initgraph(width, height);
	hwnd = GetHWnd();  // ��ȡ EasyX �����Ĵ��ھ��

	LONG style = GetWindowLong(hwnd, GWL_STYLE);
	style |= WS_MAXIMIZEBOX | WS_SIZEBOX;  // ������󻯡�������С
	SetWindowLong(hwnd, GWL_STYLE, style);

	//���ô��ڹ���
	SetWindowLongPtr(hwnd, GWLP_WNDPROC, (LONG_PTR)WindowProc);
	// ���� GWLP_USERDATA Ϊ��ǰ Window ����ָ��
	SetWindowLongPtr(hwnd, GWLP_USERDATA, reinterpret_cast<LONG_PTR>(this));
	// ��ʾ����
	ShowWindow(hwnd, SW_SHOW);

	return true;
}

void Window::ToggleFullScreen()
{
	RECT rect;
	if (isFullScreen) {
		// �����ǰ��ȫ��״̬���ָ�Ϊ��ͨ����
		isFullScreen = false;

		closegraph();
		InitWindow(windowWidth, windowHeight);

		// ���ز�����ȫ��ͼƬ����ʱ�����Ѿ�Ϊȫ����
		startpage_img.ShowScalingImage(windowWidth, windowHeight);
		DrawImg(startpage_img, windowWidth / 2, windowHeight / 2);

		// �ָ�ԭʼ����λ�úʹ�С
		SetWindowLong(hwnd, GWL_STYLE, WS_OVERLAPPEDWINDOW);  // �ָ��߿�
		SetWindowPos(hwnd, HWND_TOP, originalRect.left, originalRect.top,
			originalRect.right - originalRect.left,
			originalRect.bottom - originalRect.top, SWP_NOZORDER);

		ShowWindow(hwnd, SW_RESTORE); // �ָ�����
	}
	else {
		// ����ȫ��ģʽ
		isFullScreen = true;

		closegraph();
		InitWindow(GetSystemMetrics(SM_CXSCREEN), GetSystemMetrics(SM_CYSCREEN));

		// ���ز�����ȫ��ͼƬ����ʱ�����Ѿ�Ϊȫ����
		startpage_img.ShowScalingImage(GetSystemMetrics(SM_CXSCREEN), GetSystemMetrics(SM_CYSCREEN));
		DrawImg(startpage_img, GetSystemMetrics(SM_CXSCREEN) / 2, GetSystemMetrics(SM_CYSCREEN) / 2);

		// ��ȡ��Ļ�Ĺ���������������������
		SystemParametersInfo(SPI_GETWORKAREA, 0, &rect, 0);

		// ȥ�����ڱ߿�
		//SetWindowLong(hwnd, GWL_STYLE, GetWindowLong(hwnd, GWL_STYLE) & ~WS_OVERLAPPEDWINDOW);

		// ���ô���Ϊȫ��������������Ļ
		SetWindowPos(hwnd, HWND_TOP, rect.left, rect.top,
			rect.right - rect.left, rect.bottom - rect.top, SWP_NOZORDER);

		ShowWindow(hwnd, SW_MAXIMIZE); // ��ʾȫ��״̬
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
		else return DefWindowProc(hwnd, uMsg, wParam, lParam); // ��������ϵͳ����
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
			// ������ڱ���󻯣�����ȫ��ģʽ
			if (!isFullScreen) {
				ToggleFullScreen();
			}
		}
		else if (wParam == SIZE_RESTORED) {
			// ������ڱ��ָ����˳�ȫ��ģʽ
			if (isFullScreen) {
				ToggleFullScreen();
			}
		}
		break;

	case WM_DESTROY:
		PostQuitMessage(0);  // �رմ���ʱ�˳�Ӧ�ó���
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

