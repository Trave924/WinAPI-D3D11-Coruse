#pragma once
#include <Windows.h>

class WindowWT {
	public:
		static LRESULT CALLBACK WinProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
		bool WT_CreateWndClass(LPCWSTR className);
		bool WT_CreateWindow(LPCWSTR windowName, int width, int height);
		int Run();

		WindowWT(HINSTANCE hInst , int cs) : hInstance(hInst) , cmdShow(cs) {

		}

		~WindowWT() {
			::UnregisterClass(wc.lpszClassName, hInstance);
		}
	private:

		WNDCLASSEX wc;
		LPCWSTR className;
		HINSTANCE hInstance;
		int cmdShow;
		HWND hwnd;
};