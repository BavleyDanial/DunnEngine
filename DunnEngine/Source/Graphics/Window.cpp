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

}