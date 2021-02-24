// Jlib
// Pointer.h
// Justyn Durnford
// Created on 2021-01-31
// Last updated on 2021-02-22
// Header file for the Pointer template class.

#ifndef POINTER_H_INCLUDED
#define POINTER_H_INCLUDED

#include <cstddef>

namespace Jlib
{
	template <typename T> class Pointer
	{
		T* ptr_ = nullptr;

		public:

		using value_type = T;

		// Default constructor.
		Pointer() = default;

		// Copy constructor.
		Pointer(const Pointer& other)
		{
			ptr_ = other.ptr_;
		}

		// Move constructor.
		// This function may not throw.
		Pointer(Pointer&& other) noexcept
		{
			ptr_ = other.ptr_;
			other.ptr_ = nullptr;
		}

		// Primary constructor.
		Pointer(T& object)
		{
			ptr_ = &object;
		}

		// Copy assignment operator.
		Pointer& operator = (const Pointer& other)
		{
			ptr_ = other.ptr_;
			return *this;
		}

		// Move assignment operator.
		// This function may not throw.
		Pointer& operator = (Pointer&& other) noexcept
		{
			ptr_ = other.ptr_;
			other.ptr_ = nullptr;
			return *this;
		}

		// Primary assignment operator.
		Pointer& operator = (T& object)
		{
			ptr_ = &object;
			return *this;
		}

		// nullptr assignment operator.
		Pointer& operator = (std::nullptr_t)
		{
			ptr_ = nullptr;
			return *this;
		}

		// Destructor.
		~Pointer() = default;

		// Returns the stored raw pointer.
		value_type* get()
		{
			return ptr_;
		}

		// Returns a const version of the stored raw pointer.
		const value_type* get() const
		{
			return (const value_type*)ptr_;
		}

		// Sets the stored raw pointer to nullptr.
		// This function may not throw.
		void reset() noexcept
		{
			ptr_ = nullptr;
		}

		value_type& operator * () const
		{
			return *ptr_;
		}

		value_type* operator -> ()
		{
			return ptr_;
		}

		const value_type* operator -> () const
		{
			return (const value_type*)ptr_;
		}

		value_type& operator [] (std::ptrdiff_t index)
		{
			return ptr_ + index;
		}

		const value_type& operator [] (std::ptrdiff_t index) const
		{
			return (const value_type*)(ptr_ + index);
		}

		// Evaluates to true if the stored raw pointer is not a nullptr.
		// Evaluates to false if it is.
		// This function may not throw.
		explicit operator bool() const noexcept
		{
			return ptr_ != nullptr;
		}
	};

	// Moves the Pointer A into the Pointer B.
	// Pointer A is then set to nullptr.
	// This function may not throw.
	template <typename T> void move(Pointer<T>& A, Pointer<T>& B) noexcept
	{
		B = A;
		A.reset();
	}

	// Swaps the two given Pointers.
	// This function may not throw.
	template <typename T> void swap(Pointer<T>& A, Pointer<T>& B) noexcept
	{
		Pointer<T> C(A);
		A = B;
		B = C;
	}

	// Equality comparison operator.
	// Returns true if the given Pointers point to the same object.
	// Returns false otherwise.
	template <typename T> bool operator == (Pointer<T> A, Pointer<T> B)
	{
		return A.get() == B.get();
	}

	// Equality comparison operator.
	// Returns true if the given Pointer is a nullptr.
	// Returns false otherwise.
	template <typename T> bool operator == (Pointer<T> ptr, std::nullptr_t)
	{
		return ptr.get() == nullptr;
	}

	// Inequality comparison operator.
	// Returns false if the given Pointers point to the same object.
	// Returns true otherwise.
	template <typename T> bool operator != (Pointer<T> A, Pointer<T> B)
	{
		return A.get() != B.get();
	}

	// Inequality comparison operator.
	// Returns false if the given Pointer is a nullptr.
	// Returns true otherwise.
	template <typename T> bool operator != (Pointer<T> ptr, std::nullptr_t)
	{
		return ptr.get() != nullptr;
	}
}

#endif // POINTER_H_INCLUDED