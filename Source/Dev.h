#pragma once

#include "Typedef.h"
#include "TypeTraits.h"
#include <initializer_list>

using namespace Stella;
using namespace Stella::Collections;

namespace Development
{
	template <typename T, typename TAllocator>
	class Vector //: public ICollection<T>
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

		Vector()
			: count(0), capacity(0)
		{
			// ...
		}

		//Vector(Int32 capacity);
		//Vector(const Vector& other);
		//Vector(const T* pointer, Int32 count);
		//Vector(std::initializer_list<T> initializer);
		
		~Vector()
		{
		}

		/*-----------------------------------------------------------------------
		                                 Methods
		-----------------------------------------------------------------------*/
	public:
		
		Int32 GetCount() const
		{
			return count;
		}

	//	virtual Int32  GetCapacity() const;
	//	void   SetCapacity(Int32 capacity);
	//	Int32  Add(const T& element);
	//	Int32  Add(T&& element);
	//	void   Insert(Int32 index, const T& element);
	//	void   Insert(Int32 index, T&& element);
	//	bool   Remove(const T& element);
	//	bool   RemoveAt(Int32 index);
	//	Int32  RemoveAll(/* Predicate<T> predicate*/);
	//	void   Clear();

	//private:

	//	template <typename ... TArguments>
	//	Int32 Emplace(TArguments&& ... arguments);

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
	};
}