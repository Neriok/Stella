#pragma once
#include "Typedef.h"

namespace Stella
{
	/*-----------------------------------------------------------------------
									   And
	-----------------------------------------------------------------------*/

	template <typename ... T> 
	struct And;

	template <bool TLeft, typename ... TRight>
	struct AndValue
	{
		enum { Value = And <TRight ...>::Value};
	};

	template <typename ... TRight>
	struct AndValue <false, TRight ...>
	{
		enum { Value = false };
	};

	template <typename TLeft, typename ... TRight>
	struct And<TLeft, TRight ...> : AndValue <TLeft::Value, TRight ...>
	{
	};

	template <>   
	struct And <> 
	{ 
		enum { Value = true }; 
	};

	/*-----------------------------------------------------------------------
									   Or
	-----------------------------------------------------------------------*/

	template <typename ... T>
	struct Or;

	template <bool TLeft, typename ... TRight>
	struct OrValue
	{
		enum { Value = Or<TRight ...>::Value };
	};

	template <typename ... TRight>
	struct OrValue <true, TRight ...>
	{
		enum { Value = true };
	};

	template <typename TLeft, typename ... TRight>
	struct Or <TLeft, TRight ...> : OrValue <TLeft::Value, TRight ...>
	{
	};

	template <>
	struct Or <>
	{
		enum { Value = false };
	};

	/*-----------------------------------------------------------------------
									  Not
	-----------------------------------------------------------------------*/

	template <typename T>
	struct Not
	{
		enum { Value = !T::Value };
	};
}