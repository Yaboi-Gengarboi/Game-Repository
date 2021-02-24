// Jlib
// Stopwatch.cpp
// Justyn Durnford
// Created on 2021-02-14
// Last updated on 2021-02-14
// Source file for the Stopwatch class.

#include "Stopwatch.h"

// <chrono>
using std::chrono::duration;
using std::chrono::system_clock;
using std::chrono::time_point;

void Jlib::Stopwatch::start()
{
	is_stopped_ = false;
	start_ = system_clock::now();
}

void Jlib::Stopwatch::stop()
{
	end_ = system_clock::now();
	is_stopped_ = true;
}

double Jlib::Stopwatch::secondsPassed()
{
	duration<double> time_elapsed;

	if (is_stopped_)
		time_elapsed = end_ - start_;
	else
		time_elapsed = system_clock::now() - start_;

	return time_elapsed.count();
}

double Jlib::Stopwatch::millisecondsPassed()
{
	duration<double> time_elapsed;

	if (is_stopped_)
		time_elapsed = end_ - start_;
	else
		time_elapsed = system_clock::now() - start_;

	return time_elapsed.count() * 1000;
}