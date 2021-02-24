// Jlib
// Fraction.h
// Justyn P.Durnford
// Created on 2020-10-12
// Last updated on 2021-02-24
// Header file for the Fraction template class.

#ifndef FRACTION_H_INCLUDED
#define FRACTION_H_INCLUDED

#ifndef _USE_MATH_DEFINES
#define _USE_MATH_DEFINES

#endif // _USE_MATH_DEFINES

#include <cmath>
#include <compare>
#include <concepts>
#include <cstddef>
#include <cstdint>
#include <iostream>
#include <string>

namespace Jlib
{
	// This class provides an "exact" representation of the quotient of two 
	// integers by storing them and allowing fraction arithmetic with them. 
	// Use the member function evaluate() to obtain the result of the fraction.
	template <std::integral T> class Fraction
	{
		T numer_ = 0;
		T denom_ = 0;

		public:

		// Default constructor.
		Fraction() = default;

		// Copy constructor.
		// Copies the values from the passed Fraction into the new Fraction.
		explicit Fraction(const Fraction& other) = default;

		// Move constructor.
		// Moves the passed Fraction into the new Fraction.
		explicit Fraction(Fraction&& other) = default;

		// 1-int constructor.
		// Sets the numerator of the Fraction to numer.
		// Sets the denominator of the Fraction to 1.
		Fraction(T numer)
		{
			numer_ = numer;
			denom_ = 1;
		}

		// 2-int constructor.
		// Sets the numerator of the Fraction to numer.
		// Sets the denominator of the Fraction to denom.
		Fraction(T numer, T denom)
		{
			numer_ = numer;
			denom_ = denom;
		}

		// Copy assignment operator.
		// Copies the values from the passed Fraction into the new Fraction.
		Fraction& operator = (const Fraction& other) = default;

		// Move assignment operator.
		// Moves the passed fraction into the new Fraction.
		Fraction& operator = (Fraction&& other) = default;

		// 1-int assignment operator.
		// Sets the numerator of the Fraction to numer.
		// Sets the denominator of the Fraction to 1.
		Fraction& operator = (T numer)
		{
			numer_ = numer;
			denom_ = 1;
		}

		// Destructor.
		// Destroys the Fraction and its data.
		~Fraction() = default;

		// Returns the numerator of the Fraction.
		T numer() const
		{
			return numer_;
		}

		// Returns the denominator of the Fraction.
		T denom() const
		{
			return denom_;
		}

		// Sets the numerator of the Fraction to numer.
		void setNumer(T numer)
		{
			numer_ = numer;
		}

		// Sets the denominator of the Fraction to denom.
		void setDenom(T denom)
		{
			denom_ = denom;
		}

		// Sets the numerator of the Fraction to numer.
		// Sets the denominator of the Fraction to denom.
		void setAll(T numer, T denom)
		{
			numer_ = numer;
			denom_ = denom;
		}

		// Raises both the numerator and denominator of the Fraction to the nth power.
		template <std::unsigned_integral Ty> void pow(Ty n)
		{
			std::pow(numer_, n);
			std::pow(denom_, n);
		}

		// Returns the result of the Fraction as a double.
		// This function may throw if a division by 0 is attempted.
		double evaluate() const
		{
			return ( 1.0 * numer_ ) / ( 1.0 * denom_ );
		}

		// Returns true if the denominator of the Fraction is NOT 0.
		bool is_valid() const
		{
			return denom_ != 0;
		}

		// Returns true if the denominator of the Fraction is NOT 0.
		operator bool() const
		{
			return denom_ != 0;
		}

		// Returns a std::string representation of the Fraction.
		std::string toString() const
		{
			return std::to_string(numer_) + " / " + std::to_string(denom_);
		}

		// Preincrement operator.
		// Adds 1 onto the Fraction.
		Fraction& operator ++ ()
		{
			numer_ += denom_;
			return *this;
		}

		// Postincrement operator.
		// Adds 1 onto the Fraction.
		Fraction operator ++ (int)
		{
			Fraction fr(*this);
			++( *this );

			return fr;
		}

		// Predecrement operator.
		// Subtracts 1 from the Fraction.
		Fraction& operator -- ()
		{
			numer_ -= denom_;
			return *this;
		}

		// Postdecrement operator.
		// Subtracts 1 from the Fraction.
		Fraction operator -- (int)
		{
			Fraction fr(*this);
			--( *this );

			return fr;
		}

		// Addition assignment operator.
		// Adds the components of the given Fraction onto the
		// corresponding components of this Fraction.
		Fraction& operator += (const Fraction& other)
		{
			if (denom_ == other.denom_)
			{
				numer_ += other.numer_;
				return *this;
			}

			T tmp = denom_;

			numer_ *= other.denom_;
			denom_ *= other.denom_;

			numer_ += other.numer_ * denom_;
			return *this;
		}

		// Addition assignment operator.
		// Adds the given value onto this Fraction.
		template <std::integral Ty> Fraction& operator += (Ty value)
		{
			numer_ += value * denom_;
			return *this;
		}

		// Subtraction assignment operator.
		// Subtracts the components of the given Fraction from the
		// corresponding components of this Fraction.
		Fraction& operator -= (const Fraction& other)
		{
			if (denom_ == other.denom_)
			{
				numer_ -= other.numer_();
				return *this;
			}

			T tmp = denom_;

			numer_ *= other.denom_;
			denom_ *= other.denom_;

			numer_ -= other.numer_ * denom_;
			return *this;
		}

		// Subtraction assignment operator.
		// Subtracts the given value from this Fraction.
		template <std::integral Ty> Fraction& operator -= (Ty value)
		{
			numer_ -= value * denom_;
			return *this;
		}

		// Multiplication assignment operator.
		// Multiplies the components of this Fraction by the
		// corresponding components of the given Fraction.
		Fraction& operator *= (const Fraction& other)
		{
			numer_ *= other.numer_;
			denom_ *= other.denom_;

			return *this;
		}

		// Multiplication assignment operator.
		// Multiplies the numerator of this Fraction by the given value.
		template <std::integral Ty> Fraction& operator *= (Ty value)
		{
			numer_ *= value;
			return *this;
		}

		// Division assignment operator.
		// Divides the components of this Fraction by the
		// corresponding components of the given Fraction.
		Fraction& operator /= (const Fraction& other)
		{
			numer_ *= other.denom_;
			denom_ *= other.numer_;

			return *this;
		}

		// Division assignment operator.
		// Divides the numerator of this Fraction by the given value.
		template <std::integral Ty> Fraction& operator /= (Ty value)
		{
			denom_ *= value;
			return *this;
		}
	};

	///////////////////////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////////////////////
	//////                                    GLOBAL OPERATORS                                   //////
	///////////////////////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////////////////////////////// 

	// Addition operator.
	template <std::integral T> Fraction<T> operator + (const Fraction<T>& A, const Fraction<T>& B)
	{
		Fraction<T> new_fr(A);
		new_fr += B;
		return new_fr;
	}

	// Addition operator.
	template <std::integral T> Fraction<T> operator + (const Fraction<T>& fr, T value)
	{
		Fraction new_fr(fr);
		new_fr += value;
		return new_fr;
	}

	// Subtraction operator.
	template <std::integral T> Fraction<T> operator - (const Fraction<T>& A, const Fraction<T>& B)
	{
		Fraction<T> new_fr(A);
		new_fr -= B;
		return new_fr;
	}

	// Subtraction operator.
	template <std::integral T> Fraction<T> operator - (const Fraction<T>& fr, T value)
	{
		Fraction new_fr(fr);
		new_fr -= value;
		return new_fr;
	}

	// Multiplication operator.
	template <std::integral T> Fraction<T> operator * (const Fraction<T>& A, const Fraction<T>& B)
	{
		Fraction<T> new_fr(A);
		new_fr *= B;
		return new_fr;
	}

	// Multiplication operator.
	template <std::integral T> Fraction<T> operator * (const Fraction<T>& fr, T value)
	{
		Fraction new_fr(fr);
		new_fr *= value;
		return new_fr;
	}

	// Multiplication operator.
	template <std::integral T> double operator * (const Fraction<T>& fr, double d)
	{
		return d * fr.evaluate();
	}

	// Division operator.
	template <std::integral T> Fraction<T> operator / (const Fraction<T>& A, const Fraction<T>& B)
	{
		Fraction<T> new_fr(A);
		new_fr /= B;
		return new_fr;
	}

	// Division operator.
	template <std::integral T> Fraction<T> operator / (const Fraction<T>& fr, T value)
	{
		Fraction new_fr(fr);
		new_fr /= value;
		return new_fr;
	}

	// Division operator.
	template <std::integral T> double operator / (const Fraction<T>& fr, double d)
	{
		return d / fr.evaluate();
	}

	// Equality comparison operator.
	// Returns true if A.evaluate() == B.evaluate().
	template <std::integral T> bool operator == (const Fraction<T>& A, const Fraction<T>& B)
	{
		return A.evaluate() == B.evaluate();
	}

	// Equality comparison operator.
	// Returns true if fr.evaluate() == f.
	template <std::integral T> bool operator == (const Fraction<T>& fr, double d)
	{
		return fr.evaluate() == d;
	}

	// Inequality comparison operator.
	// Returns true if A.evaluate() != B.evaluate().
	template <std::integral T> bool operator != (const Fraction<T>& A, const Fraction<T>& B)
	{
		return A.evaluate() != B.evaluate();
	}

	// Inequality comparison operator.
	// Returns true if fr.evaluate() != f.
	template <std::integral T> bool operator != (const Fraction<T>& fr, double d)
	{
		return fr.evaluate() != d;
	}

	// Greater than comparison operator.
	// Returns true if A.evaluate() > B.evaluate().
	template <std::integral T> bool operator > (const Fraction<T>& A, const Fraction<T>& B)
	{
		return A.evaluate() > B.evaluate();
	}

	// Greater than comparison operator.
	// Returns true if fr.evaluate() > f.
	template <std::integral T> bool operator > (const Fraction<T>& fr, double d)
	{
		return fr.evaluate() > d;
	}

	// Greater than or equal to comparison operators.
	// Returns true if A.evaluate() >= B.evaluate().
	template <std::integral T> bool operator >= (const Fraction<T>& A, const Fraction<T>& B)
	{
		return A.evaluate() >= B.evaluate();
	}

	// Greater than or equal to comparison operators.
	// Returns true if fr.evaluate() >= f.
	template <std::integral T> bool operator >= (const Fraction<T>& fr, double d)
	{
		return fr.evaluate() >= d;
	}

	// Less than comparison operator.
	// Returns true if A.evaluate() < B.evaluate().
	template <std::integral T> bool operator < (const Fraction<T>& A, const Fraction<T>& B)
	{
		return A.evaluate() < B.evaluate();
	}

	// Less than comparison operator.
	// Returns true if fr.evaluate() < f.
	template <std::integral T> bool operator < (const Fraction<T>& fr, double d)
	{
		return fr.evaluate() < d;
	}

	// Less than or equal to comparison operator.
	// Returns true if A.evaluate() <= B.evaluate().
	template <std::integral T> bool operator <= (const Fraction<T>& A, const Fraction<T>& B)
	{
		return A.evaluate() <= B.evaluate();
	}

	// Less than or equal to comparison operator.
	// Returns true if fr.evaluate() <= f.
	template <std::integral T> bool operator <= (const Fraction<T>& fr, double d)
	{
		return fr.evaluate() <= d;
	}

	// Three-way comparison operator.
	template <std::integral T> std::strong_ordering operator <=> (const Fraction<T>& A, const Fraction<T>& B)
	{
		if (A.evaluate() < B.evaluate())
			return std::strong_ordering::less;

		if (A.evaluate() > B.evaluate())
			return std::strong_ordering::greater;

		return std::strong_ordering::equal;
	}

	// Three-way comparison operator.
	template <std::integral T> std::strong_ordering operator <=> (const Fraction<T>& fr, double d)
	{
		if (fr.evaluate() < d)
			return std::strong_ordering::less;

		if (fr.evaluate() > d)
			return std::strong_ordering::greater;

		return std::strong_ordering::equal;
	}

	// std::ostream insertion operator.
	template <std::integral T> std::ostream& operator << (std::ostream& os, const Fraction<T>& fr)
	{
		os << fr.toString();
		return os;
	}

	///////////////////////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////////////////////
	//////                                    GLOBAL FUNCTIONS                                   //////
	///////////////////////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////////////////////

	// Prints the Fraction to the terminal.
	template <std::integral T> void print(const Fraction<T>& fr)
	{
		std::cout << fr;
	}

	// Prints the Fraction to the terminal and a newline.
	template <std::integral T> void println(const Fraction<T>& fr)
	{
		std::cout << fr << std::endl;
	}

	template <typename T> concept fraction_t =
		std::is_same_v<T, Jlib::Fraction<std::int8_t>>         ||
		std::is_same_v<T, Jlib::Fraction<std::int16_t>>        ||
		std::is_same_v<T, Jlib::Fraction<std::int32_t>>        ||
		std::is_same_v<T, Jlib::Fraction<std::int64_t>>        ||
		std::is_same_v<T, Jlib::Fraction<std::int_fast8_t>>    ||
		std::is_same_v<T, Jlib::Fraction<std::int_fast16_t>>   ||
		std::is_same_v<T, Jlib::Fraction<std::int_fast32_t>>   ||
		std::is_same_v<T, Jlib::Fraction<std::int_fast64_t>>   ||
		std::is_same_v<T, Jlib::Fraction<std::int_least8_t>>   ||
		std::is_same_v<T, Jlib::Fraction<std::int_least16_t>>  ||
		std::is_same_v<T, Jlib::Fraction<std::int_least32_t>>  ||
		std::is_same_v<T, Jlib::Fraction<std::int_least64_t>>  ||
		std::is_same_v<T, Jlib::Fraction<std::intmax_t>>       ||
		std::is_same_v<T, Jlib::Fraction<std::uint8_t>>        ||
		std::is_same_v<T, Jlib::Fraction<std::uint16_t>>       ||
		std::is_same_v<T, Jlib::Fraction<std::uint32_t>>       ||
		std::is_same_v<T, Jlib::Fraction<std::uint64_t>>       ||
		std::is_same_v<T, Jlib::Fraction<std::uint_fast8_t>>   ||
		std::is_same_v<T, Jlib::Fraction<std::uint_fast16_t>>  ||
		std::is_same_v<T, Jlib::Fraction<std::uint_fast32_t>>  ||
		std::is_same_v<T, Jlib::Fraction<std::uint_fast64_t>>  ||
		std::is_same_v<T, Jlib::Fraction<std::uint_least8_t>>  ||
		std::is_same_v<T, Jlib::Fraction<std::uint_least16_t>> ||
		std::is_same_v<T, Jlib::Fraction<std::uint_least32_t>> ||
		std::is_same_v<T, Jlib::Fraction<std::uint_least64_t>> ||
		std::is_same_v<T, Jlib::Fraction<std::uintmax_t>>      ||
		std::is_same_v<T, Jlib::Fraction<std::size_t>>;
}

#endif // FRACTION_H_INCLUDED