/*
File : Vector4.h
Author: Matthew Micciolo

Vector4 class.
*/

#ifndef __VECTOR4_
#define __VECTOR4_

namespace VenomEngine {
	class Vector4 {
	public:
		Vector4() {}
		Vector4(float x, float y, float z, float w) { this->x = x; this->y = y; this->z = z; this->w = w; }
		float x, y, z, w;
	protected:
	private:
	};
}

#endif
