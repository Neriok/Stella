#pragma once

//#define REVERSE_DEBUG_ENABLED

#include "Typedef.h"
#include "Error.h"

using namespace Stella;

#define PAD_ALIGN 16

class Memory
{
private:
#ifdef REVERSE_DEBUG_ENABLED
	static Size _memory_usage;
	static Size _max_usage;
#endif

	static Size _allocation_count;

public:

	static void* StaticAllocation(Size bytes, Boolean pad_align = false);
	static void* StaticReallocation(void* pointer, Size bytes, Boolean pad_align = false);
	static void  StaticFree(void* pointer, bool pad_align = false);

	static Size GetMemoryAvailable();
	static Size GetMemoryUsage();
	static Size GetMemoryMaxUsage();
	static Size GetAllocationCount();

};

class DefaultAllocator
{
	inline static void* Allocation(Size memory)
	{
		return Memory::StaticAllocation(memory, false);
	}

	inline static void Free(void* pointer)
	{
		return Memory::StaticFree(pointer, false);
	}
};

void* operator new(Size size, const Char* description);
void* operator new(Size size, void* (*alloc_func)(Size size));

void* operator new(Size size, void* pointer, Size size_check, const Char* description);

template <class T>
inline T* PostInitialize(T* object)
{
	return object;
}

__forceinline void postinitialize_handler(void *) {}

template <class T>
__forceinline T *_post_initialize(T *p_obj) {

	postinitialize_handler(p_obj);
	return p_obj;
}

__forceinline void* operator new(Size size, void* pointer, Size size_check, const Char* description)
{
	return pointer;
}

#define MemoryNewAllocator(m_class, m_allocator) (new (m_allocator::Allocation) m_class)
#define MemoryNewConstructor(m_placement, m_class) _post_initialize(new (m_placement, sizeof(m_class), "") m_class)


