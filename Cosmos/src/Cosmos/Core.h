#pragma once

#ifdef COS_PLATFORM_WINDOWS
	#ifdef COS_BUILD_DLL
		#define COSMOS_API __declspec(dllexport)
	#else 
		#define COSMOS_API __declspec(dllimport)
	#endif // COS_BUILD_DLL
#else 
	#error COSMOS ONLY SUPPORTS WINDOWS
#endif // COS_PLATFORM_WINDOWS

#ifdef HZ_ENABLE_ASSERTS
	#define CS_ASSERT(x, ...) { if(!(x)) { HZ_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define CS_CORE_ASSERT(x, ...) { if(!(x)) { HZ_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define CS_ASSERT(x, ...)
	#define CS_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)