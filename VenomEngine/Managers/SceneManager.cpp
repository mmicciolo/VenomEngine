#include "SceneManager.h"

namespace VenomEngine {
	SceneManager::SceneManager() {
		D3DXMatrixPerspectiveFovLH(&projection, 0.4f*3.14f, (float)800 / (float)600, 1.0f, 1000.0f);
	}

	bool SceneManager::Init() {
		return true;
	}

	void SceneManager::Update() {

	}

	bool SceneManager::Shutdown() {
		return true;
	}

	void SceneManager::AddObject(IVenomObject * object) {
		Direct3D10Renderer * r; Model * m;
		sceneObjects.push_back(object);
		switch (object->GetType()) {
		case VenomObjectType::NONE:
			break;
		case VenomObjectType::MODEL:
			r = (Direct3D10Renderer *)GraphicsManager::Instance()->GetRenderer();
			m = (Model *)object;
			r->CreateMesh(&m->mesh, &m->Technique, &m->fxWVPvar, &m->FX, &m->VertexLayout, (Direct3D10VertexBuffer *)m->vertexBuffer, (Direct3D10IndexBuffer *)m->indexBuffer);
			break;
		case VenomObjectType::CAMERA:
			currentCamera = (Camera *)object;
			break;
		}
	}

	void SceneManager::RemoveObject(IVenomObject * object) {
		for (std::vector<IVenomObject *>::iterator iter = sceneObjects.begin(); iter != sceneObjects.end(); ++iter) {
			if (*iter = object) {
				sceneObjects.erase(iter);
				break;
			}
		}
	}

	std::vector<IVenomObject *> SceneManager::GetSceneObjects() {
		return sceneObjects;
	}

	Camera * SceneManager::GetCurrentCamera() {
		return currentCamera;
	}

	void SceneManager::UpdateScene() {
		for (std::vector<IVenomObject *>::iterator iter = sceneObjects.begin(); iter != sceneObjects.end(); ++iter) {
			VenomObject * obj = (VenomObject*)*iter;
			obj->UpdateTransforms();
		}
	}

	void SceneManager::RenderScene() {
		for (size_t i = 0; i < SceneManager::Instance()->GetSceneObjects().size(); i++) {
			VenomObject *obj = (VenomObject *)SceneManager::Instance()->GetSceneObjects().at(i);
			if (obj->GetType() == VenomObjectType::MODEL) {
				Model * model = (Model*)obj;
				model->Render(currentCamera->GetView(), projection);
			}
			else {
				obj->Render();
			}
		}
	}
}