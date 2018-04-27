#pragma once
#include "String.h"

namespace Stella
{
	class Exception
	{
		/*-----------------------------------------------------------------------
				                         Fields
		-----------------------------------------------------------------------*/	

	private:

		String message;
		Exception* innerException;

		/*-----------------------------------------------------------------------
							   Constructors & Destructors
		-----------------------------------------------------------------------*/

	public:

		Exception();
		Exception(const String& message);
		Exception(const String& message, Exception* innerException);

		/*-----------------------------------------------------------------------
									    Methods
		-----------------------------------------------------------------------*/

	public:

		virtual const String& GetMessage() const;
		virtual const String& GetStackTrace() const;
		Exception* GetInnerException() const;
		Exception* GetBaseException();
	};
}