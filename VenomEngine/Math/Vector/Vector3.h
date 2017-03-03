/*
File : Vector3.h
Author: Matthew Micciolo

Vector3 class.
*/

#ifndef __VECTOR3_
#define __VECTOR3_

namespace VenomEngine {
	class Vector3 {
	public:
		Vector3() {}
		Vector3(float x, float y, float z) { this->x = x; this->y = y; this->z = z; }
		float x, y, z;
	protected:
	private:
	};
}

#endif
