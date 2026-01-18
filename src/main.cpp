#include "../src/WindowWT/WindowWT.h"



int APIENTRY wWinMain(HINSTANCE hInstance, HINSTANCE, PWSTR, int cmdShow) {
	
	WindowWT wndWT = WindowWT(hInstance, cmdShow);
	wndWT.WT_CreateWndClass(L"MyClassWindowTest");
	wndWT.WT_CreateWindowOverlay();
	wndWT.Run();
	

	return 0;
}