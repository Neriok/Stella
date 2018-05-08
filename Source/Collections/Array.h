#pragma once
#include "Typedef.h"
#include "IEnumerable.h"
#include <initializer_list>

namespace Stella::Collections
{
	template <class T, Size N>
	class Array : public IEnumerable<T>
	{
		/*-----------------------------------------------------------------------
		                                 Fields
		-----------------------------------------------------------------------*/
	public:

		T elements[N];

		/*-----------------------------------------------------------------------
		                       Constructors & Destructors
		-----------------------------------------------------------------------*/	
	public:

		Array(std::initializer_list<T> initializerList)
		{
			if (initializerList.size() != N)
			{
				//@todo throw ArgumentOutOfRangeException
				return;
			}
			for (int i = 0; i < N; i++)
			{
				elements[i] = *(initializerList.begin() + i);
			}
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

		void Swap(const Array<T, N> other)
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
		                               IEnumerable
		-----------------------------------------------------------------------*/
	public:

		SharedPointer<IEnumerator<T>> GetEnumerator() const
		{
			return SharedPointer<IEnumerator<T>>((IEnumerator<T>*) new ArrayEnumerator(*this));
		}

		/*-----------------------------------------------------------------------
		                              ArrayEnumerator
		-----------------------------------------------------------------------*/
	private:

		class ArrayEnumerator : IEnumerator<T>
		{
		private:
			
			Int32 index;
			Array<T, N> array;

		public:

			ArrayEnumerator(const Array<T, N>& array)
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

			T& GetCurrent() 
			{
				if (index == 0 || index == N + 1)
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
}