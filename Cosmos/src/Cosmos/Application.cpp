#include "Application.h"
#include "Cosmos/Events/ApplicationEvent.h"
#include "Cosmos/Log.h"

namespace Cosmos {
	Cosmos::Application::Application()
	{
	}

	Cosmos::Application::~Application()
	{
	}

	void Application::Run()
	{
		WindowResizeEvent e(1280, 720);
		CS_TRACE(e);
		while (true)
		{

		}
	}
}