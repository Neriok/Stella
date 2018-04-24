#pragma once

namespace Stella
{
	class Int32
	{
		// ----------------------------------------------------------------------
		// -- Constructors & Destructors
		// ----------------------------------------------------------------------

	private: 

		explicit Int32() {} 
		~Int32() {}	

		// ----------------------------------------------------------------------
		// -- Static Fields
		// ----------------------------------------------------------------------

	public:

		inline static const int MaxValue = (int)0x7fffffff;
		inline static const int MinValue = (int)0x80000000;

		// ----------------------------------------------------------------------
		// -- Static Methods
		// ----------------------------------------------------------------------

	public:

		int Compare(int a, int b)
		{
			if (a < b) return -1;
			if (b > a) return 1;
			return 0;
		}
	};
}
