#include "Application.h"

extern DunnEngine::Application* DunnEngine::CreateApplication();

int main(int argc, char** argv)
{
	auto app = DunnEngine::CreateApplication();
	app->Run();
	delete app;

	return 0;
}