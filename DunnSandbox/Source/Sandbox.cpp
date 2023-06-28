#include <DunnEngine.h>

#include <iostream>

class Sandbox : public DunnEngine::Application
{
public:
	void OnInit() override
	{
		std::cout << "Initialized successfully!" << std::endl;
	}

	void OnUpdate() override
	{

	}

	void OnKeyEvent() override
	{

	}

	void OnMouseEvent() override
	{

	}

private:

};

DunnEngine::Application* DunnEngine::CreateApplication()
{
	return new Sandbox();
}