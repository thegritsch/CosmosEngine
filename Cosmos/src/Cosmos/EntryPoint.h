#pragma once

#ifdef COS_PLATFORM_WINDOWS
#include "Log.h"
extern Cosmos::Application* Cosmos::CreateCosmosApplication();

int main(int argc, char** argv)
{
	Cosmos::Log::Init();
	CS_CORE_WARN("Logging initialized!");
	CS_INFO("Hello!");
	auto app = Cosmos::CreateCosmosApplication();
	app->Run();
	return 0;
}
#endif