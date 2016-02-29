#include <Windows.h>
#include <stdio.h>

LRESULT CALLBACK WinSunProc
(
	HWND hwnd,
	UINT uMsg,

	WPARAM wParam,
	LPARAM lParam
	);

int WINAPI WinMain
(
	HINSTANCE hInstance,
	HINSTANCE hPrevInstance,

	LPSTR lpCmdLine,
	int nCmdShow)
{
	WNDCLASS wndcls;
	wndcls.cbClsExtra = 0;
	wndcls.cbWndExtra = 0;

	wndcls.hbrBackground = (HBRUSH)GetStockObject(GRAY_BRUSH);
	wndcls.hCursor = LoadCursor(NULL, IDC_CROSS);

	wndcls.hIcon = LoadIcon(NULL, IDI_ERROR);
	wndcls.hInstance = hInstance;

	wndcls.lpfnWndProc = WinSunProc;
	wndcls.lpszClassName = "I love GitHub";

	wndcls.lpszMenuName = NULL;
	wndcls.style = CS_HREDRAW | CS_VREDRAW;

	RegisterClass(&wndcls);
	HWND hwnd;

	hwnd = CreateWindow(
		"I love GitHub",
		"I love GitHub",
		WS_OVERLAPPEDWINDOW,

		0,
		0,
		800,
		800,

		NULL,
		NULL,
		hInstance,
		NULL);
	ShowWindow(hwnd, SW_SHOWNORMAL);
	UpdateWindow(hwnd);
	MSG msg;

	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return 0;
}
LRESULT CALLBACK WinSunProc(
	HWND hwnd,
	UINT uMsg,

	WPARAM wParam,
	LPARAM lParam
	)
{
	switch (uMsg)
	{
	case WM_PAINT:
	{
		HDC hDC;
		PAINTSTRUCT ps;

		hDC = BeginPaint(hwnd, &ps);
		TextOut(hDC, 200, 0, "我来到了GitHub", strlen("我来到了GitHub"));

		EndPaint(hwnd, &ps);
		break;
	}
	case WM_CLOSE:
	{
		if (IDYES == MessageBoxA(hwnd, "是否真的退出？", "来自GitHub的消息", MB_YESNO))
		{

			DestroyWindow(hwnd);

		}

		break;
	}
	case WM_DESTROY:
	{
		PostQuitMessage(0);

		break;
	}

	default:
	{
		return DefWindowProc(hwnd, uMsg, wParam, lParam);
	}
	}




	return 0;
}
