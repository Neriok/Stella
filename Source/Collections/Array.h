#pragma once
#include "Typedef.h"

namespace Stella::Collections
{
	template <class T, UInt32 Size>
	class Array
	{
		// ----------------------------------------------------------------------
		// -- Fields
		// ----------------------------------------------------------------------

	public:

		T elements[Size];

		// ----------------------------------------------------------------------
		// -- Methods
		// ----------------------------------------------------------------------

	public:

		Boolean IsEmpty() const
		{
			return false;
		}

		UInt32 GetSize() const
		{
			return Size;
		}
		
		T* Begin()
		{
			return this->elements;
		}

		const T* Begin() const
		{
			return this->elements;
		}

		T* End()
		{
			return this->elements + Size;
		}

		const T* End() const
		{
			return this->elements + Size;
		}

		T& Front()
		{
			return this->elements[0];
		}

		const T& Front() const
		{
			return this->elements[0];
		}

		T& Back()
		{
			return this->elements[Size - 1];
		}

		const T& Back() const
		{
			return this->elements[Size - 1];
		}

		void Fill(const T& value)
		{
			for (int i = 0; i < Size; i++)
			{
				elements[i] = value;
			}
		}

		void Swap(const Array<T, Size> other)
		{
			for (int i = 0; i < Size; i++)
			{
				// ...			

			}
		}

		// ----------------------------------------------------------------------
		// -- Operators
		// ----------------------------------------------------------------------

	public:

		T& operator[](UInt32 index) 
		{
			return elements[index];
		}

		const T& operator[](UInt32 index) const
		{
			return elements[index];
		}

		Boolean operator==(Array<T, Size>& other)
		{
			T* b1 = Begin();
			T* b2 = other.Begin();
			T* e1 = End();

			for (; b1 != e1; b1++, b2++)
			{
				if (*b1 != *b2)
				{
					return false;
				}
			}
			return true;
		}

		Boolean operator!=(Array<T, Size>& other)
		{
			return !(operator==(other));
		}

		Boolean operator<(Array<T, Size>& other)
		{
			T* b1 = Begin();
			T* b2 = other.Begin();
			T* e1 = End();

			for (; b1 != e1; b1++, b2++)
			{
				if (*b1 < *b2) return true;
				if (*b2 < *b1) return false;
			}
			return false;
		}

		Boolean operator<=(Array<T, Size>& other)
		{
			return !(other < *this);
		}

		Boolean operator>(Array<T, Size>& other)
		{
			return other < *this;
		}

		Boolean operator>=(Array<T, Size>& other)
		{
			return !(*this < other);
		}
	};

	template<class T>
	class Array<T, 0>
	{
	public:

		Boolean IsEmpty() const
		{
			return true;
		}

		UInt32 GetSize() const
		{
			return 0;
		}

	};
}