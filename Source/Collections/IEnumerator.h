#pragma once

namespace Stella::Collections
{
	template <typename T>
	class IEnumerator
	{
	public:
		virtual ~IEnumerator() {}
		virtual bool MoveNext() = 0;
		virtual T& GetCurrent() = 0;
		virtual const T& GetCurrent() const = 0;
		virtual void Reset() = 0;
	};
}