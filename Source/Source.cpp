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

using namespace Stella;

class IA
{
public:
	virtual ~IA() {}
	virtual void DoSomething() const = 0;
};

class IAImplementation : public IA
{
public:

	IAImplementation()
	{
		std::cout << "Init implementation" << std::endl;
	}

	void DoSomething() const
	{
		std::cout << "Do something";
	}

	~IAImplementation()
	{
		std::cout << "Destroy implementation" << std::endl;
	}

};

class IReturnIA
{
public:
	virtual ~IReturnIA() {}
	virtual IA* GetIA() const = 0;
};

class B : public IReturnIA
{
public:

	virtual IA* GetIA() const
	{
		return new IAImplementation();
	}

};

void UseInterface()
{
	B instance;
	std::shared_ptr<IA> ias(instance.GetIA());
	ias->DoSomething();
	//IA* ia = instance.GetIA();
	//ia->DoSomething();
	//delete ia;	
}

int main()
{
	UseInterface();
	getchar();
	return 0;
}