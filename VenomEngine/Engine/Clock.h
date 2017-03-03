/*
File : Clock.h
Author: Matthew Micciolo

Provides any timing neeed for the engine.
*/

#ifndef __CLOCK_H__
#define __CLOCK_H__

namespace VenomEngine {

	class Clock {

	private:

		long int previous_time; //Previous time delta called (in microseconds)

	public:

		//Sets previous time to current time
		Clock();

		//Return the time elapsed since delta was last called, -1 if error
		//Units are in microseconds
		long int delta(void);

		//Return time elapsed since delta was called, -1 if error
		long int split(void) const;
	};
} // end of namespace df
#endif  __CLOCK_H__