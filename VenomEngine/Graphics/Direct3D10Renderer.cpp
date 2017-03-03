#include "Direct3D10Renderer.h"

namespace VenomEngine {
	Direct3D10Renderer::Direct3D10Renderer() {
		Init();
	}

	bool Direct3D10Renderer::Init() {
		return true;
	}

	bool Direct3D10Renderer::InitDevice(int width, int height, bool vsync, HWND hwnd, bool fullscreen, float screenDepth, float screenNear) {
		this->width = width; this->height = height;
		DXGI_SWAP_CHAIN_DESC swapChainDesc;
		ZeroMemory(&swapChainDesc, sizeof(swapChainDesc));
		swapChainDesc.BufferCount = 1;
		swapChainDesc.BufferDesc.Width = width;
		swapChainDesc.BufferDesc.Height = height;
		swapChainDesc.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
		swapChainDesc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
		swapChainDesc.OutputWindow = hwnd;
		swapChainDesc.SampleDesc.Count = 1;
		swapChainDesc.SampleDesc.Quality = 0;
		swapChainDesc.Windowed = TRUE;

		if (FAILED(D3D10CreateDeviceAndSwapChain(NULL,
			D3D10_DRIVER_TYPE_HARDWARE, NULL,
			D3D10_CREATE_DEVICE_DEBUG, D3D10_SDK_VERSION, &swapChainDesc,
			&pSwapChain, &pDevice)))
		{
			//Error("Failed to create device and swap chain.");
			return false;
		}

		ID3D10Texture2D *pBackBuffer;
		if (FAILED(pSwapChain->GetBuffer(0, __uuidof(ID3D10Texture2D),
			(LPVOID*)&pBackBuffer)))
		{
			//Error("Failed to create back buffer.");
			return false;
		}

		if (FAILED(pDevice->CreateRenderTargetView(pBackBuffer,
			NULL, &pRenderTargetView)))
		{
			//Error("Failed to create render target view.");
			return false;
		}

		pBackBuffer->Release();

		pDevice->OMSetRenderTargets(1, &pRenderTargetView, NULL);

		D3D10_VIEWPORT vp = { 0, 0, (UINT)width, (UINT)height, 0, 1 };
		pDevice->RSSetViewports(1, &vp);

		return true;
	}

	void Direct3D10Renderer::Begin() {
		float color[4];


		// Setup the color to clear the buffer to.
		color[0] = 0;
		color[1] = 0;
		color[2] = 0;
		color[3] = 1;

		// Clear the back buffer.
		pDevice->ClearRenderTargetView(pRenderTargetView, color);

		// Clear the depth buffer.
		//pDevice->ClearDepthStencilView(m_depthStencilView, D3D10_CLEAR_DEPTH, 1.0f, 0);

		return;
	}

	void Direct3D10Renderer::End() {
		// Present the back buffer to the screen since rendering is complete.
		pSwapChain->Present(0, 0);

		return;
	}

	void Direct3D10Renderer::CreateMesh(ID3DX10Mesh ** mesh, ID3D10EffectTechnique ** technique, ID3D10EffectMatrixVariable ** fxWVPvar, ID3D10Effect ** fx, ID3D10InputLayout ** vertexLayout, Direct3D10VertexBuffer * vertexBuffer, Direct3D10IndexBuffer * indexBuffer) {
		D3D10_INPUT_ELEMENT_DESC layout[] =
		{
			{ "POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 0, D3D10_INPUT_PER_VERTEX_DATA, 0 },
		};

		D3DX10CreateMesh(pDevice, layout, 1, "POSITION", vertexBuffer->VertexCount(), indexBuffer->IndexCount(), D3DX10_MESH_32_BIT, mesh);
		(*mesh)->SetVertexData(0, vertexBuffer->vertices);
		(*mesh)->SetIndexData(indexBuffer->indices, indexBuffer->IndexCount());
		(*mesh)->CommitToDevice();

		D3DX10CreateEffectFromFile(L"vertex.fx", NULL, NULL, "fx_4_0", D3D10_SHADER_ENABLE_STRICTNESS, 0,
			pDevice, NULL, NULL, fx, NULL, NULL);

		*technique = (*fx)->GetTechniqueByName("Tech");

		*fxWVPvar = (*fx)->GetVariableByName("WVP")->AsMatrix();

		D3D10_PASS_DESC PassDesc;
		(*technique)->GetPassByIndex(0)->GetDesc(&PassDesc);

		pDevice->CreateInputLayout(layout, 1, PassDesc.pIAInputSignature,
			PassDesc.IAInputSignatureSize, vertexLayout);

		pDevice->IASetInputLayout((*vertexLayout));

		pDevice->IASetPrimitiveTopology(D3D10_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
	}

	bool Direct3D10Renderer::Shutdown() {
		if (pRenderTargetView)
		{
			pRenderTargetView->Release();
			pRenderTargetView = 0;
		}

		if (pSwapChain)
		{
			pSwapChain->Release();
			pSwapChain = 0;
		}

		if (pDevice)
		{
			pDevice->Release();
			pDevice = 0;
		}
		return true;
	}
}


