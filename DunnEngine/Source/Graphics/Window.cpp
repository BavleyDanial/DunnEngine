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

#include "Window.h"

namespace DunnEngine {

	WindowProps Window::m_WindowProps;
	std::shared_ptr<sf::RenderWindow> Window::m_Window = nullptr;

	void Window::Create(const std::string& title, uint32_t width, uint32_t height, bool fullScreen, bool vSync)
	{
		m_WindowProps.Title = title;
		m_WindowProps.Width = width;
		m_WindowProps.Height = height;
		m_WindowProps.IsFullScreen = fullScreen;
		m_WindowProps.IsVSync = vSync;

		m_Window = std::make_unique<sf::RenderWindow>(sf::VideoMode(width, height), title); // create the window with the specified width, height, and title
		SetVSync(vSync);
		SetFullScreen(fullScreen);
	}

	void Window::Shutdown()
	{
		m_Window->close();
	}

	void Window::SetWidth(uint32_t width)
	{
		Resize(width, m_WindowProps.Height);
	}
	void Window::SetHeight(uint32_t height)
	{
		Resize(height, m_WindowProps.Height);
	}
	void Window::Resize(uint32_t width, uint32_t height)
	{
		m_WindowProps.Width = width;
		m_WindowProps.Height = height;
		sf::FloatRect viewPort = sf::FloatRect(0, 0, width, height);
		m_Window->setView(sf::View(viewPort));
	}
	
	void Window::SetVSync(bool enabled)
	{
		if (enabled)
			m_Window->setVerticalSyncEnabled(true);
		else
			m_Window->setVerticalSyncEnabled(false);

		m_WindowProps.IsVSync = enabled;
	}
	bool Window::IsVSync()
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

	void Window::ClearWindow()
	{
		m_Window->clear();
	}

	void Window::UpdateWindow()
	{
		m_Window->display();
	}
	bool Window::PollEvents(sf::Event& event)
	{
		return m_Window->pollEvent(event);
	}
}