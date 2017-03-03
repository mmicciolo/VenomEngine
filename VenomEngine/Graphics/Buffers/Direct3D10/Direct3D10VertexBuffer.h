/*
File : Direct3D10VertexBuffer.h
Author: Matthew Micciolo

Implementation of IVenomVertexBuffer for Direct3D10.
*/

#ifndef __Direct3D10_VERTEX_BUFFER_
#define __Direct3D10_VERTEX_BUFFER_

#include "../IVenomVertexBuffer.h"
#include <d3d10.h>
#include <d3dx10.h>

namespace VenomEngine {

	struct Vertex
	{
		D3DXVECTOR3 pos;
	};

	class Direct3D10VertexBuffer : public IVenomVertexBuffer {
	public:
		Direct3D10VertexBuffer();
		void FillWithFromVector(std::vector<Vector3 *> * vertexList);
		int VertexCount();
		Vertex * vertices;
	protected:
	private:
		int vertexCount;
	};
}

#endif