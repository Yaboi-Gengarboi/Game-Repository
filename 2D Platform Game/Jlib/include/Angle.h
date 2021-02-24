// Jlib
// Angle.h
// Justyn Durnford
// Created on 2021-01-17
// Last updated on 2021-02-09
// Header file for the Angle class.

#ifndef ANGLE_H_INCLUDED
#define ANGLE_H_INCLUDED

#ifndef _USE_MATH_DEFINES
#define _USE_MATH_DEFINES

#endif // _USE_MATH_DEFINES

#include <cmath>
#include <compare>
#include <iostream>
#include <string>

namespace Jlib
{
	class Angle
	{
		double value_ = 0.0;

		public:

		// Default constructor.
		Angle() = default;

		// Copy constructor.
		// Copies the values from the passed Angle into the new Angle.
		Angle(const Angle& other) = default;

		// Move constructor.
		// Moves the passed Angle into the new Angle.
		Angle(Angle&& other) = default;

		// Value constructor.
		// Sets the Angle to the given value.
		Angle(double value);

		// Copy assignment operator.
		// Copies the values from the passed Angle into the new Angle.
		Angle& operator = (const Angle& other) = default;

		// Move assignment operator.
		// Moves the passed Angle into the new Angle.
		Angle& operator = (Angle&& other) = default;

		// Value assignment operator.
		// Sets the Angle to the given value.
		Angle& operator = (double value);

		// Destructor.
		// Destroys the Angle and its data.
		~Angle() = default;

		// Returns the value of the Angle.
		double value() const;

		// Sets the value of the Angle to the given value.
		void setValue(double value);

		// Returns a std::string representation of the Angle.
		std::string toString() const;

		Angle& operator += (const Angle& other);

		Angle& operator -= (const Angle& other);

		Angle& operator *= (double d);

		Angle& operator /= (double d);
	};

	///////////////////////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////////////////////
	//////                                    GLOBAL OPERATORS                                   //////
	///////////////////////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////////////////////

	Angle operator + (const Angle& A, const Angle& B);

	Angle operator - (const Angle& A, const Angle& B);

	Angle operator * (const Angle& ang, double d);

	Angle operator / (const Angle& ang, double d);

	bool operator == (const Angle& A, const Angle& B);

	bool operator != (const Angle& A, const Angle& B);

	bool operator < (const Angle& A, const Angle& B);

	bool operator <= (const Angle& A, const Angle& B);

	bool operator > (const Angle& A, const Angle& B);

	bool operator >= (const Angle& A, const Angle& B);

	std::strong_ordering operator <=> (const Angle& A, const Angle& B);

	std::ostream& operator << (std::ostream& os, const Angle& ang);

	///////////////////////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////////////////////
	//////                                    GLOBAL FUNCTIONS                                   //////
	///////////////////////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////////////////////

	double toRad(double ang);

	double toDeg(double rad);

	Angle abs(const Angle& ang);

	Angle pow(const Angle& ang, double power);

	// Will throw a std::domain_error exception if
	// ang.value() < 0
	Angle sqrt(const Angle& ang);

	Angle cbrt(const Angle& ang);

	// Will throw a std::domain_error exception if 
	// ang.value() <= 0
	Angle log(const Angle& ang);

	Angle floor(const Angle& ang);

	Angle ceil(const Angle& ang);

	double cos(const Angle& ang);

	double sin(const Angle& ang);

	// Will throw a std::domain_error exception if
	// std::fmod(ang.value(), 90.0) == 0 AND
	// std::fmod(ang.value() / 90.0, 2.0) != 0
	double tan(const Angle& ang);

	// Will throw a std::domain_error exception if
	//  - -1 >= d OR
	//  -  1 <= d
	Angle arccos(double d);

	// Will throw a std::domain_error exception if
	//  - -1 >= d OR
	//  -  1 <= d
	Angle arcsin(double d);

	Angle arctan(double d);

	void print(const Angle& ang);

	void println(const Angle& ang);
}

#endif // ANGLE_H_INCLUDED