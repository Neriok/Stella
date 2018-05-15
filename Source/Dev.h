#pragma once

#include "Typedef.h"
#include "TypeTraits.h"
#include "Collections/Array.h"
#include "Collections/ICollection.h"
#include "Memory/Allocator.h"
#include "Memory/SharedPointer.h"
#include <initializer_list>
#include <exception.h>

using namespace Stella;
using namespace Stella::Collections;
using namespace Stella::Memory;

namespace Dev
{
	template <typename T, typename TAllocator>
	class Vector : public ICollection<T>
	{
		/*-----------------------------------------------------------------------
		                                 Fields
		-----------------------------------------------------------------------*/
	private:
		
		TAllocator allocator; 
		Int32 count;   
		Int32 capacity;

		/*-----------------------------------------------------------------------
		                       Constructors & Destructors
		-----------------------------------------------------------------------*/	
	public:

		/**
		   Initializes a new empty Vector<T> instance.
		*/
		Vector()
			: count(0), capacity(0)
		{
		}

		/**
		   Initializes a new Vector<T> instance with the given capacity.
		   @param  Capacity Initial capacity.
		*/
		Vector(Int32 capacity)
		{
		}

		/**
		   Initializes a new Vector<T> instance that contains elements copied from other Vector<T>.
		   @param  Other Instance to copty.
		*/
		Vector(const Vector& other)
		{
		}

		/**
		   Initializes a new Vector<T> instance with a raw array of elements.
		   
		   @param  Pointer Address of the first element.
		   @param  Count   Number of elements contained in the array.
		*/
		template <Size N>
		Vector(const Array<T, N>& array)
		{
			std::cout << "Hola!";
		}

		/**
		   Initializes a new Vector<T> instance with a raw array of elements.
		   
		   @param  Pointer Address of the first element.
		   @param  Count   Number of elements contained in the array.
		*/
		Vector(const T* pointer, Int32 count)
		{
		}

		/**
		   Initializes a new Vector<T> instance that adds elements contained in the initializer list. 		  
		   
		   @param  InitializerList Elements to add.
		*/
		Vector(std::initializer_list<T> initializerList)
		{
		}
		
		/**
		   Destroys the Vector<T> instance.	
		*/
		~Vector()
		{
		}

		/*-----------------------------------------------------------------------
		                                 Methods
		-----------------------------------------------------------------------*/
	public:
		
		/**
		   Returns the number of elements contained in the Vector<T>.
		*/
		Int32 Count() const
		{
			return count;
		}

		/**
		   Gets the internal capacity that the Vector<T> can contain before 
		   rezising is requiered.
		*/
		Int32 GetCapacity() const
		{
			return capacity;
		}

		/**
		   Sets the internal capacity that the Vector<T> can contain before 
		   rezising is requiered.
		   
		   @param  Capacity Number of elements that the Vector<T> can contain.
		   @throws ArgumentOutOfRangeException, OutOfMemoryException
		*/
		void SetCapacity(Int32 capacity)
		{

		}

		Int32 Add(const T& element)
		{
			return 0;
		}

		Int32 Add(T&& element)
		{
			return 0;
		}

		void Insert(Int32 index, const T& element)
		{
			
		}

		void Insert(Int32 index, T&& element)
		{
			
		}
		
		bool Remove(const T& element)
		{
			return false;
		}

		bool RemoveAt(Int32 index)
		{
			return false;
		}

		Int32 RemoveAll(/* Predicate<T> predicate*/) 
		{
			return 0;
		}
		
		void Clear()
		{

		}

		Int32 Contains(const T& element) const
		{
			return 0;
		}

	private:

		template <typename ... TArguments>
		Int32 Emplace(TArguments&& ... arguments)
		{
			return 0;
		}

		/*-----------------------------------------------------------------------
		                                Operators
		-----------------------------------------------------------------------*/

		/*Vector& operator=(const Vector& other);
		Vector& operator=(Vector&& other);
		Vector& operator=(std::initializer_list<T> initializer);

		T& operator[](Int32 index);
		const T& operator[](Int32 index) const;

		bool operator==(const Vector& other) const;
		bool operator!=(const Vector& other) const;

		Vector& operator+=(const Vector& other);
		Vector& operator+=(Vector&& other);
		Vector& operator+=(std::initializer_list<T> initializer);*/

		/*-----------------------------------------------------------------------
		                               IIterable
		-----------------------------------------------------------------------*/
	public:

		SharedPointer<IIterator<T>> GetIterator() const
		{		
			return new VectorIterator(*this);
		}

		/*-----------------------------------------------------------------------
		                             VectorIterator
		-----------------------------------------------------------------------*/
	private:

		class VectorIterator : public IIterator<T> 
		{
		private:

			const Vector<T, TAllocator> vector;
			Int32 index;
			Int32 version;

		public:

			VectorIterator(const Vector<T, TAllocator>& vector)
				: vector(vector), index(0), version(vector.count)
			{
			}

			bool MoveNext()
			{
				if ((version == vector.count) && (index < vector.count))
				{
					index++;
					return true;
				}

				if (version != vector.count)
				{
					// @todo throw InvalidOperationException
				}
				index = vector.count + 1;
				return false;
			}

			bool HasCurrent() const
			{
				return !(index == 0 || index == vector.count + 1);
			}

			T& GetCurrent()
			{
				if (!HasCurrent())
				{
					// @todo throw InvalidOperationException
				}				
				throw std::exception();
				//return vector[index - 1];
			}

			const T& GetCurrent() const
			{
				if (index == 0 || index == vector.count + 1)
				{
					// @todo throw InvalidOperationException
				}
				throw std::exception();
				//return vector[index - 1];
			}

			void Reset()
			{
				if (version != vector.count)
				{
					// @todo throw InvalidOperationException
				}
				index = 0;
			}
		};
	};
}