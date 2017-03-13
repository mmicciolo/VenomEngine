#include "InputManager.h"
#include "ConsoleManager.h"
#include "../Engine/EngineDefs.h"

namespace VenomEngine {
	InputManager::InputManager() {
		SetType(INPUT_MANAGER);
		Init();
	}

	bool InputManager::Init() {
		ConsoleManager::Instance()->WriteAll("Input Manager Starting...\n");
		return true;
	}

	void InputManager::Update() {

	}

	bool InputManager::Shutdown() {
		return true;
	}

	void InputManager::KeyDown(VenomKey key) {

	}

	void InputManager::KeyUp(VenomKey key) {

	}
}