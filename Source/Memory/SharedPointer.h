#pragma once
#include "Typedef.h"
#include "TypeTraits.h"

namespace Stella::Memory
{
	template <typename T>
	class SharedPointer
	{
		/*-----------------------------------------------------------------------
		                                 Fields
		-----------------------------------------------------------------------*/
	private:

		T* object;

		/*-----------------------------------------------------------------------
		                       Constructors & Destructors
		-----------------------------------------------------------------------*/
	public:

		inline SharedPointer()
		{
		}

		inline SharedPointer(T* object)
				: object(object)
		{ 
		}

		inline SharedPointer(const SharedPointer& other)
			: object(other.object)
		{
		}

		inline SharedPointer(SharedPointer&& other)
			: object(other.object)
		{
			other.object = nullptr;
		}

		inline ~SharedPointer()
		{
			delete object;
		}

		/*-----------------------------------------------------------------------
		                                 Methods
		-----------------------------------------------------------------------*/
	public:

		inline T* Get() const
		{
			return object;
		}

		/*-----------------------------------------------------------------------
		                                Operators
		-----------------------------------------------------------------------*/
	public:

		inline T* operator->() const
		{
			return object;
		}

		inline typename AddReference<T>::Type operator*() const
		{
			return *object;
		}
	};
}