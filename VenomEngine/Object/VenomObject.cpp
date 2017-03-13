#include "VenomObject.h"
#include "../Managers/SceneManager.h"

namespace VenomEngine {
	VenomObject::VenomObject() {
		D3DXMatrixIdentity(&world);
		D3DXMatrixIdentity(&transform);
		type = VenomObjectType::NONE;
	}

	void VenomObject::SetPosition(Vector3 position) {
		this->position.x = position.x;
		this->position.y = position.y;
		this->position.z = position.z;
	}

	Vector3 VenomObject::GetPosition() {
		Vector3 vec3;
		vec3.x = position.x;
		vec3.y = position.y;
		vec3.z = position.z;
		return vec3;
	}

	int VenomObject::GetType() {
		return type;
	}

	void VenomObject::Init() {
		SceneManager::Instance()->AddObject(this);
	}

	void VenomObject::Update() {

	}

	void VenomObject::Render() {

	}
}