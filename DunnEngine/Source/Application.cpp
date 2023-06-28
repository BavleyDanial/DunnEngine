#include "Application.h"

#include <SFML/Graphics.hpp>


#include "Core.h"

namespace DunnEngine {

    Application* Application::s_Instance = nullptr;

	Application::Application()
	{
        DE_CORE_ASSERT(!s_Instance, "Application already exists!")
        s_Instance = this;

        m_Window = std::make_shared<Window>("Hello", (uint32_t)1280, (uint32_t)720);
	}

	Application::~Application()
	{

	}

	void Application::Run()
	{
		OnInit();

        sf::CircleShape shape(100.f);
        shape.setOrigin(shape.getRadius(), shape.getRadius());
        shape.setFillColor(sf::Color::Green);

        while (m_IsRunning)
        {
            sf::Event event;
            while (m_Window->GetSFMLWindow()->pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                {
                    m_Window->GetSFMLWindow()->close();
                    m_IsRunning = false;
                }

                if (event.type == sf::Event::Resized)
                {
                    // update the view to the new size of the window
                    sf::FloatRect visibleArea(0, 0, event.size.width, event.size.height);
                    m_Window->GetSFMLWindow()->setView(sf::View(visibleArea));
                }
                shape.setPosition(m_Window->GetSFMLWindow()->getSize().x / 2, m_Window->GetSFMLWindow()->getSize().y / 2);

            }

            m_Window->ClearWindow();
            m_Window->GetSFMLWindow()->draw(shape);
            m_Window->UpdateWindow();
        }
	}

}