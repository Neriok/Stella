#pragma once
#include "Platform.h"

namespace Stella
{
	// ---------------------------------------------------------------------
	// -- Base types 
	// ---------------------------------------------------------------------

	// Boolean type
	typedef bool                Boolean;  // 8-bit bool (Memory cannot address a single bit)

    // Unsigned integer types 
	typedef unsigned char 	    UInt8;	  // 8-bit  unsigned
	typedef unsigned short int  UInt16;	  // 16-bit unsigned
	typedef unsigned int	    UInt32;	  // 32-bit unsigned
	typedef unsigned long long  UInt64;	  // 64-bit unsigned

    // Signed integer types
	typedef	signed char		    Int8;	  // 8-bit  signed
	typedef signed short int    Int16;	  // 16-bit signed
	typedef signed int	 	    Int32;	  // 32-bit signed
	typedef signed long long    Int64;	  // 64-bit signed
	
	// Floating-point types
	typedef float               Float;    // 32-bit floating-point
	typedef float               Single;   // 32-bit floating-point
	typedef double              Double;   // 64-bit floating-point

	// Character types
	typedef char                Char;     // 8-bit character type
	typedef wchar_t             WideChar; // 16-bit character type
	typedef UInt16				Char16;   // 16-bit character type
	typedef UInt32				Char32;   // 32-bit character type

	// Size types. Changes according the architecture
	#if STELLA_ARCHITECTURE_TYPE == ARCHITECTURE_x86_32

	typedef UInt32 Size;

	#else

	typedef UInt64 Size;

	#endif

	//---------------------------------------------------------------------
	// -- Generic definitions
	//---------------------------------------------------------------------

	#define NULL            0
	#define NULLPTR         nullptr
	#define STDCALL		    __stdcall						
	#define INLINE          inline
	#define FORCE_INLINE    __forceinline
    #define CONST_EXPRESION constexpr
    #define CONST           const

}