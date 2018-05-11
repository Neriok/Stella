#pragma once

namespace Stella::Collections
{
	template <typename T>
	class IIterator
	{
	public:
		virtual ~IIterator() {}
		virtual bool MoveNext() = 0;
		virtual bool HasCurrent() const = 0;
		virtual T& GetCurrent() = 0;
		virtual const T& GetCurrent() const = 0;
		virtual void Reset() = 0;
	};
}