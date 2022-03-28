#include "cmpch.h"
#include "Application.h"
#include "Cosmos/Events/ApplicationEvent.h"
#include "Cosmos/Log.h"
#include <GLFW/glfw3.h>

namespace Cosmos {
	Cosmos::Application::Application()
	{
		m_Window = std::unique_ptr<Window>(Window::Create());
	}

	Cosmos::Application::~Application()
	{
	}

	void Application::Run()
	{
		WindowResizeEvent e(1280, 720);
		CS_TRACE(e);
		while (m_Running)
		{
			glClearColor(1, 0, 1, 1);
			glClear(GL_COLOR_BUFFER_BIT);
			m_Window->OnUpdate();
		}
	}
}