#pragma once
#include "IEnumerator.h"
#include "Memory/SharedPointer.h"

using namespace Stella::Memory;

namespace Stella::Collections
{
	template <typename T>
	class IEnumerable
	{
	public:
		virtual ~IEnumerable() {}
		virtual SharedPointer<IEnumerator<T>> GetEnumerator() const = 0;
	};
}