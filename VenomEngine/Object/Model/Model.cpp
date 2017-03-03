#include "Model.h"

namespace VenomEngine {
	Model::Model() {
		type = VenomObjectType::MODEL;
	}

	void Model::UpdateTransforms() {
		D3DXMatrixTranslation(&transform, 0, 0, 0);
		D3DXMatrixTranslation(&world, position.x, position.y, position.z);
	}

	void Model::Render(D3DXMATRIX view, D3DXMATRIX projection) {
		WVP = world * transform * view * projection;
		fxWVPvar->SetMatrix((float*)&WVP);
		D3D10_TECHNIQUE_DESC techDesc;
		Technique->GetDesc(&techDesc);
		for (UINT p = 0; p < techDesc.Passes; ++p)
		{
			Technique->GetPassByIndex(p)->Apply(0);
			mesh->DrawSubset(0);
		}
	}
}
