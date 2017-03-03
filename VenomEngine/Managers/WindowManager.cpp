#include "WindowManager.h"

namespace VenomEngine {
	WindowManager::WindowManager() {
		SetType(WINDOW_MANAGER);
		ConsoleManager::Instance()->WriteAll("Window Manager Starting...\n");
	}

	bool WindowManager::Init() {
		return true;
	}

	void WindowManager::Update() {
		if (PeekMessage(&Msg, 0, 0, 0, PM_REMOVE) > 0) {
			TranslateMessage(&Msg);
			DispatchMessage(&Msg);
		}
	}

	bool WindowManager::Shutdown() {
		Close();
		return true;
	}

	LRESULT CALLBACK WindowManager::WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
	{
		switch (msg)
		{
		case WM_KEYDOWN:
			InputManager::Instance()->KeyDown((VenomKey)wParam);
			break;
		case WM_KEYUP:
			InputManager::Instance()->KeyUp((VenomKey)wParam);
			break;
		case WM_CLOSE:
			DestroyWindow(hwnd);
			break;
		case WM_DESTROY:
			PostQuitMessage(0);
			break;
		default:
			return DefWindowProc(hwnd, msg, wParam, lParam);
		}
		return 0;
	}

	bool WindowManager::Create(std::string title, int x, int y, int width, int height, WindowType windowType) {

		this->height = height;
		this->width = width;

		//Create the window class
		wc.cbSize = sizeof(WNDCLASSEX);
		wc.style = 0;
		wc.lpfnWndProc = WndProc;
		wc.cbClsExtra = 0;
		wc.cbWndExtra = 0;
		wc.hInstance = hInstance;
		wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
		wc.hCursor = LoadCursor(NULL, IDC_ARROW);
		wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
		wc.lpszMenuName = NULL;
		wc.lpszClassName = L"Venom Window";
		wc.hIconSm = LoadIcon(NULL, IDI_APPLICATION);

		if (!RegisterClassEx(&wc)) {
			MessageBox(NULL, L"Window Registration Failed!", L"Error!", MB_ICONEXCLAMATION | MB_OK);
			return false;
		}

		//Create the actual window
		std::wstring stemp = std::wstring(title.begin(), title.end());
		hwnd = CreateWindowEx(WS_EX_CLIENTEDGE, L"Venom Window", (LPCWSTR)stemp.c_str(), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, width, height, NULL, NULL, hInstance, NULL);

		if (hwnd == NULL) {
			MessageBox(NULL, L"Window Creation Failed!", L"Error!", MB_ICONEXCLAMATION | MB_OK);
			return false;
		}

		ShowWindow(hwnd, 1);
		UpdateWindow(hwnd);

		ConsoleManager::Instance()->WriteAll("Window Created...\n");
		ConsoleManager::Instance()->WriteAll("Initializing Renderer...\n");

		if (!GraphicsManager::Instance()->InitGraphicsSubSystem()) {
			return false;
		}

		return true;

	}

	bool WindowManager::Close() {
		CloseWindow(hwnd);
		return true;
	}

	int WindowManager::GetXPosition() {
		return 0;
	}

	int WindowManager::GetYPosition() {
		return 0;
	}

	int WindowManager::GetHeight() {
		return height;
	}

	int WindowManager::GetWidth() {
		return width;
	}

	void WindowManager::Hide() {
		ShowWindow(hwnd, 0);
	}

	void WindowManager::Show() {
		ShowWindow(hwnd, 1);
	}

	HWND WindowManager::GetWindow() {
		return hwnd;
	}
}
