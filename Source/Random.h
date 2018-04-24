#pragma once

#include "Typedef.h"
#include "Collections/Array.h"
using namespace Stella::Collections;

namespace Stella
{
	class Random
	{
		// ----------------------------------------------------------------------
		// -- Fields
		// ----------------------------------------------------------------------

	private: 

		Int32 seed;
		Array<Int32, 55> seedArray;

		// ----------------------------------------------------------------------
		// -- Constructors & Destructors
		// ----------------------------------------------------------------------

	public:

		Random();
		Random(Int32 seed);

		// ----------------------------------------------------------------------
		// -- Methods
		// ----------------------------------------------------------------------

	public:

		Int32 GetSeed() const;
		Float Fraction() const;
		Int32 Range(Int32 max) const;
		Int32 Range(Int32 min, Int32 max) const;

	};
}