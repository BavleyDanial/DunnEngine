#include <DunnEngine.h>

#include <iostream>

class Sandbox : public DunnEngine::Application
{
public:
	void OnInit() override
	{
		LOG_INFO("Initialized sandbox successfully!");
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