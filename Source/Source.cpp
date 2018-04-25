#include "Typedef.h"
#include "String.h"
#include <stdio.h>
#include <iostream>
#include <vector>
#include "ArgumentException.h"
#include "Exception.h"
#include "Collections\InitializerList.h"

using namespace Stella;

template<typename T>
struct RemoveReference
{
	typedef T Type;
};

template<typename T>
__forceinline typename RemoveReference<T>::Type&& Move(T&& obj)
{
	typedef typename RemoveReference<T>::Type CastType;
	return (CastType&&)obj;
}

template<typename T>
__forceinline T&& Move2(T&& obj)
{
	return obj;
}

int main()
{

	String n = "Hola mundo!";
	
	String k = String(Move2(n));

	std::cout << k;
	getchar();
	return 0;
}