/*
File : Model.h
Author: Matthew Micciolo

Base class for any 3d model.
*/

#ifndef __MODEL_
#define __MODEL_

#include "../VenomObject.h"
#include <string>
#include "../../Graphics/Buffers/IVenomVertexBuffer.h"
#include "../../Graphics/Buffers/IVenomIndexBuffer.h"

namespace VenomEngine {
	class Model : public VenomObject {
	public:
		Model();
		void Render(D3DXMATRIX view, D3DXMATRIX projection);
		void UpdateTransforms();
		IVenomVertexBuffer * vertexBuffer;
		IVenomIndexBuffer  * indexBuffer;
		ID3D10Effect* FX;
		ID3D10InputLayout* VertexLayout;
		ID3D10EffectTechnique* Technique;
		ID3D10EffectMatrixVariable* fxWVPvar;
		ID3DX10Mesh * mesh;
		D3DXMATRIX WVP;
	protected:
	private:
	};
}

#endif
