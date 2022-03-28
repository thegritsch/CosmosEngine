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

#define BIT(x) (1 << x)