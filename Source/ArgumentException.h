#pragma once
#include "Exception.h"

namespace Stella
{
	class ArgumentException : public Exception
	{
		// ----------------------------------------------------------------------
		// -- Fields
		// ----------------------------------------------------------------------
	
	private:

		String paramName;

		// ----------------------------------------------------------------------
		// -- Constructors & Destructors
		// ----------------------------------------------------------------------

	public:

		ArgumentException();
		ArgumentException(const String& message);
		ArgumentException(const String& message, const String& paramName);
		ArgumentException(const String& message, Exception* innerException);
		ArgumentException(const String& message, const String& paramName, Exception* innerException);

		// ----------------------------------------------------------------------
		// -- Methods
		// ----------------------------------------------------------------------

	public:

		virtual const String& GetParamName() const;
	};
}