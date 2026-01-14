#include "../src/WindowWT/WindowWT.h"

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE, PWSTR, int cmdShow) {
	
	WindowWT wndWT = WindowWT(hInstance, cmdShow);
	wndWT.WT_CreateWndClass(L"MyClassWindowTest");
	wndWT.WT_CreateWindow(L"My Window", 800, 600);
	wndWT.Run();

	return 0;
}