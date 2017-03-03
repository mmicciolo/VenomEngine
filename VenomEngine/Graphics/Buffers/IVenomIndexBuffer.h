/*
File : IVenomIndexBuffer.h
Author: Matthew Micciolo

Interface for any index buffers in the engine.
*/

#ifndef __IVENOM_INDEX_BUFFER_
#define __IVENOM_INDEX_BUFFER_

#include <vector>
#include "../../Math/Vector/Vector3.h"

namespace VenomEngine {
	class IVenomIndexBuffer {
	public:
		IVenomIndexBuffer() {}
		virtual void FillWithFromVector(std::vector<Vector3 *> * indexList) {}
		virtual int IndexCount() { return 0; }
	protected:
	private:
	};
}

#endif
