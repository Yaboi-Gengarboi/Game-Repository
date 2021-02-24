// Jlib
// Rectangle.h
// Justyn Durnford
// Created on 2021-01-17
// Last updated on 2021-02-12
// Header file for the Rectangle and RectangleFr template structs.

#ifndef RECTANGLE_H_INCLUDED
#define RECTANGLE_H_INCLUDED

#include "Point.h"

namespace Jlib
{
	template <arithmetic value_type> struct Rectangle
	{
		Point2<value_type> vertex;
		value_type width = 0;
		value_type height = 0;

		// Default constructor.
		Rectangle() = default;

		// Copy constructor.
		Rectangle(const Rectangle& other) = default;

		// Move constructor.
		Rectangle(Rectangle&& other) = default;

		// 4-parameter constructor.
		// Sets the x component of the vertex of the Rectangle to new_x.
		// Sets the y component of the vertex of the Rectangle to new_y.
		// Sets the width of the Rectangle to new_width.
		// Sets the height of the Rectangle to new_height.
		Rectangle(value_type new_x, value_type new_y, value_type new_width, value_type new_height)
		{
			vertex.setAll(new_x, new_y);
			width = new_width;
			height = new_height;
		}

		// Point2 constructor.
		// Sets the vertex of the Rectangle to the given Point2.
		// Sets the width of the Rectangle to new_width.
		// Sets the height of the Rectangle to new_height.
		Rectangle(const Point2<value_type>& P, value_type new_width, value_type new_height)
		{
			vertex = P;
			width = new_width;
			height = new_height;
		}

		// Copy assignment operator.
		Rectangle& operator = (const Rectangle& other) = default;

		// Move assignment operator.
		Rectangle& operator = (Rectangle&& other) = default;

		// Destructor.
		// Destroys the Rectangle and its data.
		~Rectangle() = default;

		// Returns the x component of the vertex of the Rectangle.
		value_type& x() const
		{
			return vertex.x;
		}

		// Returns the y component of the vertex of the Rectangle.
		value_type& y() const
		{
			return vertex.y;
		}

		// Sets the x component of the vertex of the Rectangle to new_x.
		void setX(value_type new_x)
		{
			vertex.x = new_x;
		}

		// Sets the y component of the vertex of the Rectangle to new_y.
		void setY(value_type new_y)
		{
			vertex.y = new_y;
		}

		// Sets the x component of the vertex of the Rectangle to new_x.
		// Sets the y component of the vertex of the Rectangle to new_y.
		// Sets the width of the Rectangle to new_width.
		// Sets the height of the Rectangle to new_height.
		void setAll(value_type new_x, value_type new_y, value_type new_width, value_type new_height)
		{
			vertex.setAll(new_x, new_y);
			width = new_width;
			height = new_height;
		}

		// Sets the vertex of the Rectangle to the given Point2.
		// Sets the width of the Rectangle to new_width.
		// Sets the height of the Rectangle to new_height.
		void setAll(const Point2<value_type>& P, value_type new_width, value_type new_height)
		{
			vertex = P;
			width = new_width;
			height = new_height;
		}

		// Returns the perimeter of the Rectangle.
		double perimeter() const
		{
			return 2.0 * ( width + height );
		}

		// Returns the area of the Rectangle.
		double area() const
		{
			return width * height;
		}

		// Returns a std::string representation of the Rectangle.
		std::string toString() const
		{
			return vertex.toString() + ", " + std::to_string(width) + ", " + std::to_string(height);
		}
	};

	///////////////////////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////////////////////
	//////                                    FRACTION VARIANT                                   //////
	///////////////////////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////////////////////

	template <fraction_t value_type> struct RectangleFr
	{
		Point2Fr<value_type> vertex;
		value_type width = 0;
		value_type height = 0;

		// Default constructor.
		RectangleFr() = default;

		// Copy constructor.
		RectangleFr(const RectangleFr& other) = default;

		// Move constructor.
		RectangleFr(RectangleFr&& other) = default;

		// 4-parameter constructor.
		// Sets the x component of the vertex of the RectangleFr to new_x.
		// Sets the y component of the vertex of the RectangleFr to new_y.
		// Sets the width of the RectangleFr to new_width.
		// Sets the height of the RectangleFr to new_height.
		RectangleFr(value_type new_x, value_type new_y, value_type new_width, value_type new_height)
		{
			vertex.setAll(new_x, new_y);
			width = new_width;
			height = new_height;
		}

		// Point2Fr constructor.
		// Sets the vertex of the RectangleFr to the given Point2Fr.
		// Sets the width of the RectangleFr to new_width.
		// Sets the height of the RectangleFr to new_height.
		RectangleFr(const Point2Fr<value_type>& P, value_type new_width, value_type new_height)
		{
			vertex = P;
			width = new_width;
			height = new_height;
		}

		// Copy assignment operator.
		RectangleFr& operator = (const RectangleFr& other) = default;

		// Move assignment operator.
		RectangleFr& operator = (RectangleFr&& other) = default;

		// Destructor.
		// Destroys the RectangleFr and its data.
		~RectangleFr() = default;

		// Returns the x component of the vertex of the RectangleFr.
		value_type& x() const
		{
			return vertex.x;
		}

		// Returns the y component of the vertex of the RectangleFr.
		value_type& y() const
		{
			return vertex.y;
		}

		// Sets the x component of the vertex of the RectangleFr to new_x.
		void setX(value_type new_x)
		{
			vertex.x = new_x;
		}

		// Sets the y component of the vertex of the RectangleFr to new_y.
		void setY(value_type new_y)
		{
			vertex.y = new_y;
		}

		// Sets the x component of the vertex of the RectangleFr to new_x.
		// Sets the y component of the vertex of the RectangleFr to new_y.
		// Sets the width of the RectangleFr to new_width.
		// Sets the height of the RectangleFr to new_height.
		void setAll(value_type new_x, value_type new_y, value_type new_width, value_type new_height)
		{
			vertex.setAll(new_x, new_y);
			width = new_width;
			height = new_height;
		}

		// Sets the vertex of the RectangleFr to the given Point2Fr.
		// Sets the width of the RectangleFr to new_width.
		// Sets the height of the RectangleFr to new_height.
		void setAll(const Point2Fr<value_type>& P, value_type new_width, value_type new_height)
		{
			vertex = P;
			width = new_width;
			height = new_height;
		}

		// Returns the perimeter of the RectangleFr.
		double perimeter() const
		{
			return 2.0 * ( width.evaluate() + height.evaluate() );
		}

		// Returns the area of the RectangleFr.
		double area() const
		{
			return width.evaluate() * height.evaluate();
		}

		// Returns a std::string representation of the RectangleFr.
		std::string toString() const
		{
			return vertex.toString() + ", " + width.toString() + ", " + height.toString();
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
	//  - A.vertex == B.vertex  AND
	//  - A.width == B.width    AND
	//  - A.height == B.height
	// Returns false otherwise.
	template <arithmetic T> bool operator == (const Rectangle<T>& A, const Rectangle<T>& B)
	{
		if (A.vertex != B.vertex)
			return false;

		if (A.width != B.width)
			return false;

		if (A.height != B.height)
			return false;

		return true;
	}

	// Inequality comparison operator.
	// Returns true if:
	//  - A.vertex != B.vertex  OR
	//  - A.width != B.width    OR
	//  - A.height != B.height
	// Returns false otherwise.
	template <arithmetic T> bool operator != (const Rectangle<T>& A, const Rectangle<T>& B)
	{
		if (A.vertex != B.vertex)
			return true;

		if (A.width != B.width)
			return true;

		if (A.height != B.height)
			return true;

		return false;
	}

	// Equality comparison operator.
	// Returns true if:
	//  - A.vertex == B.vertex  AND
	//  - A.width == B.width    AND
	//  - A.height == B.height
	// Returns false otherwise.
	template <fraction_t T> bool operator == (const RectangleFr<T>& A, const RectangleFr<T>& B)
	{
		if (A.vertex != B.vertex)
			return false;

		if (A.width != B.width)
			return false;

		if (A.height != B.height)
			return false;

		return true;
	}

	// Inequality comparison operator.
	// Returns true if:
	//  - A.vertex != B.vertex  OR
	//  - A.width != B.width    OR
	//  - A.height != B.height
	// Returns false otherwise.
	template <fraction_t T> bool operator != (const RectangleFr<T>& A, const RectangleFr<T>& B)
	{
		if (A.vertex != B.vertex)
			return true;

		if (A.width != B.width)
			return true;

		if (A.height != B.height)
			return true;

		return false;
	}

	// std::ostream insertion operator.
	template <arithmetic T> std::ostream& operator << (std::ostream& os, const Rectangle<T>& r)
	{
		os << r.toString();
		return os;
	}

	// std::ostream insertion operator.
	template <fraction_t T> std::ostream& operator << (std::ostream& os, const RectangleFr<T>& r)
	{
		os << r.toString();
		return os;
	}

	///////////////////////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////////////////////
	//////                                    GLOBAL FUNCTIONS                                   //////
	///////////////////////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////////////////////

	template <arithmetic T> void print(const Rectangle<T>& r)
	{
		std::cout << r;
	}

	template <arithmetic T> void println(const Rectangle<T>& r)
	{
		std::cout << r << std::endl;
	}

	template <fraction_t T> void print(const RectangleFr<T>& r)
	{
		std::cout << r;
	}

	template <fraction_t T> void println(const RectangleFr<T>& r)
	{
		std::cout << r << std::endl;
	}
}

#endif // RECTANGLE_H_INCLUDED