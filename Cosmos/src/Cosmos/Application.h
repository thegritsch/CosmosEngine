#pragma once
#include "Core.h"
#include "Events/Event.h"
#include "Window.h"
#include "Cosmos/Events/ApplicationEvent.h"

namespace Cosmos
{
	class COSMOS_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event& e);
	private:
		bool OnWindowClose(WindowCloseEvent&);

		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
	};
	Application* CreateCosmosApplication();
}
