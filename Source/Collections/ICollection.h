#pragma once
#include "Typedef.h"
#include "IEnumerable.h"

namespace Stella::Collections
{
	template <typename T>
	class ICollection : IEnumerable<T>
	{
	public:
		virtual ~ICollection() {}
		virtual Int32 Count() const = 0;
		virtual Int32 Add(const T& element) = 0;
		virtual bool  Remove(const T& element) = 0;
		virtual Int32 Contains(const T& element) const = 0;
		virtual void  Clear() = 0;
	};
}