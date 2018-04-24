#include "String.h"
#include <cstdlib>

namespace Stella
{
	// ----------------------------------------------------------------------
	// -- Constants
	// ----------------------------------------------------------------------

	const String String::Empty = "";

	// ----------------------------------------------------------------------
	// -- Constructors & destructors
	// ----------------------------------------------------------------------
	
	String::String(const Char* string)
	{
		CopyFrom(string);
	}

	String::String(const WideChar* string)
	{
		CopyFrom(string);
	}

	// ----------------------------------------------------------------------
	// -- Methods
	// ----------------------------------------------------------------------

	Boolean String::IsEmpty() const
	{
		return GetLength() == 0;
	}

	Size String::GetLength() const
	{
		Size size = GetSize();
		return size ? size - 1 : 0;
	}

	const WideChar* String::ToWideChar() const
	{
		return &operator[](0);
	}

	const Char* String::ToChar() const
	{		
		if (IsEmpty())
			return "";

		Char* result = new Char[GetSize()];

		for (int i = 0; i < GetSize(); i++)
		{
			result[i] = operator[](i);
		}
		
		return result;
	}

	void String::CopyFrom(const Char* string_from)
	{
		if (!string_from)
		{
			Resize(0);
			return;
		}

		Int32 length = 0;
		const Char* pointer = string_from;

		while (*(pointer++) != NULL)
		{
			length++;
		}

		if (length == 0)
		{
			Resize(0);
			return;
		}

		Resize(length + 1);

		for (Int32 i = 0; i < length; i++)
		{
			Begin()[i] = string_from[i];
		}

		Begin()[length] = 0;
	}

	void String::CopyFrom(const WideChar* string_from)
	{
		if (!string_from)
		{
			Resize(0);
			return;
		}

		Int32 length = 0;
		const WideChar* pointer = string_from;

		while (*(pointer++) != NULL)
		{
			length++;
		}

		if (length == 0)
		{
			Resize(0);
			return;
		}

		Resize(length + 1);

		for (Int32 i = 0; i < length; i++)
		{
			Begin()[i] = string_from[i];

		}

		Begin()[length] = 0;
	}

	// ----------------------------------------------------------------------
	// -- Operators
	// ----------------------------------------------------------------------

	void String::operator=(const Char* string)
	{
		CopyFrom(string);
	}

	void String::operator=(const WideChar* string)
	{
		CopyFrom(string);
	}

	// ----------

	String& String::operator+(const String& string)
	{
		return *this += string;
	}

	// ----------

	String& String::operator+=(const String& other)
	{
		if (IsEmpty())
		{
			*this = other;
			return *this;
		}

		if (other.IsEmpty())
		{
			return *this;
		}

		Size old_length = GetLength();
		Resize(old_length + other.GetSize());

		for (Int32 i = 0; i < (Int32)other.GetLength(); i++)
		{
			Begin()[old_length + i] = other[i];
		}

		Begin()[GetLength()] = 0;
		return *this;
	}

	String& String::operator+=(const Char* other)
	{
		return *this += String(other);
	}

	String& String::operator+=(const WideChar* other)
	{
		return *this += String(other);
	}

	String::operator const Char*()
	{
		return ToChar();
	}

	String::operator const WideChar*()
	{
		return ToWideChar();
	}
}
