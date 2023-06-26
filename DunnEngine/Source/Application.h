#pragma once

#include <SFML/Graphics.hpp>

namespace DunnEngine {

	class Application
	{
	public:
		Application();
		~Application();

		void Run();

		virtual void OnInit() = 0;
		virtual void OnUpdate() = 0;
	private:
		static Application* s_Instance;
	};

	Application* CreateApplication();
}