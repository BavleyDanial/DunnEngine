// Auther: Bavley Danial
// Date: 7/11/2023
//
// TDE - The Dunn Engine
//


/// <summary>
///	
/// This is the main function of the entire application (including the game)
/// This main function gets the pointer to the application that the client has created in the Sandbox.cpp (or equivilent) file.
/// It runs the application and deletes it when it gets out of the Run() function (main loop).
/// It must ONLY be included ONCE where the client's application resides.
/// 
/// </summary>

#include "Application.h"

extern DunnEngine::Application* DunnEngine::CreateApplication();

int main(int argc, char** argv)
{
	auto app = DunnEngine::CreateApplication();
	app->Run();
	delete app;

	return 0;
}