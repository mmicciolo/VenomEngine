/*
File : Singleton.h
Author: Matthew Micciolo

Template for any classes that need to use the singleton design pattern.
*/

#ifndef __SINGLETON_
#define __SINGLETON_

#include <iostream>

namespace VenomEngine {
	template <class T> class Singleton {
	public:
		template <typename... Args> static T * Instance(Args... args) {
			if (instance == nullptr) {
				instance = new T(std::forward<Args>(args)...);
			}
			return instance;
		}
	private:
		static T * instance;
	};
	template <class T> T*  Singleton<T>::instance = nullptr;
}

#endif
