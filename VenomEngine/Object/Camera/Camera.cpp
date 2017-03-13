#include "Camera.h"
#include "../../Managers/SceneManager.h"

namespace VenomEngine {
	Camera::Camera() {
		type = VenomObjectType::CAMERA;
		position = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
		Target = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
		Up = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
		D3DXMatrixLookAtLH(&View, &position, &Target, &Up);
		D3DXMatrixPerspectiveFovLH(&Projection, 0.4f*3.14f, (float)800 / (float)600, 1.0f, 1000.0f);
	}

	void Camera::Init() {
		SceneManager::Instance()->SetCurrentCamera(this);
	}

	void Camera::Update() {
		D3DXMatrixLookAtLH(&View, &position, &Target, &Up);
	}

	void Camera::Render() {

	}

	D3DXMATRIX Camera::GetView() {
		return View;
	}

	D3DXMATRIX Camera::GetProjection() {
		return Projection;
	}
}