/*
File : GraphicsManager.h
Author: Matthew Micciolo

This class provides all of the functions to render graphics to a window
*/

#ifndef __GRAPHICS_MANAGER_
#define __GRAPHICS_MANAGER_

#include "Manager.h"
#include "../Common/Singleton.h"
#include "../Graphics/IVenomRenderer.h"

namespace VenomEngine {
	class GraphicsManager : public Manager, public Singleton<GraphicsManager> {
	public:
		GraphicsManager();
		~GraphicsManager() {};
		bool Init();
		void Update();
		bool Shutdown();
		bool InitGraphicsSubSystem();
		void Render();
		IVenomRenderer * GetRenderer();
	protected:
	private:
		IVenomRenderer * renderer;
	};
}

#endif
