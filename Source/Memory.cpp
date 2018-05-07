#include "Memory.h"
#include <stdlib.h>



// ----------------------------------------------------------------------
// Operators
// ----------------------------------------------------------------------

void* operator new(Size size, const Char* description)
{
	return MemoryF::StaticAllocation(size, false);
}

void* operator new(Size size, void* (*alloc_func)(Size size))
{
	return alloc_func(size);
}

// ----------------------------------------------------------------------
// Memory
// ----------------------------------------------------------------------

#ifdef REVERSE_DEBUG_ENABLED
Size MemoryF::_memory_usage = 0;
Size MemoryF::_max_usage = 0;
#endif

Size MemoryF::_allocation_count = 0;

void * MemoryF::StaticAllocation(Size bytes, Boolean pad_align)
{
#ifdef REVERSE_DEBUG_ENABLED
	Boolean prepad = true;
#else
	Boolean prepad = pad_align;
#endif // REVERSE_DEBUG_ENABLED

	void* memory = malloc(bytes + (prepad? PAD_ALIGN : 0));
	MemoryF::_allocation_count++;

	ERR_NULL_ARGUMENT_RETURN(memory, NULL);

	if (prepad)
	{
		UInt64* size64 = (UInt64*)memory;
		*size64 = bytes;

		UInt8* size8 = (UInt8*)memory;
		
#ifdef REVERSE_DEBUG_ENABLED

		MemoryF::_memory_usage += bytes;

		if (MemoryF::_memory_usage > MemoryF::_max_usage)
		{
			MemoryF::_max_usage = MemoryF::_memory_usage;
		}		

#endif // REVERSE_DEBUG_ENABLED

		return size8 + PAD_ALIGN;
	}
	else
	{
		return memory;
	}
}



void* MemoryF::StaticReallocation(void* pointer, Size bytes, Boolean pad_align)
{
	if (pointer == NULL)
	{
		return MemoryF::StaticAllocation(bytes, pad_align);
	}

	UInt8* memory = (UInt8*)pointer;

#ifdef REVERSE_DEBUG_ENABLED
	Boolean prepad = true;
#else
	Boolean prepad = pad_align;
#endif // REVERSE_DEBUG_ENABLED

	if (prepad)
	{
		memory -= PAD_ALIGN;
		UInt64* size = (UInt64*)memory;

#ifdef REVERSE_DEBUG_ENABLED

		_memory_usage -= *size;
		_memory_usage += bytes;

#endif // REVERSE_DEBUG_ENABLED

		if (bytes == 0)
		{
			free(memory);
			return NULL;
		}
		else
		{
			*size = bytes;

			memory = (UInt8*)realloc(memory, bytes + PAD_ALIGN);

			if (!memory)
			{
				return NULL;
			}

			size = (UInt64*)memory;
			*size = bytes;

			return memory + PAD_ALIGN;
		}
	}
	else
	{
		memory = (UInt8*)realloc(memory, bytes);

		if (memory == NULL && bytes > 0)
		{
			return NULL;
		}

		return memory;
	}
}

void MemoryF::StaticFree(void* pointer, bool pad_align)
{
	if (pointer == NULL)
	{
		return;
	}

	UInt8* memory = (UInt8*)pointer;
	_allocation_count--;

#ifdef REVERSE_DEBUG_ENABLED
	Boolean prepad = true;
#else
	Boolean prepad = pad_align;
#endif 

	if (prepad)
	{
		memory -= PAD_ALIGN;		

#ifdef REVERSE_DEBUG_ENABLED
		UInt64* size = (UInt64*)memory;
		MemoryF::_memory_usage -= *size;
#endif
		free(memory);
	}
	else
	{
		free(memory);
	}
}

Size MemoryF::GetMemoryAvailable()
{
	return 0;
}

Size MemoryF::GetMemoryUsage()
{
#ifdef REVERSE_DEBUG_ENABLED

	return MemoryF::_memory_usage;

#else 

	return 0;

#endif
}

Size MemoryF::GetMemoryMaxUsage()
{
#ifdef REVERSE_DEBUG_ENABLED

	return MemoryF::_max_usage;

#else 

	return 0;

#endif
}

Size MemoryF::GetAllocationCount()
{
	return _allocation_count;
}

