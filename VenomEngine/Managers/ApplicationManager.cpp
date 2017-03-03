#include "ApplicationManager.h"

namespace VenomEngine {
	ApplicationManager::ApplicationManager() {
		SetType(APPLICATION_MANAGER);
		Init();
	}

	bool ApplicationManager::Init() {
		return true;
	}

	void ApplicationManager::Update() {

		//Get the current time
		mainLoopClock.delta();

		SceneManager::Instance()->UpdateScene();
		GraphicsManager::Instance()->Render();

		//Sounds
		//Etc

		//Get the current time again and sleep in order to maintain
		//FRAME_TIME_DEFAULT
		mainLoopTime = mainLoopClock.split();
		if (!(FRAME_TIME_DEFAULT - mainLoopTime <= 0)) {
			Sleep(FRAME_TIME_DEFAULT - mainLoopTime);
		}
	}

	bool ApplicationManager::Shutdown() {
		return true;
	}
}