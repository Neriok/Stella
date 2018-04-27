#include "Typedef.h"
#include "String.h"
#include <stdio.h>
#include <iostream>
#include <vector>
#include "ArgumentException.h"
#include "Exception.h"
#include "Collections\InitializerList.h"
#include "TypeTraits.h"

using namespace Stella;


int main()
{
	std::cout << IsVoidType<void>::Value << std::endl;
	std::cout << IsVoidType<const void>::Value << std::endl;


	String n = "Hola mundo!";
	
	String k = String(Move(n));
	std::move(n);

	std::cout << k;
	getchar();
	return 0;
}