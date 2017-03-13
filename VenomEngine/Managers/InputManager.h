/*
File : InputManager.h
Author: Matthew Micciolo

Header file for all input related things such as keyboard, mouse, controllers, etc.
*/

#ifndef __INPUT_MANAGER_
#define __INPUT_MANAGER_

#include "Manager.h"
#include "../Common/Singleton.h"

namespace VenomEngine {
	enum VenomKey {
		KEY_0 = 48,
		KEY_1,
		KEY_2,
		KEY_3,
		KEY_4,
		KEY_5,
		KEY_6,
		KEY_7,
		KEY_8,
		KEY_9,
		KEY_A = 65,
		KEY_B,
		KEY_C,
		KEY_D,
		KEY_E,
		KEY_F,
		KEY_G,
		KEY_H,
		KEY_I,
		KEY_J,
		KEY_K,
		KEY_L,
		KEY_M,
		KEY_N,
		KEY_O,
		KEY_P,
		KEY_Q,
		KEY_R,
		KEY_S,
		KEY_T,
		KEY_U,
		KEY_V,
		KEY_W,
		KEY_X,
		KEY_Y,
		KEY_Z,
	};

	class InputManager : public Manager, public Singleton<InputManager> {
	public:
		InputManager();
		~InputManager() {};
		bool Init();
		void Update();
		bool Shutdown();
		void KeyDown(VenomKey key);
		void KeyUp(VenomKey key);
	protected:
	private:

	};
}

#endif
