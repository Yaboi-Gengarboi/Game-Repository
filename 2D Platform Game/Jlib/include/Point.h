// Jlib
// Point.h
// Justyn Durnford
// Created on 2020-10-12
// Last updated on 2021-02-24
// Header file for the Point2, Point2Fr, Point3 and Point3Fr template structs.

#ifndef POINT_H_INCLUDED
#define POINT_H_INCLUDED

#ifndef _USE_MATH_DEFINES
#define _USE_MATH_DEFINES

#endif // _USE_MATH_DEFINES

#include "Arithmetic.h"
#include "Fraction.h"

#include <cmath>
#include <iostream>

namespace Jlib
{
	// This struct provides a representation of a single point
	// in two-dimensional space. 
	template <arithmetic T> struct Point2
	{
		T x = 0;
		T y = 0;

		// Default constructor.
		Point2() = default;

		// Copy constructor.
		// Copies the values from the passed Point2 into the new Point2.
		Point2(const Point2& other) = default;

		// Move constructor.
		// Moves the passed Point2 into the new Point2.
		Point2(Point2&& other) = default;

		// 2-parameter constructor.
		// Sets the x component of the Point2 to new_x.
		// Sets the y component of the Point2 to new_y.
		Point2(T new_x, T new_y)
		{
			x = new_x;
			y = new_y;
		}

		// Copy assignment operator.
		// Copies the values from the passed Point2 into the new Point2.
		Point2& operator = (const Point2& other) = default;

		// Move assignment operator.
		// Moves the passed Point2 into the new Point2.
		Point2& operator = (Point2&& other) = default;

		// Destructor.
		// Destroys the Point2 and its data.
		~Point2() = default;

		// Sets the x component of the Point2 to new_x.
		// Sets the y component of the Point2 to new_y.
		void setAll(T new_x, T new_y)
		{
			x = new_x;
			y = new_y;
		}

		// Clears the values of the Point2.
		void clear()
		{
			x = 0;
			y = 0;
		}

		// Returns a std::string representation of the Point2d
		std::string toString() const
		{
			return '(' + std::to_string(x) + ", " + std::to_string(y) + ')';
		}
	};

	///////////////////////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////////////////////
	//////                                 2D FRACTION VARIATION                                 //////
	///////////////////////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////////////////////

	// This struct provides a representation of a single point
	// in two-dimensional space. 
	template <fraction_t T> struct Point2Fr
	{
		T x = 0;
		T y = 0;

		// Default constructor.
		Point2Fr() = default;

		// Copy constructor.
		// Copies the values from the passed Point2Fr into the new Point2Fr.
		Point2Fr(const Point2Fr& other) = default;

		// Move constructor.
		// Moves the passed Point2Fr into the new Point2Fr.
		Point2Fr(Point2Fr&& other) = default;

		// 2-parameter constructor.
		// Sets the x component of the Point2Fr to new_x.
		// Sets the y component of the Point2Fr to new_y.
		Point2Fr(T new_x, T new_y)
		{
			x = new_x;
			y = new_y;
		}

		// Copy assignment operator.
		// Copies the values from the passed Point2Fr into the new Point2Fr.
		Point2Fr& operator = (const Point2Fr& other) = default;

		// Move assignment operator.
		// Moves the passed Point2Fr into the new Point2Fr.
		Point2Fr& operator = (Point2Fr&& other) = default;

		// Destructor.
		// Destroys the Point2Fr and its data.
		~Point2Fr() = default;

		// Sets the x component of the Point2Fr to new_x.
		// Sets the y component of the Point2Fr to new_y.
		void setAll(T new_x, T new_y)
		{
			x = new_x;
			y = new_y;
		}

		// Clears the values of the Point2Fr.
		void clear()
		{
			x = 0;
			y = 0;
		}

		// Returns a std::string representation of the Point2Fr
		std::string toString() const
		{
			return '(' + x.toString() + ", " + y.toString() + ')';
		}
	};

	///////////////////////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////////////////////
	//////                                3D ARITHMETIC VARIATION                                //////
	///////////////////////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////////////////////

	// This struct provides a representation of a single point
	// in three-dimensional space. 
	template <arithmetic T> struct Point3
	{
		T x = 0;
		T y = 0;
		T z = 0;

		// Default constructor.
		Point3() = default;

		// Copy constructor.
		// Copies the values from the passed Point3 into the new Point3.
		Point3(const Point3& other) = default;

		// Move constructor.
		// Moves the passed Point3 into the new Point3.
		Point3(Point3&& other) = default;

		// 2-parameter constructor.
		// Sets the x component of the Point3 to new_x.
		// Sets the y component of the Point3 to new_y.
		// Sets the z component of the Point3 to new_z.
		Point3(T new_x, T new_y, T new_z)
		{
			x = new_x;
			y = new_y;
			z = new_z;
		}

		// Point2 copy constructor.
		// Allows for the conversion from a Point2 to a Point3.
		Point3(const Point2<T>& other)
		{
			x = other.x;
			y = other.y;
			z = 0;
		}

		// Copy assignment operator.
		// Copies the values from the passed Point3 into the new Point3.
		Point3& operator = (const Point3& other) = default;

		// Move assignment operator.
		// Moves the passed Point3 into the new Point3.
		Point3& operator = (Point3&& other) = default;

		// Point2 assignment operator.
		// Allows for the conversion from a Point2 to a Point3.
		Point3& operator = (const Point2<T>& other)
		{
			x = other.x;
			y = other.y;
			z = 0;

			return *this;
		}

		// Destructor.
		// Destroys the Point3 and its data.
		~Point3() = default;

		// Sets the x component of the Point3 to new_x.
		// Sets the y component of the Point3 to new_y.
		// Sets the z component of the Point3 to new_z.
		void setAll(T new_x, T new_y, T new_z)
		{
			x = new_x;
			y = new_y;
			z = new_z;
		}

		// Clears the values of the Point3.
		void clear()
		{
			x = 0;
			y = 0;
			z = 0;
		}

		// Returns a std::string representation of the Point3.
		std::string toString() const
		{
			return '(' + std::to_string(x) + ", " + std::to_string(y) + ", " + std::to_string(z) + ')';
		}
	};

	///////////////////////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////////////////////
	//////                                 3D FRACTION VARIATION                                 //////
	///////////////////////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////////////////////

	// This struct provides a representation of a single point
	// in three-dimensional space. 
	template <fraction_t T> struct Point3Fr
	{
		T x = 0;
		T y = 0;
		T z = 0;

		// Default constructor.
		Point3Fr() = default;

		// Copy constructor.
		// Copies the values from the passed Point3Fr into the new Point3Fr.
		Point3Fr(const Point3Fr& other) = default;

		// Move constructor.
		// Moves the passed Point3Fr into the new Point3Fr.
		Point3Fr(Point3Fr&& other) = default;

		// 2-parameter constructor.
		// Sets the x component of the Point3Fr to new_x.
		// Sets the y component of the Point3Fr to new_y.
		// Sets the z component of the Point3Fr to new_z.
		Point3Fr(T new_x, T new_y, T new_z)
		{
			x = new_x;
			y = new_y;
			z = new_z;
		}

		// Point2 copy constructor.
		// Allows for the conversion from a Point2 to a Point3Fr.
		Point3Fr(const Point2<T>& other)
		{
			x = other.x;
			y = other.y;
			z = 0;
		}

		// Copy assignment operator.
		// Copies the values from the passed Point3Fr into the new Point3Fr.
		Point3Fr& operator = (const Point3Fr& other) = default;

		// Move assignment operator.
		// Moves the passed Point3Fr into the new Point3Fr.
		Point3Fr& operator = (Point3Fr&& other) = default;

		// Point2Fr assignment operator.
		// Allows for the conversion from a Point2Fr to a Point3Fr.
		Point3Fr& operator = (const Point2Fr<T>& other)
		{
			x = other.x;
			y = other.y;
			z = 0;

			return *this;
		}

		// Destructor.
		// Destroys the Point3Fr and its data.
		~Point3Fr() = default;

		// Sets the x component of the Point3Fr to new_x.
		// Sets the y component of the Point3Fr to new_y.
		// Sets the z component of the Point3Fr to new_z.
		void setAll(T new_x, T new_y, T new_z)
		{
			x = new_x;
			y = new_y;
			z = new_z;
		}

		// Clears the values of the Point3Fr.
		void clear()
		{
			x = 0;
			y = 0;
			z = 0;
		}

		// Returns a std::string representation of the Point3Fr.
		std::string toString() const
		{
			return '(' + x.toString() + ", " + y.toString() + ", " + z.toString() + ')';
		}
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
	//  - P.x == Q.x AND
	//  - P.y == Q.y
	// Returns false otherwise.
	template <arithmetic T> bool operator == (const Point2<T>& P, const Point2<T>& Q)
	{
		if (P.x != Q.x)
			return false;

		if (P.y != Q.y)
			return false;

		return true;
	}

	// Inequality comparison operator.
	// Returns true if:
	//  - P.x != Q.x OR
	//  - P.y != Q.y
	// Returns false otherwise.
	template <arithmetic T> bool operator != (const Point2<T>& P, const Point2<T>& Q)
	{
		if (P.x != Q.x)
			return true;

		if (P.y != Q.y)
			return true;

		return false;
	}

	// Equality comparison operator.
	// Returns true if:
	//  - P.x == Q.x AND
	//  - P.y == Q.y
	// Returns false otherwise.
	template <fraction_t T> bool operator == (const Point2Fr<T>& P, const Point2Fr<T>& Q)
	{
		if (P.x != Q.x)
			return false;

		if (P.y != Q.y)
			return false;

		return true;
	}

	// Inequality comparison operator.
	// Returns true if:
	//  - P.x != Q.x OR
	//  - P.y != Q.y
	// Returns false otherwise.
	template <fraction_t T> bool operator != (const Point2Fr<T>& P, const Point2Fr<T>& Q)
	{
		if (P.x != Q.x)
			return true;

		if (P.y != Q.y)
			return true;

		return false;
	}

	// Equality comparison operator.
	// Returns true if:
	//  - P.x == Q.x AND
	//  - P.y == Q.y AND
	//  - P.z == Q.z
	// Returns false otherwise.
	template <arithmetic T> bool operator == (const Point3<T>& P, const Point3<T>& Q)
	{
		if (P.x != Q.x)
			return false;

		if (P.y != Q.y)
			return false;

		if (P.z != Q.z)
			return false;

		return true;
	}

	// Inequality comparison operator.
	// Returns true if:
	//  - P.x != Q.x OR
	//  - P.y != Q.y OR
	//  - P.z != Q.z
	// Returns false otherwise.
	template <arithmetic T> bool operator != (const Point3<T>& P, const Point3<T>& Q)
	{
		if (P.x != Q.x)
			return true;

		if (P.y != Q.y)
			return true;

		if (P.z != Q.z)
			return true;

		return false;
	}

	// Equality comparison operator.
	// Returns true if:
	//  - P.x == Q.x AND
	//  - P.y == Q.y AND
	//  - P.z == Q.z
	// Returns false otherwise.
	template <fraction_t T> bool operator == (const Point3Fr<T>& P, const Point3Fr<T>& Q)
	{
		if (P.x != Q.x)
			return false;

		if (P.y != Q.y)
			return false;

		if (P.z != Q.z)
			return false;

		return true;
	}

	// Inequality comparison operator.
	// Returns true if:
	//  - P.x != Q.x OR
	//  - P.y != Q.y OR
	//  - P.z != Q.z
	// Returns false otherwise.
	template <fraction_t T> bool operator != (const Point3Fr<T>& P, const Point3Fr<T>& Q)
	{
		if (P.x != Q.x)
			return true;

		if (P.y != Q.y)
			return true;

		if (P.z != Q.z)
			return true;

		return false;
	}

	// std::ostream insertion operator.
	template <arithmetic T> std::ostream& operator << (std::ostream& os, const Point2<T>& P)
	{
		os << P.toString();
		return os;
	}

	// std::ostream insertion operator.
	template <fraction_t T> std::ostream& operator << (std::ostream& os, const Point2Fr<T>& P)
	{
		os << P.toString();
		return os;
	}

	// std::ostream insertion operator.
	template <arithmetic T> std::ostream& operator << (std::ostream& os, const Point3<T>& P)
	{
		os << P.toString();
		return os;
	}

	// std::ostream insertion operator.
	template <fraction_t T> std::ostream& operator << (std::ostream& os, const Point3Fr<T>& P)
	{
		os << P.toString();
		return os;
	}

	///////////////////////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////////////////////
	//////                                    GLOBAL FUNCTIONS                                   //////
	///////////////////////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////////////////////

	// Returns the distance between the two Point2s.
	template <arithmetic T> double distance(const Point2<T>& P, const Point2<T>& Q)
	{
		return std::sqrt(std::pow(Q.x - P.x, 2) + std::pow(Q.y - P.y, 2));
	}

	// Returns the distance between the two Point2s.
	template <fraction_t T> double distance(const Point2Fr<T>& P, const Point2Fr<T>& Q)
	{
		return std::sqrt(std::pow(Q.x.evaluate() - P.x.evaluate(), 2) + std::pow(Q.y.evaluate() - P.y.evaluate(), 2));
	}

	// Returns the distance between the two Point3s.
	template <arithmetic T> double distance(const Point3<T>& P, const Point3<T>& Q)
	{
		return std::sqrt(std::pow(Q.x - P.x, 2) + std::pow(Q.y - P.y, 2) + std::pow(Q.z - P.z, 2));
	}

	// Returns the distance between the two Point3s.
	template <fraction_t T> double distance(const Point3Fr<T>& P, const Point3Fr<T>& Q)
	{
		return std::sqrt(std::pow(Q.x.evaluate() - P.x.evaluate(), 2) + std::pow(Q.y.evaluate() - P.y.evaluate(), 2) + std::pow(Q.z.evaluate() - P.z.evaluate(), 2));
	}

	template <arithmetic T> void print(const Point2<T>& P)
	{
		std::cout << P;
	}

	template <arithmetic T> void println(const Point2<T>& P)
	{
		std::cout << P << std::endl;
	}

	template <fraction_t T> void print(const Point2Fr<T>& P)
	{
		std::cout << P;
	}

	template <fraction_t T> void println(const Point2Fr<T>& P)
	{
		std::cout << P << std::endl;
	}

	template <arithmetic T> void print(const Point3<T>& P)
	{
		std::cout << P;
	}

	template <arithmetic T> void println(const Point3<T>& P)
	{
		std::cout << P << std::endl;
	}

	template <fraction_t T> void print(const Point3Fr<T>& P)
	{
		std::cout << P;
	}

	template <fraction_t T> void println(const Point3Fr<T>& P)
	{
		std::cout << P << std::endl;
	}

	///////////////////////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////////////////////
	//////                                        TYPEDEFS                                       //////
	///////////////////////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////////////////////

	// Expands to Point2<std::int32_t>
	typedef Point2<std::int32_t> Point2i;

	// Expands to Point2<std::uint32_t>
	typedef Point2<std::uint32_t> Point2u;

	// Expands to Point2<std::int8_t>
	typedef Point2<std::int8_t> Point2c;

	// Expands to Point2<std::uint8_t>
	typedef Point2<std::uint8_t> Point2uc;

	// Expands to Point2<std::int16_t>
	typedef Point2<std::int16_t> Point2s;

	// Expands to Point2<std::uint16_t>
	typedef Point2<std::uint16_t> Point2us;

	// Expands to Point2<float>
	typedef Point2<float> Point2f;

	// Expands to Point2<double>
	typedef Point2<double> Point2d;

	// Expands to Point2Fr<Fraction<std::int32_t>>
	typedef Point2Fr<Fraction<std::int32_t>> Point2Fri;

	// Expands to Point2Fr<Fraction<std::uint32_t>>
	typedef Point2Fr<Fraction<std::uint32_t>> Point2Fru;

	// Expands to Point2Fr<Fraction<std::int8_t>>
	typedef Point2Fr<Fraction<std::int8_t>> Point2Frc;

	// Expands to Point2Fr<Fraction<std::uint8_t>>
	typedef Point2Fr<Fraction<std::uint8_t>> Point2Fruc;

	// Expands to Point3<std::int32_t>
	typedef Point3<std::int32_t> Point3i;

	// Expands to Point3<std::uint32_t>
	typedef Point3<std::uint32_t> Point3u;

	// Expands to Point3<std::int8_t>
	typedef Point3<std::int8_t> Point3c;

	// Expands to Point3<std::uint8_t>
	typedef Point3<std::uint8_t> Point3uc;

	// Expands to Point3<std::int16_t>
	typedef Point3<std::int16_t> Point3s;

	// Expands to Point3<std::uint16_t>
	typedef Point3<std::uint16_t> Point3us;

	// Expands to Point3<float>
	typedef Point3<float> Point3f;

	// Expands to Point3<double>
	typedef Point3<double> Point3d;

	// Expands to Point3Fr<Fraction<std::int32_t>>
	typedef Point3Fr<Fraction<std::int32_t>> Point3Fri;

	// Expands to Point3Fr<Fraction<std::uint32_t>>
	typedef Point3Fr<Fraction<std::uint32_t>> Point3Fru;

	// Expands to Point3Fr<Fraction<std::int8_t>>
	typedef Point3Fr<Fraction<std::int8_t>> Point3Frc;

	// Expands to Point3Fr<Fraction<std::uint8_t>>
	typedef Point3Fr<Fraction<std::uint8_t>> Point3Fruc;
}

#endif // POINT_H_INCLUDED