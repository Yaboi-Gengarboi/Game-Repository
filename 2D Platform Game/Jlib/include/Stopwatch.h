// Jlib
// Stopwatch.h
// Justyn Durnford
// Created on 2021-02-14
// Last updated on 2021-02-14
// Header file for the Stopwatch class.

#ifndef STOPWATCH_H_INCLUDED
#define STOPWATCH_H_INCLUDED

#include <chrono>

namespace Jlib
{
	class Stopwatch
	{
		std::chrono::time_point<std::chrono::system_clock> start_;
		std::chrono::time_point<std::chrono::system_clock> end_;
		bool is_stopped_ = false;

		public:

		// Default constructor.
		Stopwatch() = default;

		// Copy constructor. Deleted.
		Stopwatch(const Stopwatch& other) = delete;

		// Move constructor. Deleted.
		Stopwatch(Stopwatch&& other) = delete;

		// Copy assignment operator. Deleted.
		Stopwatch& operator = (const Stopwatch& other) = delete;

		// Move assignment operator. Deleted.
		Stopwatch& operator = (Stopwatch&& other) = delete;

		// Destructor.
		~Stopwatch() = default;

		// Starts the Stopwatch.
		void start();

		// Stops the Stopwatch.
		void stop();

		// Returns the amount of seconds that have passed.
		double secondsPassed();

		// Returns the amount of milliseconds that have passed.
		double millisecondsPassed();
	};
}

#endif // !STOPWATCH_H_INCLUDED