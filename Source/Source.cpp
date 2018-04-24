#include "Typedef.h"
#include "String.h"
#include <stdio.h>
#include <iostream>
#include <vector>
#include "ArgumentException.h"
#include "Exception.h"
#include "Collections\InitializerList.h"

using namespace Stella;

int main()
{
	try
	{
		throw Exception("AHH");
	}
	catch (Exception& ex)
	{
		std::wcout << ex.GetMessage().ToWideChar();
	}

	getchar();
	return 0;
}