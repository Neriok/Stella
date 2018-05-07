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

using namespace Stella;

template <typename T>
class Temp
{
public:

	T something;

	void GetSomething() const
	{
		SharedPointer<T> sptr;
		
	}
};

int main()
{
	int integer = 3;
	int* intptr = &integer;
	SharedPointer<void> sptr;
	//std::cout << sizeof(void) << std::endl;

	/*Development::Vector<int, int> k;
	SharedPointer<IEnumerator<int>> enumerator = k.GetEnumerator();
	enumerator->MoveNext();*/

	getchar();
	return 0;
}