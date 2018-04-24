#pragma once
#include "ArgumentException.h"

namespace Stella
{
	// ----------------------------------------------------------------------
	// -- Constructors & Destructors
	// ----------------------------------------------------------------------

	ArgumentException::ArgumentException()
		: ArgumentException("An unhandled ArgumentException was thrown.", "", nullptr)
	{		
	}

	ArgumentException::ArgumentException(const String& message)
		: ArgumentException(message, "", nullptr)
	{
	}

	ArgumentException::ArgumentException(const String& message, const String& paramName)
		: ArgumentException(message, paramName, nullptr)
	{
	}

	ArgumentException::ArgumentException(const String& message, Exception* innerException)
		: ArgumentException(message, "", innerException)
	{
	}

	ArgumentException::ArgumentException(const String& message, const String& paramName, Exception* innerException)
		: Exception(message, innerException),
		  paramName(paramName)
	{
	}

	// ----------------------------------------------------------------------
	// -- Methods
	// ----------------------------------------------------------------------

	const String& ArgumentException::GetParamName() const
	{
		return paramName;
	}

}