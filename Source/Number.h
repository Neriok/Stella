#pragma once
#include "Typedef.h"
#include "String.h"

namespace Stella
{
	class Number
	{
		/*-----------------------------------------------------------------------
		                                 Fields
		-----------------------------------------------------------------------*/
	public:

		static const Int8  Int8MaxValue;
		static const Int8  Int8MinValue;
		
		static const Int16 Int16MaxValue;
		static const Int16 Int16MinValue;
		
		static const Int32 Int32MaxValue;
		static const Int32 Int32MinValue;
		
		static const Int64 Int64MaxValue;
		static const Int64 Int64MinValue;

		/*-----------------------------------------------------------------------
		                                 Functions
		-----------------------------------------------------------------------*/
	public:

		static Int32 Compare(Int8 left, Int8 right);
		static Int32 Compare(Int16 left, Int16 right);
		static Int32 Compare(Int32 left, Int32 right);
		static Int32 Compare(Int64 left, Int32 right);

		static Int8 ParseInt8(String text);
		static Int16 ParseInt16(String text);
		static Int32 ParseInt32(String text);
		static Int64 ParseInt64(String text);

		String ToString(Int8 value);
		String ToString(Int16 value);
		String ToString(Int32 value);
		String ToString(Int64 value);
	};
}