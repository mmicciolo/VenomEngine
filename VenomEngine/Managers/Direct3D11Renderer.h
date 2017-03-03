/*
File : Direct3D11Renderer.h
Author: Matthew Micciolo

This class implments the IVenomRenderer Interface.
*/

#ifndef __DIRECT3D11_RENDERER_
#define __DIRECT3D11_RENDERER_

#include "../Graphics/IVenomRenderer.h"

namespace VenomEngine {
	class Direct3D11Renderer : public IVenomRenderer {
	public:
		//Direct3D11Renderer();
		//~Direct3D11Renderer() {};
		bool Init();
		bool Shutdown();
	protected:
	private:
	};
}

#endif
