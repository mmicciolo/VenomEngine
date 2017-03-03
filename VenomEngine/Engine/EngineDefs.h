/*
File : EngineDefs.h
Author: Matthew Micciolo

Provides default values for engine.
*/

#ifndef __ENGINE_DEFS_
#define __ENGINE_DEFS_

#include <string>

namespace VenomEngine {
	static const int FRAME_TIME_DEFAULT = 33;
	static const int SCREEN_WIDTH = 800;
	static const int SCREEN_HEIGHT = 600;

	static const std::string CONSOLE_MANAGER = "Console Manager";
	static const std::string APPLICATION_MANAGER = "Application Manager";
	static const std::string WINDOW_MANAGER = "Window Manager";
	static const std::string INPUT_MANAGER = "Input Manager";
	static const std::string GRAPHICS_MANAGER = "Graphics Manager";
}

#endif
