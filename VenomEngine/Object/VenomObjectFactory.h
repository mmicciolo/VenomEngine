#ifndef __VENOM_OBJECT_FACTORY_
#define __VENOM_OBJECT_FACTORY_

#include "VenomObject.h"
#include <string>

namespace VenomEngine {
	class VenomObjectFactory {
	public:
		template<typename T> static T  * Load(std::string fileName){ 
			T * object = new T(fileName);
			return object;
		}
	protected:
	private:
	};
}

#endif
