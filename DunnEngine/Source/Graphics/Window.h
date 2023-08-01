#pragma once

// Auther: Bavley Danial
// Date: 7/11/2023
//
// TDE - The Dunn Engine
//

/// <summary>
/// 
/// This file includes Window class. This class is resposible for managing the ONLY window in the game
/// In the mean time there is only one window so you can't create multiple windows. Though it will never be a problem for a game
/// This class can create a window, close it, set width, set height, get width, get height, get resize, set vsync
/// get the vysnc status, set fullscreen, get the status of fullscreen, clear the window, update the window, and get events
/// This class can not be instantiated as an object as there is only one instance of it
/// 
/// </summary>

#include <SFML/Graphics/RenderWindow.hpp>

namespace DunnEngine {

	// A structure to hold all the window properties
	struct WindowProps
	{
		std::string Title = "";				// Title of the window
		uint32_t Width = 0, Height = 0;		// Width and height of the window
		bool IsFullScreen = false;			// The state of fullscreen mode
		bool IsVSync = true;				// The state of vsync mode
	};

	class Window
	{
	public:
		//--------------------------------- COMMON FUNCTIONS ---------------------------------\\

		// Create a window with the provided data
		// A title, a width, a height, a fullscreen status that is by default set to false and a vsync stats that is set to false by default
		static void Create(const std::string& title, uint32_t width, uint32_t height, bool fullScreen = false, bool vSync = false);
		// Closes the window
		static void Shutdown();

		// Get the sfml Window. This should only be used if there is a custom window behaviour needed that is only supplied by sfml
		static sf::RenderWindow* GetSFMLWindow() { return m_Window; }

		//--------------------------------- CLIENT SIDE FUNCTOINS ---------------------------------\\

		// Set the width with the provided data. It also calls Window::Resize()
		static void SetWidth(uint32_t width);
		// Set the height with the provided data. It also calls Window::Resize()
		static void SetHeight(uint32_t height);

		// Get the current width of the window
		static const uint32_t GetWidth() { return m_WindowProps.Width; }
		// Get the current height of the window
		static const uint32_t GetHeight() { return m_WindowProps.Height; }

		// Resize the window with the provided data. This is called when needed to resize the window
		static void Resize(uint32_t width, uint32_t height);
		
		// Set the vsync status of the window with the provided data
		static void SetVSync(bool enabled);
		// Get the vsync status of the window
		static bool IsVSync();

		// Set the fullscreen status of the window with the provided data
		static void SetFullScreen(bool enabled);
		// Get the vsync status of the window
		static bool IsFullScreen();

		//--------------------------------- ENGINE SIDE FUNCTIONS ---------------------------------\\

		// Clears the window's content. Must be called at the start of each frame
		static void ClearWindow();
		// Update the window's content. Must be called at the end of each frame
		static void UpdateWindow();
		// Get the window's events. Must be called at the each frame
		static bool PollEvents(sf::Event& event);

	private:
		static WindowProps m_WindowProps;				     // Holds the window's properties
		static sf::RenderWindow* m_Window;					 // Holds the pointer to the sfml window
	};

}