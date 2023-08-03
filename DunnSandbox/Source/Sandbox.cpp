// Auther: Bavley Danial
// Date: 7/11/2023
//
// TDE - The Dunn Engine

/// <summary>
/// 
/// This is the file that you use to create anything with the engine.
/// 1. You must include <Core/EntryPoint.h> in this file ONLY. As it is where the main function sits
/// 2. You must include <DunnEngine.h> to access the engine's features. This can be included in any file that needs it.
/// 3. There must be a class that inherits from DunnEngine::Application. This class is what the engine expects to find in order to run.
/// 4. There must be a DunnEngine::Application* DunnEngine::CreateApplication() function (outisde of the class) that returns a new instance of the class.
/// 
/// The class that inherits from DunnEngine::Application (in this case Sandbox) includes 4 functions that you can use and they have different properties
/// 1. An OnInit() function that runs only once at the start of the game. This should be used to initialize anything.
/// 2. An OnUpdate() function that runs once every frame. This is where you apply your logic in the game and render stuff.
/// 3. An OnKeyEvent() function that runs when there is a key event (a key being pressed or released or held). This should not be used in the logic but instead should be used for things like enabling a pause menu and similar things. 
/// 4. An OnMouseEvent() function that runs when there is a mouse event (moues being moved or a button pressed or released or held) This should not be used in the logic but instead should be used for things like enabling a pause menu and similar things.
/// 
/// </summary>

// <notes>
// 
// Sandbox must create a window, crash when no window is created, need to fix that.
// 
// </notes>

#include <EntryPoint.h>
#include <DunnEngine.h>
#include <iostream>


using namespace DunnEngine;

class Sandbox : public DunnEngine::Application
{
public:
	
public:
	void OnInit() override
	{
		// Logging testing
		{
			// Testing printing with different kinds of logging
			LOG_INFO("Test Info");
			LOG_TRACE("Test Trace");
			LOG_WARN("Test Warn");
			LOG_ERROR("Test Error\n");

			// Testing printing variables
			int a = 123;
			bool b = true;
			float f = 5.324235f;
			std::string s = "String";
			
			LOG_INFO("a: {0}", a);
			LOG_TRACE("b: {0}", b);
			LOG_WARN("f: {0}", f);
			LOG_ERROR("s: {0}\n", s);

			// Logging multiple variables
			LOG_INFO("a: {0}, b: {1}, s: {2}, f: {3}", a, b, s, f);
			LOG_TRACE("a: {0}, b: {1}, s: {2}, f: {3}", a, b, s, f);
			LOG_WARN("a: {0}, b: {1}, s: {2}, f: {3}", a, b, s, f);
			LOG_ERROR("a: {0}, b: {1}, s: {2}, f: {3}", a, b, s, f);
		}

		// Testing Window
		{
			//Window::Create("Test!", 1280, 720, false, false);
			//Window::Create("Test!", 1280, 720, true, true);
			//Window::Create("Test!", 1280, 720, true, false);
			Window::Create("Test!", 1280, 720, false, true);					// vsync not enabling here for some reason?
			//
			//Window::SetVSync(true);									 		// Works as expected
			//Window::SetFullScreen(true);
			//Window::SetVSync(false);									 		// Works as expected
			//Window::SetFullScreen(false);
			// 
			//Window::SetWidth(480);
			//Window::SetHeight(480);
			//Window::Resize(480, 480);
			//Window::SetWidth(-480);
			//Window::SetHeight(-480);
			//Window::Resize(-480, -480);
			//
			//LOG_INFO("IsFullscreen: {0}", Window::IsFullScreen());
			//LOG_INFO("IsVSync: {0}", Window::IsVSync());
			//
			//Window::Shutdown();

		}

		// ResourceManager testing
		{
			// ResourceManager::LoadWithXML("Resources/resources.xml");
			// ResourceManager::LoadTexture("TestTexture", "Resources/TestTexture.png");
			// ResourceManager::LoadFont("TestFont", "Resources/TestFont.ttf");
			// ResourceManager::LoadSound("TestSound", "Resources/TestAudio.wav");
			// ResourceManager::LoadWithXML("");
			// ResourceManager::LoadTexture("TestTexture", "");
			// ResourceManager::LoadFont("TestFont", "");
			// ResourceManager::LoadSound("TestSound", "");
			// ResourceManager::LoadWithXML("Resources/FH.xml");
			// ResourceManager::LoadTexture("TestTexture", "Resources/FH.png");
			// ResourceManager::LoadFont("TestFont", "Resources/FH.ttf");
			// ResourceManager::LoadSound("TestSound", "Resources/FH.wav");
			// ResourceManager::LoadWithXML("Resources/resources.xml");
			// ResourceManager::LoadTexture("", "Resources/TestTexture.png");
			// ResourceManager::LoadFont("", "Resources/TestFont.ttf");
			// ResourceManager::LoadSound("", "Resources/TestAudio.wav");
			// ResourceManager::LoadTexture("TestTexture", "Resources/TestAudio.wav");
			// ResourceManager::LoadFont("TestFont", "Resources/TestTexture.png");
			// ResourceManager::LoadSound("TestSound", "Resources/TestFont.ttf");

		}
		
		// Graphics testing
		{

		}

	}

	void OnUpdate() override
	{
		// Input testing
		{
			// LOG_TRACE("F key status is {0}", Input::IsKeyPressed(TDE_KEY_F));
			// Input::IsKeyPressed(-1);
			// Input::IsKeyPressed(101);
			// LOG_TRACE("Left mouse button status is {0}", Input::IsMouseButtonPressed(TDE_MOUSE_LEFT));
			// Input::IsMouseButtonPressed(-1);
			// Input::IsMouseButtonPressed(5);
			// LOG_TRACE("Mouse position: ({0}, {1})", Input::GetMousePosition().x, Input::GetMousePosition().y);
			// Input::SetMousePoisiton(Window::GetWidth() / 2, Window::GetHeight() / 2);
		}
	}

	void OnKeyEvent(sf::Event event) override
	{

	}

	void OnMouseEvent(sf::Event event) override
	{

	}
};

DunnEngine::Application* DunnEngine::CreateApplication()
{
	return new Sandbox();
}