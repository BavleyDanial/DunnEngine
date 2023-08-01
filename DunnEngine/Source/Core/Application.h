#pragma once

// Auther: Bavley Danial
// Date: 7/11/2023
//
// TDE - The Dunn Engine
//

/// <summary>
/// 
/// This is the file that contains the application class and a function declration for creating an application.
/// This application class is meant to be the base class for any client application (game) in the sandbox project.
/// The application class is responsible for initiating any needed class, calling the different functions that the client defines (such as OnInit(), OnUpdate(), OnKeyEvent(), OnMouseEvent())
/// To use this class the client will inherit this class and then define the CreateApplication() function in which they return a new instance of their derived class (See example in DunnSandbox)
/// 
/// </summary>

#include <SFML/Window.hpp>

namespace DunnEngine {

	class Application
	{
	public:
		//--------------------------------- ENGINE SIDE FUNCTIONS ---------------------------------\\

		// Constructs the Application
		Application();
		// Destroys the Application
		~Application();
		
		// Run the application. This calls all the functions that need to happen when running the client app
		void Run();
		// Calls each of the client side event functions depending on the kind of the event
		// It also does some internal engine stuff in some events
		void OnEvent();

		//--------------------------------- CLIENT SIDE FUNCTIONS ---------------------------------\\
		
		// The Init function is only called once in the entire lifetime of the client game
		// This function should be used for initialising anything in the game
		virtual void OnInit() = 0;
		// The Update function is called once every frame during the lifetime of the client game
		// This function should be used for implementing game logic and any graphics rendering
		virtual void OnUpdate() = 0;
		// The KeyEvent function is called once every frame if and only if there was a relavent event for this particular case during the lifetime of the client game
		// This function should be used for implementing static things like a main menu or settings menu or something like that
		virtual void OnKeyEvent(sf::Event event) = 0;
		// The MouseEvent function is called once every frame if and only if there was a relavent event for this particular case during the lifetime of the client game
		// This function should be used for implementing static things like a main menu or settings menu or something like that
		virtual void OnMouseEvent(sf::Event event) = 0;
	private:
		static Application* s_Instance;   // Stores the ONLY instance of the application
		bool m_IsRunning = true;          // Keeping track if the application is still running
	};

	Application* CreateApplication();     // Function to create the application instance, it MUST be defined in the client
}