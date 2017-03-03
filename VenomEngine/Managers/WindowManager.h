/*
File : WindowManager.h
Author: Matthew Micciolo

This class provides all of the functions in order to interact with the game engine
window on the screen.
*/

#ifndef __WINDOW_MANAGER_
#define __WINDOW_MANAGER_

#include "Manager.h"
#include "../Engine/EngineDefs.h"
#include "InputManager.h"
#include "../Common/Singleton.h"
#include "ConsoleManager.h"
#include "GraphicsManager.h"
#include <Windows.h>

namespace VenomEngine {
	class WindowManager : public Manager, public Singleton<WindowManager> {
	public:
		enum WindowType { WINDOW_TITLEBAR, WINDOW_RESIZEABLE, WINDOW_HIDDEN, WINDOW_FULLSCREEN };
		WindowManager();
		~WindowManager() {};
		bool Init();
		void Update();
		bool Shutdown();
		bool Create(std::string title, int x, int y, int width, int height, WindowType windowType);
		bool Close();
		int GetXPosition();
		int GetYPosition();
		int GetHeight();
		int GetWidth();
		void Hide();
		void Show();
		HWND GetWindow();
		static LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);
	protected:
	private:
		int height;
		int width;
		WNDCLASSEX wc;
		HINSTANCE hInstance;
		HWND hwnd;
		MSG Msg;
	};
}
#endif