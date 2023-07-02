#pragma once

#include <SFML/Graphics/RenderWindow.hpp>

/*
	The window class is responsible for managing the window of the game.
	The features that this window includes:
		-Resizing
		-VSync
		-Fullscreen
	The window's backend is managed by sfml
*/

namespace DunnEngine {

	class Window
	{
	public:
		Window(const std::string& title, uint32_t width, uint32_t height, bool fullScreen = false, bool vSync = true); // Constructs the window
		~Window(); // Destroys the window

		const std::shared_ptr<sf::RenderWindow> GetSFMLWindow() { return m_Window; } // returns the sfml window for any needs that are not written in this class

		const uint32_t GetWidth() const { return m_WindowProps.Width; }
		const uint32_t GetHeight() const { return m_WindowProps.Height; }

		void SetVSync(bool enabled);
		bool IsVSync() const;

		void SetFullScreen(bool enabled);
		bool IsFullScreen();

		void ClearWindow() const;
		void UpdateWindow() const;

	private:
		struct WindowProps
		{
			std::string Title;
			uint32_t Width, Height;
			bool IsFullScreen;
			bool IsVSync;
		};
		WindowProps m_WindowProps;				     // Holds the window's properties
		std::shared_ptr<sf::RenderWindow> m_Window;  // Holds the pointer to the sfml window
	};

}