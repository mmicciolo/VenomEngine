#include "Clock.h"
#include <Windows.h>

namespace VenomEngine {
	Clock::Clock() {

		//Get the system time
		SYSTEMTIME t;
		GetSystemTime(&t);

		//Set previous time to current time
		previous_time = ((t.wMinute * 60 * 1000) + (t.wSecond * 1000) + (t.wMilliseconds)) * 1000;
	}

	long int Clock::delta() {

		//Get the system time
		SYSTEMTIME t;
		GetSystemTime(&t);

		long int old_previous_time = previous_time;

		//Set previous time to current time
		previous_time = ((t.wMinute * 60 * 1000) + (t.wSecond * 1000) + (t.wMilliseconds)) * 1000;

		return previous_time - old_previous_time;
	}

	long int Clock::split() const {

		//Get the system time
		SYSTEMTIME t;
		GetSystemTime(&t);

		//Set previous time to current time
		long int current_time = ((t.wMinute * 60 * 1000) + (t.wSecond * 1000) + (t.wMilliseconds)) * 1000;

		return current_time - previous_time;
	}
}