#pragma once
#include "IIterator.h"
#include "Memory/SharedPointer.h"

using namespace Stella::Memory;

namespace Stella::Collections
{
	template <typename T>
	class IIterable
	{
	public:
		virtual ~IIterable() {}
		virtual SharedPointer<IIterator<T>> GetIterator() const = 0;
	};
}