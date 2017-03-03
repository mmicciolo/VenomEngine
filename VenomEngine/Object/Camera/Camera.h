#ifndef __CAMERA_
#define __CAMERA_

#include "../VenomObject.h"
#include <d3d10.h>
#include <d3dx10.h>

namespace VenomEngine {
	class Camera : public VenomObject {
	public:
		Camera();
		void UpdateTransforms();
		D3DXMATRIX GetView();
		D3DXMATRIX GetProjection();
	protected:
	private:
		D3DXVECTOR3 Target;
		D3DXVECTOR3 Up;
		D3DXMATRIX View;
		D3DXMATRIX Projection;
	};
}

#endif