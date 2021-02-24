// Jlib
// Color.h
// Justyn Durnford
// Created on 2020-10-12
// Last updated on 2021-02-09
// Header file for the Color class.

#ifndef COLOR_H_INCLUDED
#define COLOR_H_INCLUDED

#include <cstdint>
#include <iostream>
#include <string>

namespace Jlib
{
	struct Color
	{
		std::uint8_t red = 0;
		std::uint8_t green = 0;
		std::uint8_t blue = 0;
		std::uint8_t alpha = 0;

		static const std::uint8_t COLOR_MAX = 255;

		// Default constructor.
		Color() = default;

		// Copy constructor.
		Color(const Color& other) = default;

		// Move constructor.
		Color(Color&& other) = default;

		// 3-integer constructor.
		// Sets red to new_red.
		// Sets green = new_green.
		// Sets blue = new_blue.
		Color(std::uint8_t new_red, std::uint8_t new_green, std::uint8_t new_blue);

		// 4-integer constructor.
		// Sets red to new_red.
		// Sets green = new_green.
		// Sets blue = new_blue.
		// Sets alpha = new_alpha.
		Color(std::uint8_t new_red, std::uint8_t new_green, std::uint8_t new_blue, std::uint8_t new_alpha);

		// Copy assignment.
		Color& operator = (const Color& other) = default;

		// Move assignment.
		Color& operator = (Color&& other) = default;

		// Destructor.
		~Color() = default;

		// Sets red to new_red.
		// Sets green = new_green.
		// Sets blue = new_blue.
		// Sets alpha = new_alpha.
		void setAll(std::uint8_t new_red, std::uint8_t new_green, std::uint8_t new_blue, std::uint8_t new_alpha);

		// Returns a std::string representation of the Color.
		std::string toString() const;
	};

	///////////////////////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////////////////////
	//////                                    GLOBAL OPERATORS                                   //////
	///////////////////////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////////////////////////////// 

	// Equality comparison operator.
	// Returns true if:
	//  - A.red == B.red      AND
	//  - A.green == B.green  AND
	//  - A.blue == B.blue    AND
	//  - A.alpha == B.alpha
	// Returns false otherwise.
	bool operator == (const Color& A, const Color& B);

	// Inequality comparison operator.
	// Returns true if:
	//  - A.red != B.red      OR
	//  - A.green != B.green  OR
	//  - A.blue != B.blue    OR
	//  - A.alpha != B.alpha
	// Returns false otherwise.
	bool operator != (const Color& A, const Color& B);

	// std::ostream insertion operator.
	std::ostream& operator << (std::ostream& os, const Color& c);

	void print(const Color& c);

	void println(const Color& c);
}

#endif // COLOR_H_INCLUDED