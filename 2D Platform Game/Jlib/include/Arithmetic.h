// Jlib
// Arithmetic.h
// Justyn Durnford
// Created on 2021-02-11
// Last updated on 2021-02-22
// Header file defining the arithmetic template.

#ifndef ARITHMETIC_H_INCLUDED
#define ARITHMETIC_H_INCLUDED

#include <concepts>

namespace Jlib
{             
	template <typename T> concept arithmetic = std::is_arithmetic_v<T>;
}

#endif // !ARITHMETIC_H_INCLUDED