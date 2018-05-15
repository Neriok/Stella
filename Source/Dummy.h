#pragma once
#include <iostream>

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