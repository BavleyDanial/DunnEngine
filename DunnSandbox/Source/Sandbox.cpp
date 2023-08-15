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

using namespace DunnEngine;

class Sandbox : public DunnEngine::Application
{
public:
	void OnInit() override
	{

	}

	void OnUpdate() override
	{

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