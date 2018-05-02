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

#include <vector>

using namespace Stella;


int main()
{
	Development::Vector<int, int> n;
	n.Add(2);
	//n.GetEnumerator().MoveNext();
	IEnumerator<int>* ne = &n.GetEnumerator();
	//ne->MoveNext();

	//ICollection<int>& c = n;

	getchar();
	return 0;
}