// Jlib
// Matrix.h
// Justyn Durnford
// Created on 2020-10-12
// Last updated on 2021-02-09
// Header file for the Matrix template class.

#ifndef MATRIX_H_INCLUDED
#define MATRIX_H_INCLUDED

#include <concepts>
#include <cstddef>
#include <initializer_list>
#include <stdexcept>
#include <vector>

namespace Jlib
{

	// This class is able to function as a 
	//
	//
	template <std::semiregular T> class Matrix
	{
		public:

		using value_type = T;
		using size_type = std::size_t;

		private:

		value_type** matrix_ = nullptr;
		size_type row_ = 0;
		size_type col_ = 0;

		// This function will check the given position and will throw
		// if it is given an invalid position.
		void checkBounds(size_type row, size_type col)
		{
			if (row >= row_)
				throw std::out_of_range("Invalid row index");

			if (col >= col_)
				throw std::out_of_range("Invalid column index");
		}

		// This function will allocate memory sufficient to store the
		// amount of elements given by row * col.
		// This function will throw if it is unable to do this.
		void allocate(size_type row, size_type col)
		{
			try
			{
				row_ = row;
				col_ = col;
				matrix_ = new value_type * [row];

				for (size_type r = 0; r < row_; r++)
					matrix_[r] = new value_type[col_];
			}
			catch (...) { throw; }
		}

		// This function releases the memory held by the Jlib::Matrix.
		// This function may not throw.
		void deallocate() noexcept
		{
			for (size_type r = 0; r < row_; r++)
				delete[] matrix_[r];

			delete[] matrix_;
		}

		public:

		// Default constructor.
		// Creates an new empty Jlib::Matrix.
		Matrix() = default;

		// 2-parameter constructor.
		// Creates a new Jlib::Matrix with the dimensions row x col.
		// This function may throw if it is unable to allocate enough memory.
		Matrix(size_type row, size_type col)
		{
			allocate(row, col);
		}

		// 3-parameter constructor.
		// Creates a new Jlib::Matrix with the dimensions row x col
		// with each element being a copy of value.
		// This function may throw if it is unable to allocate enough memory.
		Matrix(size_type row, size_type col, const value_type& value)
		{
			allocate(row, col);

			for (size_type r = 0; r < row_; ++r)
			{
				for (size_type c = 0; c < col_; ++c)
					matrix_[r][c] = value;
			}
		}

		// Copy constructor.
		// Creates a copy of the passed Jlib::Matrix.
		// This function may throw if it is unable to allocate enough memory.
		explicit Matrix(const Matrix& other)
		{
			allocate(other.row_, other.col_);

			try
			{
				for (size_type r = 0; r < row_; ++r)
				{
					for (size_type c = 0; c < col_; ++c)
						matrix_[r][c] = other.matrix_[r][c];
				}
			}
			catch (...) { throw; }
		}

		// Move constructor.
		// Moves the passed Jlib::Matrix into the new Jlib::Matrix.
		// This function may not throw.
		explicit Matrix(Matrix&& other) noexcept
		{
			row_ = other.row_;
			col_ = other.col_;
			matrix_ = other.matrix_;

			other.row_ = 0;
			other.col_ = 0;
			other.matrix_ = nullptr;
		}

		// Copy assignment operator.
		// Creates a copy of the passed Jlib::Matrix.
		// This function may throw if it is unable to allocate enough memory.
		Matrix& operator = (const Matrix& other)
		{
			deallocate();
			allocate(other.row_, other.col_);

			try
			{
				for (size_type r = 0; r < row_; ++r)
				{
					for (size_type c = 0; c < col_; ++c)
						matrix_[r][c] = other.matrix_[r][c];
				}
			}
			catch (...) { throw; }

			return *this;
		}

		// Move assignment operator.
		// Moves the passed Jlib::Matrix into the new Jlib::Matrix.
		// This function may not throw.
		Matrix& operator = (Matrix&& other) noexcept
		{
			deallocate();

			row_ = other.row_;
			col_ = other.col_;
			matrix_ = other.matrix_;

			other.row_ = 0;
			other.col_ = 0;
			other.matrix_ = nullptr;

			return *this;
		}

		// std::initializer_list<std::initializer_list> assignment operator.
		// Copies the elements from the given std::initializer_list<std::initializer_list<value_type>>.
		// This function may throw if it is unable to do this.
		Matrix& operator = (const std::initializer_list<std::initializer_list<value_type>>& matrix)
		{
			deallocate();
			size_type col = 0;

			for (const std::initializer_list<value_type>& list : matrix)
			{
				if (list.size() > col)
					col = list.size();
			}

			allocate(matrix.size(), col);

			try
			{
				auto row_iter(matrix.begin());
				std::size_t r(0);
				std::size_t c(0);

				while (row_iter != matrix.end())
				{
					auto col_iter(row_iter->begin());

					while (col_iter != row_iter->end())
					{
						matrix_[r][c] = *col_iter;
						++c;
						++col_iter;
					}

					c = 0;
					++r;
					++row_iter;
				}
			}
			catch (...) { throw; }

			return *this;
		}

		// Destructor.
		// Destroys the Jlib::Matrix and its data.
		// This function may not throw.
		~Matrix() noexcept
		{
			deallocate();
		}

		// Returns the row count of the Jlib::Matrix.
		size_type rowSize() const
		{
			return row_;
		}

		// Returns the column count of the Jlib::Matrix.
		size_type colSize() const
		{
			return col_;
		}

		// Returns true if the Jlib::Matrix is empty.
		// Returns false otherwise.
		bool empty() const
		{
			return row_ == 0;
		}

		// Returns a reference to the element at the position [row][col].
		// This function may throw if it is given an invalid position.
		value_type& at(size_type row, size_type col)
		{
			checkBounds(row, col);
			return matrix_[row][col];
		}

		// Returns a const reference to the element at the position [row][col].
		// This function may throw if it is given an invalid position.
		const value_type& at(size_type row, size_type col) const
		{
			checkBounds(row, col);
			return matrix_[row][col];
		}

		// Returns a reference to the element at the position [row][col].
		value_type& operator () (size_type row, size_type col)
		{
			return matrix_[row][col];
		}

		// Returns a const reference to the element at the position [row][col].
		const value_type& operator () (size_type row, size_type col) const
		{
			return matrix_[row][col];
		}

		// Sets the element at the position [row][col] to value.
		// This function may throw if it is given an invalid position.
		void set(size_type row, size_type col, const value_type& value)
		{
			checkBounds(row, col);
			matrix_[row][col] = value;
		}
	};
}

#endif // MATRIX_H_INCLUDED