#pragma once

#include <SFML/Graphics/RenderWindow.hpp>

namespace DunnEngine {

	class Window
	{
	public:
		Window(const std::string& title, uint32_t width, uint32_t height, bool fullScreen = false, bool vSync = true);
		~Window();

		const std::shared_ptr<sf::RenderWindow> GetSFMLWindow() { return m_Window; }

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
		WindowProps m_WindowProps;
		std::shared_ptr<sf::RenderWindow> m_Window;
	};

}