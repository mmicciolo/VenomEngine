/*
File : IVenomRenderer.h
Author: Matthew Micciolo

This provides an interface for different renderers
*/

#ifndef __IVENOM_RENDERER_
#define __IVENOM_RENDERER_

namespace VenomEngine {
	class IVenomRenderer {
	public:
		virtual bool Init() { return false; };
		virtual bool Shutdown() { return false; };
		virtual void Begin() {};
		virtual void End() {};
	protected:
	private:

	};
}

#endif

