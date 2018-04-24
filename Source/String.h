#pragma once

#include "Typedef.h"
#include "Collections/Array.h"
#include "Collections/Vector.h"

using namespace Stella::Collections;

namespace Stella
{
	// @todo Crear una mejor clase String
	class String : public Vector<WideChar>
	{
		// ----------------------------------------------------------------------
		// -- Constants
		// ----------------------------------------------------------------------

	public:

		static const String Empty;

		// ----------------------------------------------------------------------
		// -- Constructors & Destructors
		// ----------------------------------------------------------------------

	public:

		String(const Char* string);
		String(const WideChar* string);

		// ----------------------------------------------------------------------
		// -- Methods
		// ----------------------------------------------------------------------

	public:

		Boolean IsEmpty() const;
		Boolean IsNumeric() const;
		Size GetLength() const;
		String ToLower();
		String ToUpper();
		const WideChar* ToWideChar() const;
		const Char* ToChar() const;
		Boolean ToBoolean() const;

	private:

		void CopyFrom(const Char* string_from);
		void CopyFrom(const WideChar* string_from);

		// ----------------------------------------------------------------------
		// -- Operators
		// ----------------------------------------------------------------------

	public:

		void operator=(const Char* string);
		void operator=(const WideChar* string);
		String& operator+(const String& string);
		String& operator+=(const String& string);
		String& operator+=(const Char* string);
		String& operator+=(const WideChar* string);		
		operator const Char*();		
		operator const WideChar*();

	};

}	