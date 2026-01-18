#pragma once
#include <Windows.h>

class Graphics;

class WindowWT {
	public:
		static LRESULT CALLBACK WinProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
		bool WT_CreateWndClass(LPCWSTR className);
		bool WT_CreateWindow(LPCWSTR windowName, int width, int height);
		bool WT_CreateWindowOverlay();
		int Run();

		WindowWT(HINSTANCE hInst , int cs);

		~WindowWT() {
			::UnregisterClass(wc.lpszClassName, hInstance);
		}
		HWND hwnd;
	private:

		WNDCLASSEX wc;
		LPCWSTR className;
		HINSTANCE hInstance;
		int cmdShow;
		Graphics* gtx;
};