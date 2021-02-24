// Jlib
// Vector.h
// Justyn Durnford
// Created on 2020-10-12
// Last updated on 2021-02-24
// Header file for the Vector2, Vector2Fr, Vector3 and Vector3Fr template structs.

#ifndef VECTOR_H_INCLUDED
#define VECTOR_H_INCLUDED

#ifndef _USE_MATH_DEFINES
#define _USE_MATH_DEFINES

#endif // _USE_MATH_DEFINES

#include "Angle.h"
#include "Point.h"

namespace Jlib
{
	// This struct provides a representation of a mathematical 
	// vector in two-dimensional space.
	template <arithmetic T> struct Vector2
	{
		T x = 0;
		T y = 0;

		// Default constructor.
		Vector2() = default;

		// Copy constructor.
		// Copies the values from the passed Vector2 into the new Vector2.
		Vector2(const Vector2& other) = default;

		// Move constructor.
		// Moves the passed Vector2 into the new Vector2.
		Vector2(Vector2&& other) = default;

		// 2-T constructor.
		// Sets the x component of the Vector2 to new_x.
		// Sets the y component of the Vector2 to new_y.
		Vector2(T new_x, T new_y)
		{
			x = new_x;
			y = new_y;
		}

		// Angle constructor.
		// Sets the x component of the Vector2 to magnitude * cos(ang).
		// Sets the y component of the Vector2 to magnitude * sin(ang).
		Vector2(const Angle& ang, T magnitude)
		{
			x = T(magnitude * Jlib::cos(ang));
			y = T(magnitude * Jlib::sin(ang));
		}

		// 1-Point2 constructor.
		// Sets the x component of the Vector2 to P.x.
		// Sets the y component of the Vector2 to P.y.
		Vector2(const Point2<T>& P)
		{
			x = P.x;
			y = P.y;
		}

		// 2-Point2 constructor.
		// Creates the Vector2 as the displacement vector from
		// the Point2 P to the Point2 Q.
		Vector2(const Point2<T>& P, const Point2<T>& Q)
		{
			x = Q.x - P.x;
			y = Q.y - P.y;
		}

		// Copy assignment operator.
		// Copies the values from the passed Vector2 into the new Vector2.
		Vector2& operator = (const Vector2& other) = default;

		// Move assignment operator.
		// Moves the passed Vector2 into the new Vector2.
		Vector2& operator = (Vector2&& other) = default;

		// Destructor.
		// Destroys the Vector2 and its data.
		~Vector2() = default;

		// Sets the x component of the Vector2 to new_x.
		// Sets the y component of the Vector2 to new_y.
		void setAll(T new_x, T new_y)
		{
			x = new_x;
			y = new_y;
		}

		// Sets the x component of the Vector2 to P.x
		// Sets the y component of the Vector2 to P.y
		void setAll(const Point2<T>& P)
		{
			x = P.x;
			y = P.y;
		}

		// Returns the magnitude of the Vector2.
		double magnitude() const
		{
			return std::sqrt(std::pow(x, 2) + std::pow(y, 2));
		}

		// Returns the angle between the Vector2 and the x-axis.
		Angle angle() const
		{
			return Jlib::arctan(double(y) / double(x));
		}

		// Returns the endpoint of the Vector2.
		Point2<T> endpoint() const
		{
			return Point2<T>(x, y);
		}

		// Returns a unit vector in the direction of the Vector2.
		Vector2<double> unitVector() const
		{
			double m = magnitude();
			return Vector2<double>(x / m, y / m);
		}

		// Clears the values of the Vector2.
		void clear()
		{
			x = 0;
			y = 0;
		}

		// Returns a std::string representation of the Vector2.
		std::string toString() const
		{
			return '<' + std::to_string(x) + ", " + std::to_string(y) + '>';
		}

		// Addition assignment operator.
		// Adds the components of the given Vector2 V onto the
		// corresponding components of this Vector2.
		Vector2& operator += (const Vector2& V)
		{
			x += V.x;
			y += V.y;

			return *this;
		}

		// Subtraction assignment operator.
		// Subtracts the components of the given Vector2 V from the
		// corresponding components of this Vector2.
		Vector2& operator -= (const Vector2& V)
		{
			x -= V.x;
			y -= V.y;

			return *this;
		}

		// Multiplication assignment operator.
		// Multiplies the components of this Vector2 by value.
		template <arithmetic Ty> Vector2& operator *= (Ty value)
		{
			x *= value;
			y *= value;

			return *this;
		}

		// Division assignment operator.
		// Divides the components of this Vector2 by value.
		template <arithmetic Ty> Vector2& operator /= (Ty value)
		{
			x /= value;
			y /= value;

			return *this;
		}
	};

	///////////////////////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////////////////////
	//////                                 2D FRACTION VARIATION                                 //////
	///////////////////////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////////////////////

	// This struct provides a representation of a mathematical 
	// vector in two-dimensional space.
	template <fraction_t T> struct Vector2Fr
	{
		T x = 0;
		T y = 0;

		// Default constructor.
		Vector2Fr() = default;

		// Copy constructor.
		// Copies the values from the passed Vector2Fr into the new Vector2Fr.
		Vector2Fr(const Vector2Fr& other) = default;

		// Move constructor.
		// Moves the passed Vector2Fr into the new Vector2Fr.
		Vector2Fr(Vector2Fr&& other) = default;

		// 2-T constructor.
		// Sets the x component of the Vector2Fr to new_x.
		// Sets the y component of the Vector2Fr to new_y.
		Vector2Fr(T new_x, T new_y)
		{
			x = new_x;
			y = new_y;
		}

		// Angle constructor.
		// Sets the x component of the Vector2Fr to magnitude * cos(ang).
		// Sets the y component of the Vector2Fr to magnitude * sin(ang).
		Vector2Fr(const Angle& ang, T magnitude)
		{
			x = T(magnitude * Jlib::cos(ang));
			y = T(magnitude * Jlib::sin(ang));
		}

		// 1-Point2Fr constructor.
		// Sets the x component of the Vector2Fr to P.x.
		// Sets the y component of the Vector2Fr to P.y.
		Vector2Fr(const Point2Fr<T>& P)
		{
			x = P.x;
			y = P.y;
		}

		// 2-Point2Fr constructor.
		// Creates the Vector2Fr as the displacement vector from
		// the Point2Fr P to the Point2Fr Q.
		Vector2Fr(const Point2Fr<T>& P, const Point2Fr<T>& Q)
		{
			x = Q.x - P.x;
			y = Q.y - P.y;
		}

		// Copy assignment operator.
		// Copies the values from the passed Vector2Fr into the new Vector2Fr.
		Vector2Fr& operator = (const Vector2Fr& other) = default;

		// Move assignment operator.
		// Moves the passed Vector2Fr into the new Vector2Fr.
		Vector2Fr& operator = (Vector2Fr&& other) = default;

		// Destructor.
		// Destroys the Vector2Fr and its data.
		~Vector2Fr() = default;

		// Sets the x component of the Vector2Fr to new_x.
		// Sets the y component of the Vector2Fr to new_y.
		void setAll(T new_x, T new_y)
		{
			x = new_x;
			y = new_y;
		}

		// Sets the x component of the Vector2Fr to P.x
		// Sets the y component of the Vector2Fr to P.y
		void setAll(const Point2Fr<T>& P)
		{
			x = P.x;
			y = P.y;
		}

		// Returns the magnitude of the Vector2Fr.
		double magnitude() const
		{
			return std::sqrt(std::pow(x.evaluate(), 2) + std::pow(y.evaluate(), 2));
		}

		// Returns the angle between the Vector2Fr and the x-axis.
		Angle angle() const
		{
			return Jlib::arctan(double(y.evaluate()) / double(x.evaluate()));
		}

		// Returns the endpoint of the Vector2Fr.
		Point2Fr<T> endpoint() const
		{
			return Point2Fr<T>(x, y);
		}

		// Returns a unit vector in the direction of the Vector2Fr.
		Vector2<double> unitVector() const
		{
			double m = magnitude();
			return Vector2<double>(x.evaluate() / m, y.evaluate() / m);
		}

		// Clears the values of the Vector2Fr.
		void clear()
		{
			x = 0;
			y = 0;
		}

		// Returns a std::string representation of the Vector2Fr.
		std::string toString() const
		{
			return '<' + x.toString() + ", " + y.toString() + '>';
		}

		// Addition assignment operator.
		// Adds the components of the given Vector2Fr V onto the
		// corresponding components of this Vector2Fr.
		Vector2Fr& operator += (const Vector2Fr& V)
		{
			x += V.x;
			y += V.y;

			return *this;
		}

		// Subtraction assignment operator.
		// Subtracts the components of the given Vector2Fr V from the
		// corresponding components of this Vector2Fr.
		Vector2Fr& operator -= (const Vector2Fr& V)
		{
			x -= V.x;
			y -= V.y;

			return *this;
		}

		// Multiplication assignment operator.
		// Multiplies the components of this Vector2Fr by value.
		template <arithmetic T> Vector2Fr& operator *= (T value)
		{
			x *= value;
			y *= value;

			return *this;
		}

		// Division assignment operator.
		// Divides the components of this Vector2Fr by value.
		template <arithmetic T> Vector2Fr& operator /= (T value)
		{
			x /= value;
			y /= value;

			return *this;
		}

		// Multiplication assignment operator.
		// Multiplies the components of this Vector2Fr by value.
		template <fraction_t Ty> Vector2Fr& operator *= (Ty value)
		{
			x *= value;
			y *= value;

			return *this;
		}

		// Division assignment operator.
		// Divides the components of this Vector2Fr by value.
		template <fraction_t Ty> Vector2Fr& operator /= (Ty value)
		{
			x /= value;
			y /= value;

			return *this;
		}
	};

	///////////////////////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////////////////////
	//////                                3D ARITHMETIC VARIATION                                //////
	///////////////////////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////////////////////

	// This struct provides a representation of a mathematical 
	// vector in three-dimensional space.
	template <typename T> struct Vector3
	{
		T x = 0;
		T y = 0;
		T z = 0;

		// Default constructor.
		Vector3() = default;

		// Vector2 copy constructor.
		// Allows for the conversion from a Vector2 to a Vector3.
		Vector3(const Vector2<T>& other)
		{
			x = other.x;
			y = other.y;
			z = 0;
		}

		// Vector3 copy constructor.
		// Copies the values from the passed Vector3 into the new Vector3.
		Vector3(const Vector3& other) = default;

		// Move constructor.
		// Moves the passed Vector2 into the new Vector3.
		Vector3(Vector3&& other) = default;

		// 3-T constructor.
		// Sets the x component of the Vector3 to new_x.
		// Sets the y component of the Vector3 to new_y.
		// Sets the z component of the Vector3 to new_z.
		Vector3(T new_x, T new_y, T new_z)
		{
			x = new_x;
			y = new_y;
			z = new_z;
		}

		// 1-Point2 constructor.
		// Sets the x component of the Vector3 to P.x.
		// Sets the y component of the Vector3 to P.y.
		Vector3(const Point2<T>& P)
		{
			x = P.x;
			y = P.y;
			z = 0;
		}

		// 1-Point3 constructor.
		// Sets the x component of the Vector3 to P.x.
		// Sets the y component of the Vector3 to P.y.
		// Sets the z component of the Vector3 to P.z.
		Vector3(const Point3<T>& P)
		{
			x = P.x;
			y = P.y;
			z = P.z;
		}

		// 2-Point2 constructor.
		// Creates the Vector3 as the displacement vector from
		// the Point2 P to the Point2 Q.
		Vector3(const Point2<T>& P, const Point2<T>& Q)
		{
			x = Q.x - P.x;
			y = Q.y - P.y;
			z = 0;
		}

		// 2-Point3 constructor.
		// Creates the Vector3 as the displacement vector from
		// the Point3 P to the Point3 Q.
		Vector3(const Point3<T>& P, const Point3<T>& Q)
		{
			x = Q.x - P.x;
			y = Q.y - P.y;
			z = Q.z - P.z;
		}

		// Vector2 copy assignment operator.
		// Copies the values from the passed Vector2 into the new Vector3.
		Vector3& operator = (const Vector2<T>& other)
		{
			x = other.x;
			y = other.y;
			z = 0;

			return *this;
		}

		// Vector3 copy assignment operator.
		// Copies the values from the passed Vector3 into the new Vector3.
		Vector3& operator = (const Vector3& other) = default;

		// Move assignment operator.
		// Moves the passed Vector3 into the new Vector3.
		Vector3& operator = (Vector3&& other) = default;

		// Destructor.
		// Destroys the Vector3 and its data.
		~Vector3() = default;

		// Sets the x component of the Vector3 to new_x.
		// Sets the y component of the Vector3 to new_y.
		// Sets the z component of the Vector3 to new_z.
		void setAll(T new_x, T new_y, T new_z)
		{
			x = new_x;
			y = new_y;
			z = new_z;
		}

		// Sets the x component of the Vector3 to P.x
		// Sets the y component of the Vector3 to P.y
		// Sets the z component of the Vector3 to P.z
		void setAll(const Point3<T>& P)
		{
			x = P.x;
			y = P.y;
		}

		// Returns the magnitude of the Vector3.
		double magnitude() const
		{
			return std::sqrt(std::pow(x, 2) + std::pow(y, 2) + std::pow(z, 2));
		}

		// Returns the endpoint of the Vector3.
		Point3<T> endpoint() const
		{
			return Point3<T>(x, y, z);
		}

		// Returns a unit vector in the direction of the Vector3.
		Vector3<double> unitVector() const
		{
			double m = magnitude();
			return Vector3<double>(double(x) / m, double(y) / m, double(z) / m);
		}

		// Clears the values of the Vector3.
		void clear()
		{
			x = 0;
			y = 0;
			z = 0;
		}

		// Returns a std::string representation of the Vector3.
		std::string toString() const
		{
			return '<' + std::to_string(x) + ", " + std::to_string(y) + ", " + std::to_string(z) + '>';
		}

		// Addition assignment operator.
		Vector3& operator += (const Vector3& V)
		{
			x += V.x;
			y += V.y;
			z += V.z;

			return *this;
		}

		// Subtraction assignment operator.
		Vector3& operator -= (const Vector3& V)
		{
			x -= V.x;
			y -= V.y;
			z -= V.z;

			return *this;
		}

		// Multiplication assignment operator.
		template <arithmetic Ty> Vector3& operator *= (Ty value)
		{
			x *= value;
			y *= value;
			z *= value;

			return *this;
		}

		// Division assignment operator.
		template <arithmetic Ty> Vector3& operator /= (Ty value)
		{
			x /= value;
			y /= value;
			z /= value;

			return *this;
		}
	};

	///////////////////////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////////////////////
	//////                                 3D FRACTION VARIATION                                 //////
	///////////////////////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////////////////////

	// This struct provides a representation of a mathematical 
	// vector in three-dimensional space.
	template <fraction_t T> struct Vector3Fr
	{
		T x = 0;
		T y = 0;
		T z = 0;

		// Default constructor.
		Vector3Fr() = default;

		// Vector2 copy constructor.
		// Allows for the conversion from a Vector2 to a Vector3Fr.
		Vector3Fr(const Vector2<T>& other)
		{
			x = other.x;
			y = other.y;
			z = 0;
		}

		// Vector3Fr copy constructor.
		// Copies the values from the passed Vector3Fr into the new Vector3Fr.
		Vector3Fr(const Vector3Fr& other) = default;

		// Move constructor.
		// Moves the passed Vector3Fr into the new Vector3Fr.
		Vector3Fr(Vector3Fr&& other) = default;

		// 3-T constructor.
		// Sets the x component of the Vector3Fr to new_x.
		// Sets the y component of the Vector3Fr to new_y.
		// Sets the z component of the Vector3Fr to new_z.
		Vector3Fr(T new_x, T new_y, T new_z)
		{
			x = new_x;
			y = new_y;
			z = new_z;
		}

		// 1-Point2Fr constructor.
		// Sets the x component of the Vector3Fr to P.x.
		// Sets the y component of the Vector3Fr to P.y.
		Vector3Fr(const Point2Fr<T>& P)
		{
			x = P.x;
			y = P.y;
			z = 0;
		}

		// 1-Point3Fr constructor.
		// Sets the x component of the Vector3Fr to P.x.
		// Sets the y component of the Vector3Fr to P.y.
		// Sets the z component of the Vector3Fr to P.z.
		Vector3Fr(const Point3Fr<T>& P)
		{
			x = P.x;
			y = P.y;
			z = P.z;
		}

		// 2-Point2Fr constructor.
		// Creates the Vector3Fr as the displacement vector from
		// the Point2Fr P to the Point2Fr Q.
		Vector3Fr(const Point2Fr<T>& P, const Point2Fr<T>& Q)
		{
			x = Q.x - P.x;
			y = Q.y - P.y;
			z = 0;
		}

		// 2-Point3 constructor.
		// Creates the Vector3Fr as the displacement vector from
		// the Point3 P to the Point3 Q.
		Vector3Fr(const Point3<T>& P, const Point3<T>& Q)
		{
			x = Q.x - P.x;
			y = Q.y - P.y;
			z = Q.z - P.z;
		}

		// Vector2 copy assignment operator.
		// Copies the values from the passed Vector2 into the new Vector3Fr.
		Vector3Fr& operator = (const Vector2<T>& other)
		{
			x = other.x;
			y = other.y;
			z = 0;

			return *this;
		}

		// Vector3Fr copy assignment operator.
		// Copies the values from the passed Vector3Fr into the new Vector3Fr.
		Vector3Fr& operator = (const Vector3Fr& other) = default;

		// Move assignment operator.
		// Moves the passed Vector3Fr into the new Vector3Fr.
		Vector3Fr& operator = (Vector3Fr&& other) = default;

		// Destructor.
		// Destroys the Vector3Fr and its data.
		~Vector3Fr() = default;

		// Sets the x component of the Vector3Fr to new_x.
		// Sets the y component of the Vector3Fr to new_y.
		// Sets the z component of the Vector3Fr to new_z.
		void setAll(T new_x, T new_y, T new_z)
		{
			x = new_x;
			y = new_y;
			z = new_z;
		}

		// Sets the x component of the Vector3Fr to P.x
		// Sets the y component of the Vector3Fr to P.y
		// Sets the z component of the Vector3Fr to P.z
		void setAll(const Point3<T>& P)
		{
			x = P.x;
			y = P.y;
		}

		// Returns the magnitude of the Vector3Fr.
		double magnitude() const
		{
			return std::sqrt(std::pow(x.evaluate(), 2) + std::pow(y.evaluate(), 2) + std::pow(z.evaluate(), 2));
		}

		// Returns the endpoint of the Vector3Fr.
		Point3Fr<T> endpoint() const
		{
			return Point3Fr<T>(x, y, z);
		}

		// Returns a unit vector in the direction of the Vector3Fr.
		Vector3<double> unitVector() const
		{
			double m = magnitude();
			return Vector3Fr<double>(double(x.evaluate()) / m, double(y.evaluate()) / m, double(z.evaluate()) / m);
		}

		// Clears the values of the Vector3Fr.
		void clear()
		{
			x = 0;
			y = 0;
			z = 0;
		}

		// Returns a std::string representation of the Vector3Fr.
		std::string toString() const
		{
			return '<' + x.toString() + ", " + y.toString() + ", " + z.toString() + '>';
		}

		// Addition assignment operator.
		Vector3Fr& operator += (const Vector3Fr& V)
		{
			x += V.x;
			y += V.y;
			z += V.z;

			return *this;
		}

		// Subtraction assignment operator.
		Vector3Fr& operator -= (const Vector3Fr& V)
		{
			x -= V.x;
			y -= V.y;
			z -= V.z;

			return *this;
		}

		// Multiplication assignment operator.
		template <arithmetic Ty> Vector3Fr& operator *= (Ty value)
		{
			x *= value;
			y *= value;
			z *= value;

			return *this;
		}

		// Division assignment operator.
		template <arithmetic Ty> Vector3Fr& operator /= (Ty value)
		{
			x /= value;
			y /= value;
			z /= value;

			return *this;
		}

		// Multiplication assignment operator.
		template <fraction_t Ty> Vector3Fr& operator *= (Ty value)
		{
			x *= value;
			y *= value;
			z *= value;

			return *this;
		}

		// Division assignment operator.
		template <fraction_t Ty> Vector3Fr& operator /= (Ty value)
		{
			x /= value;
			y /= value;
			z /= value;

			return *this;
		}
	};

	///////////////////////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////////////////////
	//////                            2D ARITHMETIC GLOBAL OPERATORS                             //////
	///////////////////////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////////////////////////////// 

	// Addition operator.
	template <arithmetic T> Vector2<T> operator + (const Vector2<T>& V, const Vector2<T>& U)
	{
		return Vector2<T>(V.x + U.x, V.y + U.y);
	}

	// Subtraction operator.
	template <arithmetic T> Vector2<T> operator - (const Vector2<T>& V, const Vector2<T>& U)
	{
		return Vector2<T>(V.x - U.x, V.y - U.y);
	}

	// Multiplication operator.
	template <arithmetic T> Vector2<T> operator * (const Vector2<T>& V, const T& value)
	{
		return Vector2<T>(V.x * value, V.y * value);
	}

	// Division operator.
	template <arithmetic T> Vector2<T> operator / (const Vector2<T>& V, const T& value)
	{
		return Vector2<T>(V.x / value, V.y / value);
	}

	// Equality comparison operator.
	// Compares the given Vector2s V and U for equality.
	// Returns true if:
	//  - V.x == U.x AND
	//  - V.y == U.y
	// Returns false otherwise.
	template <arithmetic T> bool operator == (const Vector2<T>& V, const Vector2<T>& U)
	{
		if (V.x != U.x)
			return false;

		if (V.y != U.y)
			return false;

		return true;
	}

	// Inequality comparison operator.
	// Compares the given Vector2s V and U for inequality.
	// Returns true if:
	//  - V.x != U.x OR
	//  - V.y != U.y
	// Returns false otherwise.
	template <arithmetic T> bool operator != (const Vector2<T>& V, const Vector2<T>& U)
	{
		if (V.x != U.x)
			return true;

		if (V.y != U.y)
			return true;

		return false;
	}

	// std::ostream insertion operator.
	template <arithmetic T> std::ostream& operator << (std::ostream& os, const Vector2<T>& V)
	{
		os << V.toString();
		return os;
	}

	///////////////////////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////////////////////
	//////                             2D FRACTION GLOBAL OPERATORS                              //////
	///////////////////////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////////////////////////////// 

	// Addition operator.
	template <fraction_t T> Vector2Fr<T> operator + (const Vector2Fr<T>& V, const Vector2Fr<T>& U)
	{
		return Vector2Fr<T>(V.x + U.x, V.y + U.y);
	}

	// Subtraction operator.
	template <fraction_t T> Vector2Fr<T> operator - (const Vector2Fr<T>& V, const Vector2Fr<T>& U)
	{
		return Vector2Fr<T>(V.x - U.x, V.y - U.y);
	}

	// Multiplication operator.
	template <fraction_t T> Vector2Fr<T> operator * (const Vector2Fr<T>& V, const T& value)
	{
		return Vector2<T>(V.x * value, V.y * value);
	}

	// Division operator.
	template <fraction_t T> Vector2Fr<T> operator / (const Vector2Fr<T>& V, const T& value)
	{
		return Vector2Fr<T>(V.x / value, V.y / value);
	}

	// Equality comparison operator.
	// Compares the given Vector2Frs V and U for equality.
	// Returns true if:
	//  - V.x == U.x AND
	//  - V.y == U.y
	// Returns false otherwise.
	template <fraction_t T> bool operator == (const Vector2Fr<T>& V, const Vector2Fr<T>& U)
	{
		if (V.x != U.x)
			return false;

		if (V.y != U.y)
			return false;

		return true;
	}

	// Inequality comparison operator.
	// Compares the given Vector2Frs V and U for inequality.
	// Returns true if:
	//  - V.x != U.x OR
	//  - V.y != U.y
	// Returns false otherwise.
	template <fraction_t T> bool operator != (const Vector2Fr<T>& V, const Vector2Fr<T>& U)
	{
		if (V.x != U.x)
			return true;

		if (V.y != U.y)
			return true;

		return false;
	}

	// std::ostream insertion operator.
	template <fraction_t T> std::ostream& operator << (std::ostream& os, const Vector2Fr<T>& V)
	{
		os << V.toString();
		return os;
	}

	///////////////////////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////////////////////
	//////                            3D ARITHMETIC GLOBAL OPERATORS                             //////
	///////////////////////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////////////////////

	// Addition operator.
	template <arithmetic T> Vector3<T> operator + (const Vector3<T>& V, const Vector3<T>& U)
	{
		return Vector3<T>(V.x + U.x, V.y + U.y, V.z + U.z);
	}

	// Subtraction operator.
	template <arithmetic T> Vector3<T> operator - (const Vector3<T>& V, const Vector3<T>& U)
	{
		return Vector3<T>(V.x - U.x, V.y - U.y, V.z - U.z);
	}

	// Multiplication operator.
	template <arithmetic T> Vector3<T> operator * (const Vector3<T>& V, const T& value)
	{
		return Vector3<T>(V.x * value, V.y * value, V.z * value);
	}

	// Division operator.
	template <arithmetic T> Vector3<T> operator / (const Vector3<T>& V, const T& value)
	{
		return Vector3<T>(V.x / value, V.y / value, V.z / value);
	}

	// Equality comparison operator.
	// Compares the given Vector3s V and U for equality.
	// Returns true if:
	//  - V.x == U.x AND
	//  - V.y == U.y AND
	//  - V.z == U.z
	// Returns false otherwise.
	template <arithmetic T> bool operator == (const Vector3<T>& V, const Vector3<T>& U)
	{
		if (V.x != U.x)
			return false;

		if (V.y != U.y)
			return false;

		if (V.z != U.z)
			return false;

		return true;
	}

	// Inequality comparison operator.
	// Compares the given Vector3s V and U for inequality.
	// Returns true if:
	//  - V.x != U.x OR
	//  - V.y != U.y OR
	//  - V.z != U.z
	// Returns false otherwise.
	template <arithmetic T> bool operator != (const Vector3<T>& V, const Vector3<T>& U)
	{
		if (V.x != U.x)
			return true;

		if (V.y != U.y)
			return true;

		if (V.z != U.z)
			return true;

		return false;
	}

	// std::ostream insertion operator.
	template <arithmetic T> std::ostream& operator << (std::ostream& os, const Vector3<T>& V)
	{
		os << V.toString();
		return os;
	}

	///////////////////////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////////////////////
	//////                             3D FRACTION GLOBAL OPERATORS                              //////
	///////////////////////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////////////////////

	// Addition operator.
	template <fraction_t T> Vector3Fr<T> operator + (const Vector3Fr<T>& V, const Vector3Fr<T>& U)
	{
		return Vector3Fr<T>(V.x + U.x, V.y + U.y, V.z + U.z);
	}

	// Subtraction operator.
	template <fraction_t T> Vector3Fr<T> operator - (const Vector3Fr<T>& V, const Vector3Fr<T>& U)
	{
		return Vector3Fr<T>(V.x - U.x, V.y - U.y, V.z - U.z);
	}

	// Multiplication operator.
	template <fraction_t T> Vector3Fr<T> operator * (const Vector3Fr<T>& V, const T& value)
	{
		return Vector3Fr<T>(V.x * value, V.y * value, V.z * value);
	}

	// Division operator.
	template <fraction_t T> Vector3Fr<T> operator / (const Vector3Fr<T>& V, const T& value)
	{
		return Vector3Fr<T>(V.x / value, V.y / value, V.z / value);
	}

	// Equality comparison operator.
	// Compares the given Vector3Frs V and U for equality.
	// Returns true if:
	//  - V.x == U.x AND
	//  - V.y == U.y AND
	//  - V.z == U.z
	// Returns false otherwise.
	template <fraction_t T> bool operator == (const Vector3Fr<T>& V, const Vector3Fr<T>& U)
	{
		if (V.x != U.x)
			return false;

		if (V.y != U.y)
			return false;

		if (V.z != U.z)
			return false;

		return true;
	}

	// Inequality comparison operator.
	// Compares the given Vector3Frs V and U for inequality.
	// Returns true if:
	//  - V.x != U.x OR
	//  - V.y != U.y OR
	//  - V.z != U.z
	// Returns false otherwise.
	template <fraction_t T> bool operator != (const Vector3Fr<T>& V, const Vector3Fr<T>& U)
	{
		if (V.x != U.x)
			return true;

		if (V.y != U.y)
			return true;

		if (V.z != U.z)
			return true;

		return false;
	}

	// std::ostream insertion operator.
	template <fraction_t T> std::ostream& operator << (std::ostream& os, const Vector3Fr<T>& V)
	{
		os << V.toString();
		return os;
	}

	///////////////////////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////////////////////
	//////                            2D ARITHMETIC GLOBAL FUNCTIONS                             //////
	///////////////////////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////////////////////////////// 

	// Returns the angle between the 2 given Vector2s.
	template <arithmetic T> Angle angle_between(const Vector2<T>& V, const Vector2<T>& U)
	{
		return Jlib::arccos(dot_product(V, U) / ( V.magnitude() * U.magnitude() ));
	}

	// Determines if the 2 given Vector2s are orthogonal to eachother.
	// Returns true if dot_product(V, U) == 0.
	// Returns false otherwise.
	template <arithmetic T> bool are_normal(const Vector2<T>& V, const Vector2<T>& U)
	{
		return dot_product(V, U) == 0;
	}

	// Returns the dot product of the 2 given Vector2s.
	template <arithmetic T> T dot_product(const Vector2<T>& V, const Vector2<T>& U)
	{
		return ( V.x * U.x + V.y * U.y );
	}

	// Returns the scalar projection of U onto V.
	template <arithmetic T> double scalar_proj(const Vector2<T>& V, const Vector2<T>& U)
	{
		return dot_product(V, U) / V.magnitude();
	}

	// Returns the vector projection of U onto V.
	template <arithmetic T> Vector2<double> vector_proj(const Vector2<T>& V, const Vector2<T>& U)
	{
		double d = ( dot_product(V, U) * 1.0 / dot_product(V, V) * 1.0 );
		return Vector2<double>(V.x * d, V.y * d);
	}

	template <arithmetic T> void print(const Vector2<T>& V)
	{
		std::cout << V;
	}

	template <arithmetic T> void println(const Vector2<T>& V)
	{
		std::cout << V << std::endl;
	}

	///////////////////////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////////////////////
	//////                             2D FRACTION GLOBAL FUNCTIONS                              //////
	///////////////////////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////////////////////////////// 

	// Returns the angle between the 2 given Vector2Frs.
	template <fraction_t T> Angle angle_between(const Vector2Fr<T>& V, const Vector2Fr<T>& U)
	{
		return Jlib::arccos(dot_product(V, U) / ( V.magnitude() * U.magnitude() ));
	}

	// Determines if the 2 given Vector2Frs are orthogonal to eachother.
	// Returns true if dot_product(V, U) == 0.
	// Returns false otherwise.
	template <fraction_t T> bool are_normal(const Vector2Fr<T>& V, const Vector2Fr<T>& U)
	{
		return dot_product(V, U) == 0;
	}

	// Returns the dot product of the 2 given Vector2Frs.
	template <fraction_t T> T dot_product(const Vector2Fr<T>& V, const Vector2Fr<T>& U)
	{
		return ( V.x * U.x + V.y * U.y );
	}

	// Returns the scalar projection of U onto V.
	template <fraction_t T> double scalar_proj(const Vector2Fr<T>& V, const Vector2Fr<T>& U)
	{
		return dot_product(V, U) / V.magnitude();
	}

	// Returns the vector projection of U onto V.
	template <fraction_t T> Vector2<double> vector_proj(const Vector2Fr<T>& V, const Vector2Fr<T>& U)
	{
		double d = ( dot_product(V, U) * 1.0 / dot_product(V, V) * 1.0 );
		return Vector2<double>(V.x * d, V.y * d);
	}

	template <fraction_t T> void print(const Vector2Fr<T>& V)
	{
		std::cout << V;
	}

	template <fraction_t T> void println(const Vector2Fr<T>& V)
	{
		std::cout << V << std::endl;
	}

	///////////////////////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////////////////////
	//////                            3D ARITHMETIC GLOBAL FUNCTIONS                             //////
	///////////////////////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////////////////////

	// Determines if the 2 given Vector3s are orthogonal to eachother.
	// Returns true if dot_product(V, U) == 0.
	// Returns false otherwise.
	template <arithmetic T> bool are_normal(const Vector3<T>& V, const Vector3<T>& U)
	{
		return dot_product(V, U) == 0;
	}

	// Returns the cross product of the 2 given Vector3s.
	template <arithmetic T> Vector3<T> cross_product(const Vector3<T>& V, const Vector3<T>& U)
	{
		return Vector3<T>(V.y * U.z - V.z * U.y, V.z * U.x - V.x * U.z, V.x * U.y - V.y * U.x);
	}

	// Returns the dot product of the 2 given Vector3s.
	template <arithmetic T> T dot_product(const Vector3<T>& V, const Vector3<T>& U)
	{
		return ( V.x * U.x + V.y * U.y + V.z * U.z );
	}

	// Returns the scalar projection of U onto V.
	template <arithmetic T> double scalar_proj(const Vector3<T>& V, const Vector3<T>& U)
	{
		return dot_product(V, U) / V.magnitude();
	}

	// Returns the vector projection of U onto V.
	template <arithmetic T> Vector3<double> vector_proj(const Vector3<T>& V, const Vector3<T>& U)
	{
		double d = ( dot_product(V, U) * 1.0 / dot_product(V, V) * 1.0 );
		return Vector3<double>(V.x * d, V.y * d, V.z * d);
	}

	template <arithmetic T> void print(const Vector3<T>& V)
	{
		std::cout << V;
	}

	template <arithmetic T> void println(const Vector3<T>& V)
	{
		std::cout << V << std::endl;
	}

	///////////////////////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////////////////////
	//////                             3D FRACTION GLOBAL FUNCTIONS                              //////
	///////////////////////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////////////////////

	// Determines if the 2 given Vector3Frs are orthogonal to eachother.
	// Returns true if dot_product(V, U) == 0.
	// Returns false otherwise.
	template <fraction_t T> bool are_normal(const Vector3Fr<T>& V, const Vector3Fr<T>& U)
	{
		return dot_product(V, U) == 0;
	}

	// Returns the cross product of the 2 given Vector3Frs.
	template <fraction_t T> Vector3Fr<T> cross_product(const Vector3Fr<T>& V, const Vector3Fr<T>& U)
	{
		return Vector3<T>(V.y * U.z - V.z * U.y, V.z * U.x - V.x * U.z, V.x * U.y - V.y * U.x);
	}

	// Returns the dot product of the 2 given Vector3Frs.
	template <fraction_t T> T dot_product(const Vector3Fr<T>& V, const Vector3Fr<T>& U)
	{
		return ( V.x * U.x + V.y * U.y + V.z * U.z );
	}

	// Returns the scalar projection of U onto V.
	template <fraction_t T> double scalar_proj(const Vector3Fr<T>& V, const Vector3Fr<T>& U)
	{
		return dot_product(V, U) / V.magnitude();
	}

	// Returns the vector projection of U onto V.
	template <fraction_t T> Vector3<double> vector_proj(const Vector3Fr<T>& V, const Vector3Fr<T>& U)
	{
		double d = ( dot_product(V, U) * 1.0 / dot_product(V, V) * 1.0 );
		return Vector3<double>(V.x * d, V.y * d, V.z * d);
	}

	template <fraction_t T> void print(const Vector3Fr<T>& V)
	{
		std::cout << V;
	}

	template <fraction_t T> void println(const Vector3Fr<T>& V)
	{
		std::cout << V << std::endl;
	}

	///////////////////////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////////////////////
	//////                                        TYPEDEFS                                       //////
	///////////////////////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////////////////////

	// Expands to Vector2<std::int32_t>
	typedef Vector2<std::int32_t> Vector2i;

	// Expands to Vector2<std::uint32_t>
	typedef Vector2<std::uint32_t> Vector2u;

	// Expands to Vector2<std::int8_t>
	typedef Vector2<std::int8_t> Vector2c;

	// Expands to Vector2<std::uint8_t>
	typedef Vector2<std::uint8_t> Vector2uc;

	// Expands to Vector2<std::int16_t>
	typedef Vector2<std::int16_t> Vector2s;

	// Expands to Vector2<std::uint16_t>
	typedef Vector2<std::uint16_t> Vector2us;

	// Expands to Vector2<float>
	typedef Vector2<float> Vector2f;

	// Expands to Vector2<double>
	typedef Vector2<double> Vector2d;

	// Expands to Vector2Fr<Fraction<std::int32_t>>
	typedef Vector2Fr<Fraction<std::int32_t>> Vector2Fri;

	// Expands to Vector2Fr<Fraction<std::uint32_t>>
	typedef Vector2Fr<Fraction<std::uint32_t>> Vector2Fru;

	// Expands to Vector2Fr<Fraction<std::int8_t>>
	typedef Vector2Fr<Fraction<std::int8_t>> Vector2Frc;

	// Expands to Vector2Fr<Fraction<std::uint8_t>>
	typedef Vector2Fr<Fraction<std::uint8_t>> Vector2Fruc;

	// Expands to Vector3<std::int32_t>
	typedef Vector3<std::int32_t> Vector3i;

	// Expands to Vector3<std::uint32_t>
	typedef Vector3<std::uint32_t> Vector3u;

	// Expands to Vector3<std::int8_t>
	typedef Vector3<std::int8_t> Vector3c;

	// Expands to Vector3<std::uint8_t>
	typedef Vector3<std::uint8_t> Vector3uc;

	// Expands to Vector3<std::int16_t>
	typedef Vector3<std::int16_t> Vector3s;

	// Expands to Vector3<std::uint16_t>
	typedef Vector3<std::uint16_t> Vector3us;

	// Expands to Vector3<float>
	typedef Vector3<float> Vector3f;

	// Expands to Vector3<double>
	typedef Vector3<double> Vector3d;

	// Expands to Vector3Fr<Fraction<std::int32_t>>
	typedef Vector3Fr<Fraction<std::int32_t>> Vector3Fri;

	// Expands to Vector3Fr<Fraction<std::uint32_t>>
	typedef Vector3Fr<Fraction<std::uint32_t>> Vector3Fru;

	// Expands to Vector3Fr<Fraction<std::int8_t>>
	typedef Vector3Fr<Fraction<std::int8_t>> Vector3Frc;

	// Expands to Vector3Fr<Fraction<std::uint8_t>>
	typedef Vector3Fr<Fraction<std::uint8_t>> Vector3Fruc;
}

#endif // VECTOR_H_INCLUDED