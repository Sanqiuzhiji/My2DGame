#include "../include/window.h"


// ���캯��
Window::Window(int w, int h)
	: width(w), height(h), hwnd(nullptr){
	std::cout << "Window �����Ѵ���!" << std::endl;
}
// ��������
Window::~Window() {
	closegraph();  // �ر� EasyX ͼ�δ���
}

bool Window::InitWindow(int width, int height)
{
	//// **ʹ�� EasyX ��������**
	//initgraph(width, height);

	//LONG style = GetWindowLong(hwnd, GWL_STYLE);
	//style |= WS_MAXIMIZEBOX | WS_SIZEBOX;  // ������󻯡�������С
	//SetWindowLong(hwnd, GWL_STYLE, style);

	////���ô��ڹ���
	//SetWindowLongPtr(hwnd, GWLP_WNDPROC, (LONG_PTR)WindowProc);
	//// ���� GWLP_USERDATA Ϊ��ǰ Window ����ָ��
	//SetWindowLongPtr(hwnd, GWLP_USERDATA, reinterpret_cast<LONG_PTR>(this));
	//// ��ʾ����
	//ShowWindow(hwnd, SW_SHOW);

	initgraph(width, height);  // ��ʼ�� EasyX ͼ�δ���
	hwnd = GetHWnd();  // ��ȡ EasyX �����Ĵ��ھ��	
	//// ȷ�� hwnd ����ȷ��ʼ��
	//if (hwnd == nullptr) {
	//	std::cout << "��ȡ���ھ��ʧ��!" << std::endl;
	//	return false;
	//}
	//SetForegroundWindow(hwnd);   // �ô����ö�
	//SetFocus(hwnd);              // �ô��ڻ�ȡ����
	setbkcolor(WHITE);         // ���ñ�����ɫ
	std::cout << "���ڳ�ʼ�����: " << std::endl;
	return true;
}

// �����¼�����ꡢ���̵ȣ�
void Window::ProcessEvents() {
	ExMessage msg;
	if (peekmessage(&msg, EM_MOUSE | EM_KEY)) {  // �������ͼ����¼�
		if (msg.message == WM_LBUTTONDOWN) {
			std::cout << "�����: (" << msg.x << ", " << msg.y << ")" << std::endl;
		}
		if (msg.message == WM_KEYDOWN) {
			std::cout << "��������: " << msg.vkcode << std::endl;
			if (msg.vkcode == VK_ESCAPE) {
				closegraph();
				exit(0);
			}
		}
	}
}

void Window::DestroyWindow() {
	if (hwnd) {
		// ���ٴ��ڵĴ���
		closegraph();
		hwnd = nullptr;  // ȷ�����ٺ�ָ����Ϊ nullptr
	}
}
 //�����Ƿ���Ȼ��
bool Window::IsOpen()
{
	if (hwnd == nullptr) 
	{
		return false;  // ����δ��
	}
	// ������Լ�һЩ������߼���� hwnd �Ƿ���Ȼ��Ч
	return true;
}
//void Window::ToggleFullScreen()
//{
//	RECT rect;
//	if (isFullScreen) {
//		// �����ǰ��ȫ��״̬���ָ�Ϊ��ͨ����
//		isFullScreen = false;
//
//		closegraph();
//		InitWindow();
//		// ���ز�����ȫ��ͼƬ����ʱ�����Ѿ�Ϊȫ����
//	/*	startpage_img.ShowScalingImage(windowWidth, windowHeight);
//		DrawImg(startpage_img, windowWidth / 2, windowHeight / 2);*/
//
//		// �ָ�ԭʼ����λ�úʹ�С
//		SetWindowLong(hwnd, GWL_STYLE, WS_OVERLAPPEDWINDOW);  // �ָ��߿�
//		SetWindowPos(hwnd, HWND_TOP, originalRect.left, originalRect.top,
//			originalRect.right - originalRect.left,
//			originalRect.bottom - originalRect.top, SWP_NOZORDER);
//
//		ShowWindow(hwnd, SW_RESTORE); // �ָ�����
//	}
//	else {
//		// ����ȫ��ģʽ
//		isFullScreen = true;
//
//		closegraph();
//		InitWindow();
//
//		// ���ز�����ȫ��ͼƬ����ʱ�����Ѿ�Ϊȫ����
//		//startpage_img.ShowScalingImage(GetSystemMetrics(SM_CXSCREEN), GetSystemMetrics(SM_CYSCREEN));
//		//DrawImg(startpage_img, GetSystemMetrics(SM_CXSCREEN) / 2, GetSystemMetrics(SM_CYSCREEN) / 2);
//
//		// ��ȡ��Ļ�Ĺ���������������������
//		SystemParametersInfo(SPI_GETWORKAREA, 0, &rect, 0);
//
//		// ȥ�����ڱ߿�
//		//SetWindowLong(hwnd, GWL_STYLE, GetWindowLong(hwnd, GWL_STYLE) & ~WS_OVERLAPPEDWINDOW);
//
//		// ���ô���Ϊȫ��������������Ļ
//		SetWindowPos(hwnd, HWND_TOP, rect.left, rect.top,
//			rect.right - rect.left, rect.bottom - rect.top, SWP_NOZORDER);
//
//		ShowWindow(hwnd, SW_MAXIMIZE); // ��ʾȫ��״̬
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
//		else return DefWindowProc(hwnd, uMsg, wParam, lParam); // ��������ϵͳ����
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
//			// ������ڱ���󻯣�����ȫ��ģʽ
//			if (!isFullScreen) {
//				ToggleFullScreen();
//			}
//		}
//		else if (wParam == SIZE_RESTORED) {
//			// ������ڱ��ָ����˳�ȫ��ģʽ
//			if (isFullScreen) {
//				ToggleFullScreen();
//			}
//		}
//		break;
//
//	case WM_DESTROY:
//		PostQuitMessage(0);  // �رմ���ʱ�˳�Ӧ�ó���
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
//	FlushBatchDraw();  // ��ˢ��һ�£�ȷ������״̬����
//	putimage(X - Myimg.PRImg.getwidth() / 2, Y - Myimg.PRImg.getheight() / 2, &Myimg.PRImg);
//}

