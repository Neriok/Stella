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

using namespace Stella;

int main()
{
	Array<int, 3> n = { 1, 2, 3 };

	SharedPointer<IEnumerator<int>> e = n.GetEnumerator();

	while (e->MoveNext())
	{		
		std::cout << e->GetCurrent() << std::endl;
	}

	getchar();
	return 0;
}