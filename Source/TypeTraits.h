#pragma once
#include <RemoveReference.h>

namespace Stella
{
	struct TrueType { enum { Value = true }; };
	struct FalseType { enum { Value = false }; };

	/*-----------------------------------------------------------------------
	                               IsVoidType
	-----------------------------------------------------------------------*/

	template <typename T> struct IsVoidType : FalseType {};
	template <> struct IsVoidType<void> : TrueType {};
	template <> struct IsVoidType<const void> { enum {Value = true}; };
}

enum Type
{
	ReturnValue,

};



template <typename T> 
__forceinline typename RemoveReference<T>::Type&& Move(T&& obj)
{
	typedef typename RemoveReference<T>::Type CastType;
	return (CastType&&)obj;
}