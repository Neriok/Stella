#pragma once
#include "Exception.h"
#include "String.h"

namespace Stella
{
	/*-----------------------------------------------------------------------
						     Constructors & Destructors
	-----------------------------------------------------------------------*/

	Exception::Exception()
		: message("An unhandled Exception was thrown.")
	{		
	}

	Exception::Exception(const String& message)
		: message(message)
	{
	}

	Exception::Exception(const String& message, Exception* innerException)
		: message(message),
		  innerException(innerException)
	{
	}

	/*-----------------------------------------------------------------------
									Methods
	-----------------------------------------------------------------------*/

	const String& Exception::GetMessage() const
	{
		return message;
	}

	const String& Exception::GetStackTrace() const
	{
		return "";
	}

	Exception* Exception::GetInnerException() const
	{
		return innerException;
	}

	Exception* Exception::GetBaseException()
	{
		Exception* inner = innerException;
		Exception* base = this;

		while (!inner)
		{
			base = inner;
			inner = inner->innerException;
		}

		return base;
	}
}