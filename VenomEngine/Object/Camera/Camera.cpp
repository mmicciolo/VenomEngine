#include "Camera.h"

namespace VenomEngine {
	Camera::Camera() {
		type = VenomObjectType::CAMERA;
		position = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
		Target = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
		Up = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
		D3DXMatrixLookAtLH(&View, &position, &Target, &Up);
	}

	void Camera::UpdateTransforms() {
		D3DXMatrixLookAtLH(&View, &position, &Target, &Up);
	}

	D3DXMATRIX Camera::GetView() {
		return View;
	}

	D3DXMATRIX Camera::GetProjection() {
		return Projection;
	}
}