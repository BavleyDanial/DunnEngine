// Auther: Bavley Danial
// Date: 7/11/2023
//
// TDE - The Dunn Engine
//

#include "Window.h"

namespace DunnEngine {

	WindowProps Window::m_WindowProps;
	sf::RenderWindow* Window::m_Window = nullptr;

	void Window::Create(const std::string& title, uint32_t width, uint32_t height, bool fullScreen, bool vSync)
	{
		m_WindowProps.Title = title;
		m_WindowProps.Width = width;
		m_WindowProps.Height = height;
		m_WindowProps.IsFullScreen = fullScreen;
		m_WindowProps.IsVSync = vSync;

		m_Window = new sf::RenderWindow(sf::VideoMode(width, height), title); // create the window with the specified width, height, and title
		SetVSync(vSync);			// set vsync if vsync is enabled
		SetFullScreen(fullScreen);  // set fullscreen if fullscreen is enabled
	}

	void Window::Shutdown()
	{
		m_Window->close();
		delete m_Window;
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
		sf::FloatRect viewPort = sf::FloatRect(0, 0, width, height);		// Reset the viewport to match our new width and height
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
			m_Window->create(sf::VideoMode::getFullscreenModes()[0], m_WindowProps.Title, sf::Style::Fullscreen);	// Set the window fullscreen to the primary monitor. This could be improved by supporting different fullscreen modes
		else
			m_Window->create(sf::VideoMode(m_WindowProps.Width, m_WindowProps.Height), m_WindowProps.Title);

		m_WindowProps.Width = m_Window->getSize().x;
		m_WindowProps.Height = m_Window->getSize().y;

		m_WindowProps.IsFullScreen = enabled;
		Resize(GetWidth(), GetHeight());
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