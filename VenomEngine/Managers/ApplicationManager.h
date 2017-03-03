/*
File : ApplicationManager.h
Author: Matthew Micciolo

This class provides all of the functions to run the application. This includes updating
the world, display, input, etc.
*/

#ifndef __APPLICATION_MANAGER_
#define __APPLICATION_MANAGER_

#include "Manager.h"
#include "../Common/Singleton.h"
#include "../Engine/Clock.h"
#include "../Engine/EngineDefs.h"
#include "SceneManager.h"
#include "GraphicsManager.h"
#include <Windows.h>

namespace VenomEngine {
	class ApplicationManager : public Manager, public Singleton<ApplicationManager> {
	public:
		ApplicationManager();
		~ApplicationManager() {};
		bool Init();
		void Update();
		bool Shutdown();
	protected:
	private:
		Clock mainLoopClock;
		long int mainLoopTime;
	};
}

#endif