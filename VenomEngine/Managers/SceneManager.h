/*
File : SceneManager.h
Author: Matthew Micciolo

This manager handles all interaction with the world and scene.
*/

#ifndef __SCENE_MANAGER_
#define __SCENE_MANAGER_

#include "Manager.h"
#include "../Common/Singleton.h"
#include "../Object/VenomObject.h"
#include <vector>
#include "../Managers/GraphicsManager.h"
#include "../Graphics/Direct3D10Renderer.h"
#include "../Object/Camera/Camera.h"
#include <d3d10.h>
#include <d3dx10.h>

namespace VenomEngine {
	class SceneManager : public Manager, public Singleton<SceneManager> {
	public:
		SceneManager();
		bool Init();
		void Update();
		bool Shutdown();
		void AddObject(IVenomObject * object);
		void RemoveObject(IVenomObject * object);
		void UpdateScene();
		void RenderScene();
		std::vector<IVenomObject *> GetSceneObjects();
		Camera * GetCurrentCamera();
	protected:
	private:
		std::vector<IVenomObject *> sceneObjects;
		//Matrix Projection;
		Camera * currentCamera;
		D3DXMATRIX projection;
	};
}

#endif
