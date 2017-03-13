/*
File : IVenomObject.h
Author: Matthew Micciolo

Interface for a venom object. Mandatory functions all objects must implement.
*/

#ifndef __IVENOM_OBJECT_
#define __IVENOM_OBJECT_

#include "VenomObject.h"
#include "../Math/Vector/Vector3.h"

namespace VenomEngine {
	class IVenomObject {
	public:
		IVenomObject() {};
		virtual void SetPosition(Vector3 position) {};
		virtual Vector3 GetPosition() { return Vector3(0, 0, 0); };
		virtual int GetType() { return 0; };
		virtual void UpdateTransforms() {};
		virtual void Render() {};
		virtual void ObjectAdded() {};
	protected:
	private:
	};
}

#endif