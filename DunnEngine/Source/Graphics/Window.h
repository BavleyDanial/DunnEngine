#pragma once

// Auther: Bavley Danial
// Date: 7/11/2023
//
// TDE - The Dunn Engine
//
// This software is provided 'as-is', without any express or implied warranty.
// In no event will the authors be held liable for any damages arising from the use of this software.
//
// Permission is granted to DunnGames to use this software for any purpose,
// including commercial applications, and to alter it and redistribute it freely,
// subject to the following restrictions:
//
// 1. The origin of this software must not be misrepresented;
//    you must not claim that you wrote the original software.
//    If you use this software in a product, an acknowledgment
//    in the product documentation would be appreciated but is not required.
//
// 2. Altered source versions must be plainly marked as such,
//    and must not be misrepresented as being the original software.
//
// 3. This notice may not be removed or altered from any source distribution.
//

#include <SFML/Graphics/RenderWindow.hpp>

namespace DunnEngine {

	/*
		The window class is responsible for managing the window of the game.
		The features that this window includes:
			-Resizing
			-VSync
			-Fullscreen
		The window's backend is managed by sfml
	*/
	class Window
	{
	public:
		// Constructs the window with the provided data
		Window(const std::string& title, uint32_t width, uint32_t height, bool fullScreen = false, bool vSync = true);
		// Destroys the window
		~Window();

		const std::shared_ptr<sf::RenderWindow> GetSFMLWindow() { return m_Window; } // returns the sfml window for any needs that are not written in this class

		//--------------------------------- CLIENT SIDE FUNCTOINS ---------------------------------\\

		const uint32_t GetWidth() const { return m_WindowProps.Width; }
		const uint32_t GetHeight() const { return m_WindowProps.Height; }
		
		// Sets vsync on or off. This function can be called in any function in the client game
		void SetVSync(bool enabled);
		// returns if vsync is on or off. This function can be called in any function in the client game
		bool IsVSync() const;

		// Sets fullscreen on or off. This function can be called in any function in the client game Could be improved by not only fullscreening
		// to one mode and instead fullscreening with a different resolution if the client has provided that
		void SetFullScreen(bool enabled);
		// returns if fullscreen is on or off. This function can be called in any function in the client game
		bool IsFullScreen();


		//--------------------------------- ENGINE SIDE FUNCTOINS ---------------------------------\\

		// Clears the window of the old frame so that the new frame can be drawn on it. This function must ONLY be called in the engine side
		void ClearWindow() const;
		// Updates the window by changing the old frame to the new frame. This function must ONLY be called in the engine side
		void UpdateWindow() const;
		// Polls the events happening in the window. This function must ONLY be called in the engine side
		bool PollEvents(sf::Event& event) const;

	private:
		// Windows Properities
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