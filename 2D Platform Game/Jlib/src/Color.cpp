// Jlib
// Color.cpp
// Justyn Durnford
// Created on 2020-10-12
// Last updated on 2021-02-09
// Source file for the Color class.

#include "Color.h"

// <cstdint>
using std::uint8_t;

// <iostream>
using std::ostream;
using std::cout;
using std::endl;

// <string>
using std::string;
using std::to_string;

Jlib::Color::Color(uint8_t new_red, uint8_t new_green, uint8_t new_blue)
{
	red = new_red;
	green = new_green;
	blue = new_blue;
	alpha = COLOR_MAX;
}

Jlib::Color::Color(uint8_t new_red, uint8_t new_green, uint8_t new_blue, uint8_t new_alpha)
{
	red = new_red;
	green = new_green;
	blue = new_blue;
	alpha = new_alpha;
}

void Jlib::Color::setAll(uint8_t new_red, uint8_t new_green, uint8_t new_blue, uint8_t new_alpha)
{
	red = new_red;
	green = new_green;
	blue = new_blue;
	alpha = new_alpha;
}

string Jlib::Color::toString() const
{
	return "R: " + to_string(red) + ", G: " + to_string(green) + ", B: " + to_string(blue) + ", A: " + to_string(alpha);
}

bool Jlib::operator == (const Color& A, const Color& B)
{
	if (A.red != B.red)
		return false;

	if (A.green != B.green)
		return false;

	if (A.blue != B.blue)
		return false;

	return true;
}

bool Jlib::operator != (const Color& A, const Color& B)
{
	if (A.red != B.red)
		return true;

	if (A.green != B.green)
		return true;

	if (A.blue != B.blue)
		return true;

	return false;
}

ostream& Jlib::operator << (ostream& os, const Color& c)
{
	os << c.toString();
	return os;
}

void Jlib::print(const Jlib::Color& c)
{
	cout << c;
}

void Jlib::println(const Jlib::Color& c)
{
	cout << c << endl;
}