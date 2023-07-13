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

#include "Window.h"

namespace DunnEngine {

	Window::Window(const std::string& title, uint32_t width, uint32_t height, bool fullScreen, bool vSync)
	{
		m_WindowProps.Title = title;
		m_WindowProps.Width = width;
		m_WindowProps.Height = height;
		m_WindowProps.IsFullScreen = fullScreen;
		m_WindowProps.IsVSync = vSync;

		m_Window = std::make_shared<sf::RenderWindow>(sf::VideoMode(width, height), title); // create the window with the specified width, height, and title
		SetVSync(vSync);
		SetFullScreen(fullScreen);
	}

	Window::~Window()
	{
		m_Window->close();
	}

	
	void Window::SetVSync(bool enabled)
	{
		if (enabled)
			m_Window->setVerticalSyncEnabled(true);
		else
			m_Window->setVerticalSyncEnabled(false);

		m_WindowProps.IsVSync = enabled;
	}
	bool Window::IsVSync() const
	{
		return m_WindowProps.IsVSync;
	}

	void Window::SetFullScreen(bool enabled)
	{
		if (enabled)
			m_Window->create(sf::VideoMode::getFullscreenModes()[0], m_WindowProps.Title, sf::Style::Fullscreen);
		else
			m_Window->create(sf::VideoMode(m_WindowProps.Width, m_WindowProps.Height), m_WindowProps.Title);

		m_WindowProps.IsFullScreen = enabled;
	}
	
	bool Window::IsFullScreen()
	{
		return m_WindowProps.IsFullScreen;
	}

	void Window::ClearWindow() const
	{
		m_Window->clear();
	}

	void Window::UpdateWindow() const
	{
		m_Window->display();
	}
	bool Window::PollEvents(sf::Event& event) const
	{
		return m_Window->pollEvent(event);
	}
}