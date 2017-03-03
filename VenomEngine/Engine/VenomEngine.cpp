#include "VenomEngine.h"

namespace VenomEngine {
	Engine::Engine() {
	}

	Engine::~Engine() {

	}

	void Engine::Init() {

		//Init the managers
		managers.push_back((Manager *)ConsoleManager::Instance());
		managers.push_back((Manager *)ApplicationManager::Instance());
		managers.push_back((Manager *)WindowManager::Instance());
		managers.push_back((Manager *)InputManager::Instance());
		managers.push_back((Manager *)GraphicsManager::Instance());
		managers.push_back((Manager *)SceneManager::Instance());
	}

	void Engine::Update() {
		for (unsigned int i = 0; i < managers.size(); i++) {
			managers[i]->Update();
		}
	}

	void Engine::Shutdown() {
		for (unsigned int i = 0; i < managers.size(); i++) {
			managers[i]->Shutdown();
		}
		running = false;
	}

	void Engine::Quit() {
		running = false;
	}

	bool Engine::CreateApplicationWindowAndRenderer(std::string title, int x, int y, int width, int height, WindowManager::WindowType windowType) {
		return WindowManager::Instance()->Create(title, x, y, width, height, windowType);
	}

	Manager * Engine::GetManager(std::string type) {
		for (unsigned int i = 0; i < managers.size(); i++) {
			if (managers[i]->GetType().compare(type) == 0) {
				return managers[i];
			}
		}
		return NULL;
	}

	bool Engine::getRunning() {
		return running;
	}
}
