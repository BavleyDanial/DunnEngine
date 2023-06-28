#pragma once

#include <memory>
#include "Graphics/Window.h"

namespace DunnEngine {

	class Application
	{
	public:
		Application();
		~Application();

		// Internal methods that take care of backend stuff
		void Run();
		void OnEvent();

		// Methods to be overriden by the client
		virtual void OnInit() = 0;
		virtual void OnUpdate() = 0;
		virtual void OnKeyEvent() = 0;
		virtual void OnMouseEvent() = 0;
	private:
		std::shared_ptr<Window> m_Window;
		bool m_IsRunning = true;         // Keeping track if the application is still running

	private:
		static Application* s_Instance;  // Instance of the application
	};

	Application* CreateApplication();    // Function to create the application instance, it MUST be defined in the client
}