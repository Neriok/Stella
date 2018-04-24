#pragma once

namespace Stella
{
	//---------------------------------------------------------------------
	// -- Platforms
	//---------------------------------------------------------------------

	#define PLATFORM_WINDOWS 1
	#define PLATFORM_LINUX   2
	#define PLATFORM_OSX     3
	#define PLATFORM_IOS     4
	#define PLATFORM_ANDROID 5
	#define PLATFORM_SWITCH  6
	#define PLATFORM_PS4     7
	#define PLATFORM_XBOXONE 8

	//---------------------------------------------------------------------
	// -- Architecture
	//---------------------------------------------------------------------

	#define ARCHITECTURE_x86_32 1
	#define ARCHITECTURE_x86_64 2

	//---------------------------------------------------------------------
	// -- Compilers
	//---------------------------------------------------------------------

	#define COMPILER_MSVC   1
	#define COMPILER_GNUC   2
	#define COMPILER_INTEL  3
	#define COMPILER_CLANG  4

	//---------------------------------------------------------------------
	// -- Current platform, compiler, and architecture
	//---------------------------------------------------------------------

	#if   defined(__clang__)

	#	define STELLA_COMPILER COMPILER_CLANG
	#	define STELLA_COMPILER_VERSION __clang_version__
	#	define STELLA_LOCAL_THREAD __thread

	#elif defined(__GNUC__) 

	#	define STELLA_COMPILER COMPILER_CNUC
	#	define STELLA_COMPILER_VERSION (((__GNUC__)*100) + (__GNUC_MINOR__*10) + __GNUC_PATCHLEVEL__)
	#	define STELLA_LOCAL_THREAD __thread

	#elif defined(__INTEL_COMPILER) 

	#	define STELLA_COMPILER COMPILER_INTEL
	#	define STELLA_COMPILER_VERSION __INTEL_COMPILER

	#elif defined(_MSC_VER)

	#	define STELLA_COMPILER STELLA_COMPILER_MSVC
	#	define STELLA_COMPILER_VERSION _MSC_VER
	#	define STELLA_LOCAL_THREAD __declspec(thread)

	#else

	#	pragma error "Unknow compiler. "

	#endif

	// ----------

	#if defined(__WIN32__) || defined(_WIN32)

	#	define STELLA_PLATFORM PLATFORM_WINDOWS

	#elif defined(__APPLE_CC__)

	#	define STELLA_PLATFORM PLATFORM_OSX

	#else

	#	define STELLA_PLATFORM PLATFORM_LINUX

	#endif

	// ----------

	#if defined(__x86_64__) || defined(_M_X64)

	#   define STELLA_ARCHITECTURE_TYPE ARCHITECTURE_x86_64

	#else

	#   define STELLA_ARCHITECTURE_TYPE ARCHITECTURE_x86_32

	#endif
}