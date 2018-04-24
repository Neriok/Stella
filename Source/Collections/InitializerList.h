#pragma once
#include "Typedef.h"

namespace Stella::Collections
{
	template<class TElement>
	class InitializerList
	{
		// ----------------------------------------------------------------------
		// -- Fields
		// ----------------------------------------------------------------------

	private:

		const TElement* first;
		const TElement* last;

		// ----------------------------------------------------------------------
		// -- Constructors & Destructors
		// ----------------------------------------------------------------------

	public:

		constexpr InitializerList() noexcept
			: first(nullptr), 
			  last (nullptr)
		{
			// Empty list
		}

		explicit constexpr InitializerList(const TElement* first, const TElement* last) noexcept
			: first(first),
			  last(last)
		{
		}

		// ----------------------------------------------------------------------
		// -- Methods
		// ----------------------------------------------------------------------

		constexpr const TElement* Begin() const noexcept
		{
			return first;
		}

		constexpr const TElement* End() const noexcept
		{
			return last;
		}

		constexpr Size GetSize() const noexcept
		{
			return (Size)last - first;
		}
	};
}

