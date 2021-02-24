// Jlib
// Circle.h
// Justyn Durnford
// Created on 2021-01-17
// Last updated on 2021-02-12
// Header file for the Circle and CircleFr template structs.

#ifndef CIRCLE_H_INCLUDED
#define CIRCLE_H_INCLUDED

#include "Point.h"

namespace Jlib
{
	template <arithmetic value_type> struct Circle
	{
		Point2<value_type> center;
		value_type radius = 0;

		// Default constructor.
		Circle() = default;

		// Copy constructor.
		// Copies the values from the passed Circle into the new Circle.
		Circle(const Circle& other) = default;

		// Move constructor.
		// Moves the passed Circle into the new Circle.
		Circle(Circle&& other) = default;

		// 3-parameter constructor.
		// Sets the x component of the Circle to new_x.
		// Sets the y component of the Circle to new_y.
		// Sets the radius of the Circle to new_radius.
		Circle(value_type new_x, value_type new_y, value_type new_radius)
		{
			center.setAll(new_x, new_y);
			radius = new_radius;
		}

		// Point2 constructor.
		// Sets the center of the Circle to the given Point2.
		// Sets the radius of the Circle to new_radius.
		Circle(const Point2<value_type>& P, value_type new_radius)
		{
			center = P;
			radius = new_radius;
		}

		// Copy assignment operator.
		// Copies the values from the passed Circle into the new Circle.
		Circle& operator = (const Circle& other) = default;

		// Move assignment operator.
		// Moves the passed Circle into the new Circle.
		Circle& operator = (Circle&& other) = default;

		// Destructor.
		// Destroys the Circle and its data.
		~Circle() = default;

		// Returns the x component of the Circle.
		value_type& x() const
		{
			return center.x;
		}

		// Returns the y component of the Circle.
		value_type& y() const
		{
			return center.y;
		}

		// Sets the x component of the Circle to new_x.
		void setX(value_type new_x)
		{
			center.x = new_x;
		}

		// Sets the y component of the Circle to new_y.
		void setY(value_type new_y)
		{
			center.y = new_y;
		}

		// Sets the x component of the Circle to new_x.
		// Sets the y component of the Circle to new_y.
		// Sets the radius of the Circle to new_radius.
		void setAll(value_type new_x, value_type new_y, value_type new_radius)
		{
			center.setAll(new_x, new_y);
			radius = new_radius;
		}

		// Sets the center of the Circle to the given Point2.
		// Sets the radius of the Circle to new_radius.
		void setAll(const Point2<value_type>& P, value_type new_radius)
		{
			center = P;
			radius = new_radius;
		}

		// Returns the circumference of the Circle.
		double circumference() const
		{
			return double(2.0 * M_PI * radius);
		}

		// Returns the area of the Circle.
		double area() const
		{
			return double(M_PI * std::pow(radius, 2));
		}

		// Returns a std::string representation of the Circle.
		std::string toString() const
		{
			return center.toString() + ", " + std::to_string(radius);
		}
	};

	///////////////////////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////////////////////
	//////                                   FRACTION VARIATION                                  //////
	///////////////////////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////////////////////

	template <fraction_t value_type> struct CircleFr
	{
		Point2Fr<value_type> center;
		value_type radius = 0;

		// Default constructor.
		CircleFr() = default;

		// Copy constructor.
		// Copies the values from the passed CircleFr into the new CircleFr.
		CircleFr(const CircleFr& other) = default;

		// Move constructor.
		// Moves the passed CircleFr into the new CircleFr.
		CircleFr(CircleFr&& other) = default;

		// 3-parameter constructor.
		// Sets the x component of the CircleFr to new_x.
		// Sets the y component of the CircleFr to new_y.
		// Sets the radius of the CircleFr to new_radius.
		CircleFr(value_type new_x, value_type new_y, value_type new_radius)
		{
			center.setAll(new_x, new_y);
			radius = new_radius;
		}

		// Point2Fr constructor.
		// Sets the center of the CircleFr to the given Point2Fr.
		// Sets the radius of the CircleFr to new_radius.
		CircleFr(const Point2Fr<value_type>& P, value_type new_radius)
		{
			center = P;
			radius = new_radius;
		}

		// Copy assignment operator.
		// Copies the values from the passed CircleFr into the new CircleFr.
		CircleFr& operator = (const CircleFr& other) = default;

		// Move assignment operator.
		// Moves the passed CircleFr into the new CircleFr.
		CircleFr& operator = (CircleFr&& other) = default;

		// Destructor.
		// Destroys the CircleFr and its data.
		~CircleFr() = default;

		// Returns the x component of the CircleFr.
		value_type& x() const
		{
			return center.x;
		}

		// Returns the y component of the CircleFr.
		value_type& y() const
		{
			return center.y;
		}

		// Sets the x component of the CircleFr to new_x.
		void setX(value_type new_x)
		{
			center.x = new_x;
		}

		// Sets the y component of the CircleFr to new_y.
		void setY(value_type new_y)
		{
			center.y = new_y;
		}

		// Sets the x component of the CircleFr to new_x.
		// Sets the y component of the CircleFr to new_y.
		// Sets the radius of the CircleFr to new_radius.
		void setAll(value_type new_x, value_type new_y, value_type new_radius)
		{
			center.setAll(new_x, new_y);
			radius = new_radius;
		}

		// Sets the center of the CircleFr to the given Point2Fr.
		// Sets the radius of the CircleFr to new_radius.
		void setAll(const Point2Fr<value_type>& P, value_type new_radius)
		{
			center = P;
			radius = new_radius;
		}

		// Returns the circumference of the CircleFr.
		double circumference() const
		{
			return double(2.0 * M_PI * radius.evaluate());
		}

		// Returns the area of the CircleFr.
		double area() const
		{
			return double(M_PI * std::pow(radius.evaluate(), 2));
		}

		// Returns a std::string representation of the CircleFr.
		std::string toString() const
		{
			return center.toString() + ", " + radius.toString();
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
	//  - A.x == B.x           AND
	//  - A.y == B.y           AND
	//  - A.radius == B.radius
	// Returns false otherwise.
	template <arithmetic T> bool operator == (const Circle<T>& A, const Circle<T>& B)
	{
		if (A.center != B.center)
			return false;

		if (A.radius != B.radius)
			return false;

		return true;
	}

	// Inequality comparison operator.
	// Returns true if:
	//  - A.x != B.x OR
	//  - A.y != B.y OR
	//  - A.radius != B.radius
	// Returns false otherwise.
	template <arithmetic T> bool operator != (const Circle<T>& A, const Circle<T>& B)
	{
		if (A.center != B.center)
			return true;

		if (A.radius != B.radius)
			return true;

		return false;
	}

	// Equality comparison operator.
	// Returns true if:
	//  - A.x == B.x           AND
	//  - A.y == B.y           AND
	//  - A.radius == B.radius
	// Returns false otherwise.
	template <fraction_t T> bool operator == (const CircleFr<T>& A, const CircleFr<T>& B)
	{
		if (A.center != B.center)
			return false;

		if (A.radius != B.radius)
			return false;

		return true;
	}

	// Inequality comparison operator.
	// Returns true if:
	//  - A.x != B.x OR
	//  - A.y != B.y OR
	//  - A.radius != B.radius
	// Returns false otherwise.
	template <fraction_t T> bool operator != (const CircleFr<T>& A, const CircleFr<T>& B)
	{
		if (A.center != B.center)
			return true;

		if (A.radius != B.radius)
			return true;

		return false;
	}

	// std::ostream insertion operator.
	template <arithmetic T> std::ostream& operator << (std::ostream& os, const Circle<T>& c)
	{
		os << c.toString();
		return os;
	}

	// std::ostream insertion operator.
	template <fraction_t T> std::ostream& operator << (std::ostream& os, const CircleFr<T>& c)
	{
		os << c.toString();
		return os;
	}

	///////////////////////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////////////////////
	//////                                    GLOBAL FUNCTIONS                                   //////
	///////////////////////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////////////////////

	template <arithmetic T> void print(const Circle<T>& c)
	{
		std::cout << c;
	}

	template <arithmetic T> void println(const Circle<T>& c)
	{
		std::cout << c << std::endl;
	}

	template <fraction_t T> void print(const CircleFr<T>& c)
	{
		std::cout << c;
	}

	template <fraction_t T> void println(const CircleFr<T>& c)
	{
		std::cout << c << std::endl;
	}
}

#endif // CIRCLE_H_INCLUDED