/*
File : Direct3D11Renderer.h
Author: Matthew Micciolo

This class implments the IVenomRenderer Interface.
*/

#ifndef __DIRECT3D11_RENDERER_
#define __DIRECT3D11_RENDERER_

#include "../Graphics/IVenomRenderer.h"
#include <Windows.h>
#include <d3d10.h>
#include <d3dx10.h>
#include <vector>
#include "../Object/Model/Model.h"
#include "../Graphics/Buffers/Direct3D10/Direct3D10VertexBuffer.h"
#include "../Graphics/Buffers/Direct3D10/Direct3D10IndexBuffer.h"
//#include "../Managers/SceneManager.h"


struct Vertex
{
	D3DXVECTOR3 pos;
};

namespace VenomEngine {
	class Direct3D10Renderer : public IVenomRenderer {
	public:
		Direct3D10Renderer();
		~Direct3D10Renderer() {};
		bool Init();
		bool Shutdown();
		bool InitDevice(int width, int height, bool vsync, HWND hwnd, bool fullscreen, float screenDepth, float screenNear);
		void Begin();
		void End();
		void CreateMesh(ID3DX10Mesh ** mesh, ID3D10EffectTechnique ** technique, ID3D10EffectMatrixVariable ** fxWVPvar, ID3D10Effect ** fx, ID3D10InputLayout ** vertexLayout, Direct3D10VertexBuffer * vertexBuffer, Direct3D10IndexBuffer * indexBuffer);
	protected:
	private:
		int width, height;
		IDXGISwapChain *        pSwapChain;
		ID3D10RenderTargetView*        pRenderTargetView;
		ID3D10Device*                pDevice;
		D3DXMATRIX WVP;
		D3DXMATRIX Projection;
		std::vector<Model *> models;
	};
}

#endif