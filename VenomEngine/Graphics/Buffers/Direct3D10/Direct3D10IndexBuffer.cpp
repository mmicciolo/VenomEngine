#include "Direct3D10IndexBuffer.h"


namespace VenomEngine {
	Direct3D10IndexBuffer::Direct3D10IndexBuffer() {

	}

	void Direct3D10IndexBuffer::FillWithFromVector(std::vector<Vector3 *> * indexList) {
		indexCount = indexList->size() * 3;
		indices = new DWORD[indexList->size() * 3];
		for (size_t i = 0; i < indexList->size(); i++) {
			Vector3 * vec3 = (Vector3 *)indexList->at(i);
			indices[(i * 3)] = (DWORD)vec3->x;
			indices[(i * 3) + 1] = (DWORD)vec3->y;
			indices[(i * 3) + 2] = (DWORD)vec3->z;
		}
	}

	int Direct3D10IndexBuffer::IndexCount() {
		return indexCount;
	}
}