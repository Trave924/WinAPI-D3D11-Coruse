#pragma once
#include "../WindowWT/WindowWT.h"
#include <d3d11.h>

class Graphics {
	public:
		Graphics(HWND &hwnd);
		~Graphics();
		void Frame();
		void EndFrame();
		void ClearBuffer(float r, float g, float b);

		ID3D11Device* pDevice = nullptr;
		ID3D11DeviceContext* pContext = nullptr;
		IDXGISwapChain* pSwap = nullptr;
		ID3D11RenderTargetView* pTarget = nullptr;

		DXGI_SWAP_CHAIN_DESC sd = { };
		HWND hwnd;
	private:
		
};