/*
File : VenomObject.h
Author: Matthew Micciolo

This class is the base class for all objects that reside inside of the engine
*/

#ifndef __VENOM_OBJECT_
#define __VENOM_OBJECT_

#include "../Math/Vector/Vector3.h"
#include "../Math/Matrix/Matrix.h"
#include "IVenomObject.h"

using namespace VenomEngine;

namespace VenomEngine {
	enum VenomObjectType {
		NONE,
		MODEL,
		CAMERA,
		IMAGE,
		SOUND,
		TEXT
	};

	class VenomObject : public IVenomObject {
	public:
		VenomObject();
		void UpdateTransforms();
		void SetPosition(Vector3 position);
		void Render();
		//void SetRotation(Vector3 rotation);
		//void SetScale(Vector3 scale);
		Vector3 GetPosition();
		//Vector3 GetRotation();
		//Vector3 GetScale();
		int GetType();
		void ObjectAdded();
	protected:
		VenomObjectType type;
		D3DXMATRIX world;
		D3DXMATRIX transform;
		D3DXVECTOR3 position;
		D3DXVECTOR3 rotation;
		D3DXVECTOR3 scale;
	private:
	};
}

#endif
