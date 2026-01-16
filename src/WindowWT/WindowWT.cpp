#include "WindowWT.h"
#include "../Graphics/graphics.h"

LRESULT CALLBACK WindowWT::WinProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
	switch (uMsg) {
		case WM_CLOSE:
			PostQuitMessage(0);
			break;
		case WM_DESTROY:
			PostQuitMessage(0);
			return 0;
	}

	return DefWindowProc(hwnd, uMsg, wParam, lParam);
}

bool WindowWT::WT_CreateWndClass(LPCWSTR className) {
	this->className = className;

	wc.lpszClassName = className;
	wc.hInstance = hInstance;
	wc.cbSize = sizeof(WNDCLASSEX);
	wc.lpfnWndProc = WinProc;

	if (!::RegisterClassEx(&wc)) {
		return false;
	}
	return true;
}

bool WindowWT::WT_CreateWindow(LPCWSTR windowName, int width, int height) {
	hwnd = CreateWindowEx(
		0,
		wc.lpszClassName,
		windowName,
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT, width, height,
		nullptr, nullptr, hInstance, nullptr
	);

	if (hwnd == NULL) {
		return false;
	}

	ShowWindow(hwnd, cmdShow);
	UpdateWindow(hwnd);

	gtx = new Graphics(hwnd);
	return true;
}

int WindowWT::Run() {
	bool running = true;
	MSG msg = { };
	while (running) {
		while (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE)) {
			TranslateMessage(&msg);
			DispatchMessage(&msg);

			if (msg.message == WM_QUIT) {
				running = false;
			}
		}
		gtx->Frame();

		if (!running)
			break;

		Sleep(100); // 16 = 60fps
	}

	return 0;
}

WindowWT::WindowWT(HINSTANCE hInst, int cs) : hInstance(hInst), cmdShow(cs) {
	
}

