#include "Direct3D10VertexBuffer.h"

namespace VenomEngine {
	Direct3D10VertexBuffer::Direct3D10VertexBuffer() {

	}

	void Direct3D10VertexBuffer::FillWithFromVector(std::vector<Vector3 *> * vertexList) {
		vertexCount = vertexList->size();
		vertices = new Vertex[vertexList->size()];
		for (size_t i = 0; i < vertexList->size(); i++) {
			Vector3 * vec3 = (Vector3 *)vertexList->at(i);
			Vertex vertex;
			vertex.pos = D3DXVECTOR3(vec3->x, vec3->y, vec3->z);
			vertices[i] = vertex;
		}
	}

	int Direct3D10VertexBuffer::VertexCount() {
		return vertexCount;
	}
}