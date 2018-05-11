#include "Typedef.h"
#include "String.h"
#include <stdio.h>
#include <iostream>
#include <vector>
#include "ArgumentException.h"
#include "Exception.h"
#include "Collections/Array.h"
#include "Collections\InitializerList.h"
#include "TypeTraits.h"
#include "Dev.h"
#include "Collections/ICollection.h"
#include <stdlib.h>
#include <vector>
#include <memory>
#include "Memory/Allocator.h"
#include "Memory/SharedPointer.h"
#include "Number.h"
#include <array>
#include <vector>

using namespace Stella;

class Dummy
{
public:

	Dummy()
	{
		std::cout << "Initializing dummy ..." << std::endl;
	}

	~Dummy()
	{
		std::cout << "Destroying dummy ..." << std::endl;
	}
};

void Arrays()
{
	//Dummy n[3];
	//Array<Dummy, 3> n;
	int arr[3] = { 1, 3, 4 };

	std::array<int, 3> n = arr;

	Array<int, 3> k = arr;
	
	std::cout << &n[0] << std::endl;
	std::cout << &n[1] << std::endl;
	std::cout << &n[2] << std::endl;
}

int main()
{
	Arrays();

	getchar();
	return 0;
}