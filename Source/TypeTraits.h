#pragma once

#include <RemoveReference.h>

template <typename T> 
__forceinline typename RemoveReference<T>::Type&& Move(T&& obj)
{
	typedef typename RemoveReference<T>::Type CastType;
	return (CastType&&)obj;
}