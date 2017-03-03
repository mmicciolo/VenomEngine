#include "GraphicsManager.h"

namespace VenomEngine {
	GraphicsManager::GraphicsManager() {
		SetType(GRAPHICS_MANAGER);
		Init();
		ConsoleManager::Instance()->WriteAll("Graphics Manager Starting...\n");
	}

	bool GraphicsManager::Init() {
		return true;
	}

	void GraphicsManager::Update() {

	}

	bool GraphicsManager::Shutdown() {
		return true;
	}

	bool GraphicsManager::InitGraphicsSubSystem() {
		renderer = new Direct3D10Renderer();
		Direct3D10Renderer * r = (Direct3D10Renderer *)renderer;
		WindowManager * wm = WindowManager::Instance();
		r->InitDevice(wm->GetWidth(), wm->GetHeight(), false, wm->GetWindow(), false, 1000.0f, 0.1f);
		return true;
	}

	void GraphicsManager::Render() {
		renderer->Begin();
		SceneManager::Instance()->RenderScene();
		renderer->End();
	}

	IVenomRenderer * GraphicsManager::GetRenderer() {
		return renderer;
	}
}