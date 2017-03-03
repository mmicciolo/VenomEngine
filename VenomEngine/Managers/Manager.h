/*
File : Manager.h
Author: Matthew Micciolo

Base class header file for any managers in the engine.
*/

#ifndef  __MANAGER_
#define  __MANAGER_

#include <iostream>
//#include "Event.h"

namespace VenomEngine {
	class Manager {
	public:
		Manager();
		virtual ~Manager();
		virtual bool Init();
		virtual void Update();
		virtual bool Shutdown();
		bool GetIsStarted();
		std::string GetType();
		//virtual void EventHandler(Event * event);
	private:
		std::string type;
		bool isStarted = false;
	protected:
		void SetType(std::string type);
	};
}
#endif

