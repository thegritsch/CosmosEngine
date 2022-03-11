#pragma once
#include "Core.h"
namespace Cosmos
{
	class COSMOS_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

		
	};
	Application* CreateCosmosApplication();
}
