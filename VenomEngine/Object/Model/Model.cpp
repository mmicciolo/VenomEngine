#include "Model.h"
#include "../../Managers/SceneManager.h"
#include "../../Managers/GraphicsManager.h"

namespace VenomEngine {
	Model::Model() {
		type = VenomObjectType::MODEL;
	}

	void Model::Init() {
		Direct3D10Renderer * r = (Direct3D10Renderer *)GraphicsManager::Instance()->GetRenderer();
		r->CreateMesh(&mesh, &Technique, &fxWVPvar, &FX, &VertexLayout, (Direct3D10VertexBuffer *)vertexBuffer, (Direct3D10IndexBuffer *)indexBuffer);
	}

	void Model::Update() {
		D3DXMatrixTranslation(&transform, 0, 0, 0);
		D3DXMatrixTranslation(&world, position.x, position.y, position.z);
	}

	void Model::Render() {
		WVP = world * transform * SceneManager::Instance()->GetCurrentCamera()->GetView() * SceneManager::Instance()->GetCurrentCamera()->GetProjection();
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
