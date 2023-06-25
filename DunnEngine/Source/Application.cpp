#include "Application.h"

namespace DunnEngine {

	Application::Application()
	{

	}

	Application::~Application()
	{

	}

	void Application::Run()
	{
		OnInit();

		while (true)
		{
			OnUpdate();
		}
	}

}