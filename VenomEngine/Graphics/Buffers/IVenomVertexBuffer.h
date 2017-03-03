#ifndef __IVENOM_VERTEX_BUFFER_
#define __IVENOM_VERTEX_BUFFER_

#include <vector>
#include "../../Math/Vector/Vector3.h"

namespace VenomEngine {
	class IVenomVertexBuffer {
	public:
		IVenomVertexBuffer() {}
		virtual void FillWithFromVector(std::vector<Vector3 *> * vertexList) {}
		virtual int VertexCount() { return 0; }
	protected:
	private:
	};
}

#endif
