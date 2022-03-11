#pragma once
#include "Application.h"
#ifdef COS_PLATFORM_WINDOWS

extern Cosmos::Application* Cosmos::CreateCosmosApplication();

int main(int argc, char** argv)
{
	auto app = Cosmos::CreateCosmosApplication();
	app->Run();
	return 0;
}
#endif