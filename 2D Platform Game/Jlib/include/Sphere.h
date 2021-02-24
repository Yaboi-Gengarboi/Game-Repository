// Jlib
// Sphere.h
// Justyn Durnford
// Created on 2021-01-17
// Last updated on 2021-02-12
// Header file for the Sphere and SphereFr template structs.

#ifndef SPHERE_H_INCLUDED
#define SPHERE_H_INCLUDED

#include "Point.h"

namespace Jlib
{
	template <arithmetic value_type> struct Sphere
	{
		Point3<value_type> center;
		value_type radius = 0;

		// Default constructor.
		Sphere() = default;

		// Copy constructor.
		// Copies the values from the passed Sphere into the new Sphere.
		Sphere(const Sphere& other) = default;

		// Move constructor.
		// Moves the passed Sphere into the new Sphere.
		Sphere(Sphere&& other) = default;

		// 4-parameter constructor.
		// Sets the x component of the Sphere to new_x.
		// Sets the y component of the Sphere to new_y.
		// Sets the z component of the Sphere to new_z.
		// Sets the radius of the Sphere to new_radius.
		Sphere(value_type new_x, value_type new_y, value_type new_z, value_type new_radius)
		{
			center.setAll(new_x, new_y, new_z);
			radius = new_radius;
		}

		// Point3 constructor.
		// Sets the center of the Sphere to the given Point3.
		// Sets the radius of the Sphere to new_radius.
		Sphere(const Point3<value_type>& P, value_type new_radius)
		{
			center = P;
			radius = new_radius;
		}

		// Copy assignment operator.
		// Copies the values from the passed Sphere into the new Sphere.
		Sphere& operator = (const Sphere& other) = default;

		// Move assignment operator.
		// Moves the passed Sphere into the new Sphere.
		Sphere& operator = (Sphere&& other) = default;

		// Destructor.
		// Destroys the Sphere and its data.
		~Sphere() = default;

		// Returns the x component of the Sphere.
		value_type& x() const
		{
			return center.x;
		}

		// Returns the y component of the Sphere.
		value_type& y() const
		{
			return center.y;
		}

		// Returns the z component of the Sphere.
		value_type& z() const
		{
			return center.z;
		}

		// Sets the x component of the Sphere to new_x.
		void setX(value_type new_x)
		{
			center.x = new_x;
		}

		// Sets the y component of the Sphere to new_y.
		void setY(value_type new_y)
		{
			center.y = new_y;
		}

		// Sets the z component of the Sphere to new_z.
		void setZ(value_type new_z)
		{
			center.z = new_z;
		}

		// Sets the x component of the Sphere to new_x.
		// Sets the y component of the Sphere to new_y.
		// Sets the z component of the Sphere to new_z.
		// Sets the radius of the Sphere to new_radius.
		void setAll(value_type new_x, value_type new_y, value_type new_z, value_type new_radius)
		{
			center.setAll(new_x, new_y, new_z);
			radius = new_radius;
		}

		// Sets the center of the Sphere to the given Point3.
		// Sets the radius of the Sphere to new_radius.
		void setAll(const Point3<value_type>& P, value_type new_radius)
		{
			center = P;
			radius = new_radius;
		}

		// Returns the surface area of the Sphere.
		double surfaceArea() const
		{
			return double(4.0 * M_PI * std::pow(radius, 2));
		}

		// Returns the volume of the Sphere.
		double volume() const
		{
			return double(( 4.0 / 3.0 ) * M_PI * std::pow(radius, 3));
		}

		// Returns a std::string representation of the Sphere.
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

	template <fraction_t value_type> struct SphereFr
	{
		Point3Fr<value_type> center;
		value_type radius = 0;

		// Default constructor.
		SphereFr() = default;

		// Copy constructor.
		// Copies the values from the passed SphereFr into the new SphereFr.
		SphereFr(const SphereFr& other) = default;

		// Move constructor.
		// Moves the passed Sphere into the new SphereFr.
		SphereFr(SphereFr&& other) = default;

		// 4-parameter constructor.
		// Sets the x component of the SphereFr to new_x.
		// Sets the y component of the SphereFr to new_y.
		// Sets the z component of the SphereFr to new_z.
		// Sets the radius of the SphereFr to new_radius.
		SphereFr(value_type new_x, value_type new_y, value_type new_z, value_type new_radius)
		{
			center.setAll(new_x, new_y, new_z);
			radius = new_radius;
		}

		// Point3Fr constructor.
		// Sets the center of the SphereFr to the given Point3Fr.
		// Sets the radius of the SphereFr to new_radius.
		SphereFr(const Point3Fr<value_type>& P, value_type new_radius)
		{
			center = P;
			radius = new_radius;
		}

		// Copy assignment operator.
		// Copies the values from the passed SphereFr into the new SphereFr.
		SphereFr& operator = (const SphereFr& other) = default;

		// Move assignment operator.
		// Moves the passed SphereFr into the new SphereFr.
		SphereFr& operator = (SphereFr&& other) = default;

		// Destructor.
		// Destroys the SphereFr and its data.
		~SphereFr() = default;

		// Returns the x component of the SphereFr.
		value_type& x() const
		{
			return center.x;
		}

		// Returns the y component of the SphereFr.
		value_type& y() const
		{
			return center.y;
		}

		// Returns the z component of the SphereFr.
		value_type& z() const
		{
			return center.z;
		}

		// Sets the x component of the SphereFr to new_x.
		void setX(value_type new_x)
		{
			center.x = new_x;
		}

		// Sets the y component of the SphereFr to new_y.
		void setY(value_type new_y)
		{
			center.y = new_y;
		}

		// Sets the z component of the SphereFr to new_z.
		void setZ(value_type new_z)
		{
			center.z = new_z;
		}

		// Sets the x component of the SphereFr to new_x.
		// Sets the y component of the SphereFr to new_y.
		// Sets the z component of the SphereFr to new_z.
		// Sets the radius of the SphereFr to new_radius.
		void setAll(value_type new_x, value_type new_y, value_type new_z, value_type new_radius)
		{
			center.setAll(new_x, new_y, new_z);
			radius = new_radius;
		}

		// Sets the center of the SphereFr to the given Point3Fr.
		// Sets the radius of the SphereFr to new_radius.
		void setAll(const Point3Fr<value_type>& P, value_type new_radius)
		{
			center = P;
			radius = new_radius;
		}

		// Returns the surface area of the SphereFr.
		double surfaceArea() const
		{
			return double(4.0 * M_PI * std::pow(radius.evaluate(), 2));
		}

		// Returns the volume of the Sphere.
		double volume() const
		{
			return double(( 4.0 / 3.0 ) * M_PI * std::pow(radius.evaluate(), 3));
		}

		// Returns a std::string representation of the Sphere.
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
	//  - A.z == B.z           AND
	//  - A.radius == B.radius
	// Returns false otherwise.
	template <arithmetic T> bool operator == (const Sphere<T>& A, const Sphere<T>& B)
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
	//  - A.z != B.z OR
	//  - A.radius != B.radius
	// Returns false otherwise.
	template <arithmetic T> bool operator != (const Sphere<T>& A, const Sphere<T>& B)
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
	//  - A.z == B.z           AND
	//  - A.radius == B.radius
	// Returns false otherwise.
	template <fraction_t T> bool operator == (const SphereFr<T>& A, const SphereFr<T>& B)
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
	//  - A.z != B.z OR
	//  - A.radius != B.radius
	// Returns false otherwise.
	template <fraction_t T> bool operator != (const SphereFr<T>& A, const SphereFr<T>& B)
	{
		if (A.center != B.center)
			return true;

		if (A.radius != B.radius)
			return true;

		return false;
	}

	// std::ostream insertion operator.
	template <arithmetic T> std::ostream& operator << (std::ostream& os, const Sphere<T>& s)
	{
		os << s.toString();
		return os;
	}

	// std::ostream insertion operator.
	template <fraction_t T> std::ostream& operator << (std::ostream& os, const SphereFr<T>& s)
	{
		os << s.toString();
		return os;
	}

	///////////////////////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////////////////////
	//////                                    GLOBAL FUNCTIONS                                   //////
	///////////////////////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////////////////////

	template <arithmetic T> void print(const Sphere<T>& s)
	{
		std::cout << s;
	}

	template <arithmetic T> void println(const Sphere<T>& s)
	{
		std::cout << s << std::endl;
	}

	template <fraction_t T> void print(const SphereFr<T>& s)
	{
		std::cout << s;
	}

	template <fraction_t T> void println(const SphereFr<T>& s)
	{
		std::cout << s << std::endl;
	}
}

#endif // SPHERE_H_INCLUDED