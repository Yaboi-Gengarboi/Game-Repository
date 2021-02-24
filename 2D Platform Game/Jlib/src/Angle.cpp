// Jlib
// Angle.cpp
// Justyn Durnford
// Created on 2021-01-17
// Last updated on 2021-02-09
// Source file for the Angle class.

#include "Angle.h"

#include <stdexcept>

Jlib::Angle::Angle(double value)
	: value_(value) {}

Jlib::Angle& Jlib::Angle::operator = (double value)
{
	value_ = value;
	return *this;
}

double Jlib::Angle::value() const
{
	return value_;
}

void Jlib::Angle::setValue(double value)
{
	value_ = value;
}

std::string Jlib::Angle::toString() const
{
	return std::to_string(value_) + '\370';
}

Jlib::Angle& Jlib::Angle::operator += (const Angle& other)
{
	value_ += other.value_;
	return *this;
}

Jlib::Angle& Jlib::Angle::operator -= (const Angle& other)
{
	value_ -= other.value_;
	return *this;
}

Jlib::Angle& Jlib::Angle::operator *= (double d)
{
	value_ *= d;
	return *this;
}

Jlib::Angle& Jlib::Angle::operator /= (double d)
{
	value_ /= d;
	return *this;
}

///////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////
//////                                    GLOBAL OPERATORS                                   //////
///////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////

Jlib::Angle Jlib::operator + (const Angle& A, const Angle& B)
{
	return Angle(A.value() + B.value());
}

Jlib::Angle Jlib::operator - (const Angle& A, const Angle& B)
{
	return Angle(A.value() - B.value());
}

Jlib::Angle Jlib::operator * (const Angle& ang, double d)
{
	return Angle(ang.value() * d);
}

Jlib::Angle Jlib::operator / (const Angle& ang, double d)
{
	return Angle(ang.value() / d);
}

bool Jlib::operator == (const Angle& A, const Angle& B)
{
	return A.value() == B.value();
}

bool Jlib::operator != (const Angle& A, const Angle& B)
{
	return A.value() != B.value();
}

bool Jlib::operator < (const Angle& A, const Angle& B)
{
	return A.value() < B.value();
}

bool Jlib::operator <= (const Angle& A, const Angle& B)
{
	return A.value() <= B.value();
}

bool Jlib::operator > (const Angle& A, const Angle& B)
{
	return A.value() > B.value();
}

bool Jlib::operator >= (const Angle& A, const Angle& B)
{
	return A.value() >= B.value();
}

std::strong_ordering Jlib::operator <=> (const Angle& A, const Angle& B)
{
	if (A.value() < B.value())
		return std::strong_ordering::less;
	if (A.value() > B.value())
		return std::strong_ordering::greater;

	return std::strong_ordering::equal;
}

std::ostream& Jlib::operator << (std::ostream& os, const Angle& ang)
{
	os << ang.toString();
	return os;
}

///////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////
//////                                    GLOBAL FUNCTIONS                                   //////
///////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////

double Jlib::toRad(double deg)
{
	return deg * M_PI / 180.0;
}

double Jlib::toDeg(double rad)
{
	return rad * 180.0 / M_PI;
}

Jlib::Angle Jlib::abs(const Angle& ang)
{
	return Angle(Angle(std::abs(toRad(ang.value()))));
}

Jlib::Angle Jlib::pow(const Angle& ang, double power)
{
	return Angle(std::pow(toRad(ang.value()), power));
}

Jlib::Angle Jlib::sqrt(const Jlib::Angle& ang)
{
	if (ang < Angle(0.0))
		throw std::domain_error("Invalid argument for Jlib::sqrt");

	return Angle(std::sqrt(toRad(ang.value())));
}

Jlib::Angle Jlib::cbrt(const Jlib::Angle& ang)
{
	return Angle(std::cbrt(toRad(ang.value())));
}

Jlib::Angle Jlib::log(const Jlib::Angle& ang)
{
	if (ang <= Angle(0.0))
		throw std::domain_error("Invalid argument for Jlib::log");

	return Angle(std::log(toRad(ang.value())));
}

Jlib::Angle Jlib::floor(const Angle& ang)
{
	return Angle(std::floor(toRad(ang.value())));
}

Jlib::Angle Jlib::ceil(const Angle& ang)
{
	return Angle(std::ceil(toRad(ang.value())));
}

double Jlib::cos(const Angle& ang)
{
	return std::cos(toRad(ang.value()));
}

double Jlib::sin(const Angle& ang)
{
	return std::sin(toRad(ang.value()));
}

double Jlib::tan(const Angle& ang)
{
	if (std::fmod(ang.value(), 90.0) == 0 && std::fmod(ang.value() / 90.0, 2.0) != 0)
		throw std::domain_error("Invalid argument for Jlib::tan");

	return std::tan(toRad(ang.value()));
}

Jlib::Angle Jlib::arccos(double d)
{
	if (-1 >= d || 1 <= d)
		throw std::domain_error("Invalid argument for Jlib::arccos");

	return Angle(toDeg(std::acos(d)));
}

Jlib::Angle Jlib::arcsin(double d)
{
	if (-1 >= d || 1 <= d)
		throw std::domain_error("Invalid argument for Jlib::arcsin");

	return Angle(toDeg(std::asin(d)));
}

Jlib::Angle Jlib::arctan(double d)
{
	return Angle(toDeg(std::atan(d)));
}

void Jlib::print(const Jlib::Angle& ang)
{
	std::cout << ang;
}

void Jlib::println(const Jlib::Angle& ang)
{
	std::cout << ang << std::endl;
}