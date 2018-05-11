#pragma once
#include "Typedef.h"
#include "IIterable.h"
#include <initializer_list>

namespace Stella::Collections
{
	template <class T, Size N>
	class Array : public IIterable<T>
	{
		/*-----------------------------------------------------------------------
		                                 Fields
		-----------------------------------------------------------------------*/
	private:

		T elements[N];

		/*-----------------------------------------------------------------------
		                       Constructors & Destructors
		-----------------------------------------------------------------------*/	
	public:				

		inline Array() 
		{
		} 

		inline Array(const T* pointer)
			: Array(pointer, N)
		{			
		}

		FORCE_INLINE Array(const T* pointer, Size count)
		{
			if (count > N)
				return; // @todo throw ArgumentOutOfRangeException

			for (int i = 0; i < N; i++)
			{
				if (i < count)
				{
					elements[i] = pointer[i];
					continue;
				}
				elements[i] = NULL;
			}
		}

		inline Array(const Array<const T, N>& constArray)
			: Array(constArray.elements, N)
		{
		}

		inline Array(std::initializer_list<T> initializerList)
			: Array(initializerList.begin(), initializerList.size())
		{
		}
				
		/*-----------------------------------------------------------------------
		                                 Methods
		-----------------------------------------------------------------------*/
	public:

		bool IsEmpty() const
		{
			return false;
		}

		Size Count() const
		{
			return N;
		}

		T* GetData()
		{
			return elements;
		}

		const T* GetData() const
		{
			return elements;
		}
		
		T* Begin()
		{
			return elements;
		}

		const T* Begin() const
		{
			return elements;
		}

		T* End()
		{
			return elements + N;
		}

		const T* End() const
		{
			return elements + N;
		}

		T& Front()
		{
			return elements[0];
		}

		const T& Front() const
		{
			return elements[0];
		}

		T& Back()
		{
			return elements[N - 1];
		}

		const T& Back() const
		{
			return elements[N - 1];
		}

		void Fill(const T& value)
		{
			for (int i = 0; i < N; i++)
			{
				elements[i] = value;
			}
		}

		void Swap(const Array<T, N>& other)
		{
			for (int i = 0; i < N; i++)
			{
				// ...	
			}
		}

		/*-----------------------------------------------------------------------
		                                Operators
		-----------------------------------------------------------------------*/
	public:

		T& operator[](Size index) 
		{
			return elements[index];
		}

		const T& operator[](Size index) const
		{
			return elements[index];
		}

		bool operator==(Array<T, N>& other)
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

		bool operator!=(Array<T, N>& other)
		{
			return !(operator==(other));
		}

		bool operator<(Array<T, N>& other)
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

		bool operator<=(Array<T, N>& other)
		{
			return !(other < *this);
		}

		bool operator>(Array<T, N>& other)
		{
			return other < *this;
		}

		bool operator>=(Array<T, N>& other)
		{
			return !(*this < other);
		}

		/*-----------------------------------------------------------------------
		                                IIterable
		-----------------------------------------------------------------------*/
	public:

		SharedPointer<IIterator<T>> GetIterator() const
		{
			return new ArrayIterator(*this);
		}

		/*-----------------------------------------------------------------------
		                              ArrayIterator
		-----------------------------------------------------------------------*/
	private:

		class ArrayIterator : public IIterator<T>
		{
		private:
			
			Int32 index;
			Array<T, N> array;

		public:

			ArrayIterator(const Array<T, N>& array)
				: array(array), index(0)
			{
			}

			bool MoveNext()
			{
				if (index < N)
				{
					index++;
					return true;
				}
				index = N + 1;
				return false;
			}

			bool HasCurrent() const
			{
				if (index == 0 || index == N + 1)
					return false;

				return true;
			}

			T& GetCurrent() 
			{
				if (!HasCurrent())
				{
					// @todo throw InvalidOperationException
				}
				return array[index - 1];
			}

			const T& GetCurrent() const
			{
				if (index == 0 || index == N + 1)
				{
					// @todo throw InvalidOperationException
				}
				return array[index - 1];
			}					

			void Reset()
			{
				index = 0;
			}
		};
	};

	template<class T>
	class Array<T, 0>
	{
	public:

		bool IsEmpty() const
		{
			return true;
		}

		Size GetSize() const
		{
			return 0;
		}
	};

	template <class T, Size N>
	class Array <const T, N>
	{
	public:

		T elements[N];
	};
}