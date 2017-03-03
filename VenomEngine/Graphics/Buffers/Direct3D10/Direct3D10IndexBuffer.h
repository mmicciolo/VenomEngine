/*
File : Direct3D10IndexBuffer.h
Author: Matthew Micciolo

Implementation of IVenomIndexBuffer for Direct3D10.
*/

#ifndef __Direct3D10_INDEX_BUFFER_
#define __Direct3D10_INDEX_BUFFER_

#include "../IVenomIndexBuffer.h"
#include <d3d10.h>
#include <d3dx10.h>


namespace VenomEngine {
	class Direct3D10IndexBuffer : public IVenomIndexBuffer {
	public:
		Direct3D10IndexBuffer();
		void FillWithFromVector(std::vector<Vector3 *> * indexList);
		int IndexCount();
		DWORD * indices;
	protected:
	private:
		int indexCount;
	};
}

#endif
