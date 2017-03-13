/*
File : VenomEngine.h
Author: Matthew Micciolo

Header file for the engine class. Contains most setup and system
calls.
*/

#include <vector>
#include "../Common/Singleton.h"
#include "../Managers/WindowManager.h"


#ifndef __VENOM_ENGINE_
#define __VENOM_ENGINE_

namespace VenomEngine {
	class Engine : public Singleton<Engine> {
	public:
		Engine();
		~Engine();
		void Init();
		void Update();
		void Shutdown();
		void Quit();
		bool CreateApplicationWindowAndRenderer(std::string title, int x, int y, int width, int height, WindowManager::WindowType windowType);
		Manager * GetManager(std::string type);
		bool getRunning();
	protected:
	private:
		std::vector<Manager *> managers;
		bool running = true;
	};
}

#endif