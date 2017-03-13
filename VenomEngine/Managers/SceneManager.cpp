#include "SceneManager.h"
#include "../Managers/GraphicsManager.h"

namespace VenomEngine {
	SceneManager::SceneManager() {

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
		sceneObjects.push_back(object);
		object->Init();
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

	void SceneManager::SetCurrentCamera(Camera * camera) {
		this->currentCamera = camera;
	}

	Camera * SceneManager::GetCurrentCamera() {
		return currentCamera;
	}

	void SceneManager::UpdateScene() {
		for (std::vector<IVenomObject *>::iterator iter = sceneObjects.begin(); iter != sceneObjects.end(); ++iter) {
			IVenomObject * obj = (IVenomObject*)*iter;
			obj->Update();
		}
	}

	void SceneManager::RenderScene() {
		for (std::vector<IVenomObject *>::iterator iter = sceneObjects.begin(); iter != sceneObjects.end(); ++iter) {
			IVenomObject * obj = (IVenomObject*)*iter;
			obj->Render();
		}
	}
}