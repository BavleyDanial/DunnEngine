#pragma once

// Auther: Bavley Danial
// Date: 7/11/2023
//
// TDE - The Dunn Engine
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

	struct WindowProps
	{
		std::string Title = "";
		uint32_t Width = 0, Height = 0;
		bool IsFullScreen = false;
		bool IsVSync = true;
	};

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
		// Creates the window with the provided data
		static void Create(const std::string& title, uint32_t width, uint32_t height, bool fullScreen = false, bool vSync = true);
		// Destroys the window
		static void Shutdown();

		// returns the sfml window for any needs that are not written in this class
		static const std::shared_ptr<sf::RenderWindow> GetSFMLWindow() { return m_Window; }

		//--------------------------------- CLIENT SIDE FUNCTOINS ---------------------------------\\

		static void SetWidth(uint32_t width);
		static void SetHeight(uint32_t height);

		static const uint32_t GetWidth() { return m_WindowProps.Width; }
		static const uint32_t GetHeight() { return m_WindowProps.Height; }

		static void Resize(uint32_t width, uint32_t height);
		
		// Sets vsync on or off. This function can be called in any function in the client game
		static void SetVSync(bool enabled);
		// returns if vsync is on or off. This function can be called in any function in the client game
		static bool IsVSync();

		// Sets fullscreen on or off. This function can be called in any function in the client game Could be improved by not only fullscreening
		// to one mode and instead fullscreening with a different resolution if the client has provided that
		static void SetFullScreen(bool enabled);
		// returns if fullscreen is on or off. This function can be called in any function in the client game
		static bool IsFullScreen();


		//--------------------------------- ENGINE SIDE FUNCTOINS ---------------------------------\\

		// Clears the window of the old frame so that the new frame can be drawn on it. This function must ONLY be called in the engine side
		static void ClearWindow();
		// Updates the window by changing the old frame to the new frame. This function must ONLY be called in the engine side
		static void UpdateWindow();
		// Polls the events happening in the window. This function must ONLY be called in the engine side
		static bool PollEvents(sf::Event& event);

	private:
		static WindowProps m_WindowProps;				     // Holds the window's properties
		static std::shared_ptr<sf::RenderWindow> m_Window;  // Holds the pointer to the sfml window
	};

}