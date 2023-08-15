// Auther: Bavley Danial
// Date: 7/11/2023
//
// TDE - The Dunn Engine
//

#include "Application.h"
#include "Graphics/Window.h"
#include "ResourceManager.h"
#include "Time.h"
#include "Core.h"

namespace DunnEngine {

    Application* Application::s_Instance = nullptr;

	Application::Application()
	{
        Logger::Init();
        DE_CORE_ASSERT(!s_Instance, "Application already exists!");     // If there was an application class that was created before don't create a new one and assert
        LOG_CORE_INFO("DunnEngine instanstiated!");

        s_Instance = this;
	}

	Application::~Application()
	{
        ResourceManager::DeleteAllResources();
        Window::Shutdown();
	}

	void Application::Run()
	{
		OnInit();       // Call OnInit() outside of the main while loop to run it only once

        while (m_IsRunning)
        {
            Time start;             // the time since the frame started
            OnEvent();
            Time::Update();

            Window::ClearWindow();
            OnUpdate();
            Window::UpdateWindow();
            Time end;               // the time since the frame ended

            FPS = (float)1 / (start.GetElapsedTime() - end.GetElapsedTime()).asSeconds();       // 1 / frametime = FPS
        }

	}

    void Application::OnEvent()
    {
        sf::Event event;
        while (Window::PollEvents(event))
        {
            if (event.type == sf::Event::Closed)
                m_IsRunning = false;

            if (event.type == sf::Event::Resized)
                Window::Resize(event.size.width, event.size.height);

            if (event.type == sf::Event::EventType::TextEntered)
                OnKeyEvent(event);
            if (event.type == sf::Event::EventType::KeyPressed)
                OnKeyEvent(event);
            if (event.type == sf::Event::EventType::KeyReleased)
                OnKeyEvent(event);

            if (event.type == sf::Event::EventType::MouseMoved)
                OnMouseEvent(event);
            if (event.type == sf::Event::EventType::MouseButtonPressed)
                OnMouseEvent(event);
            if (event.type == sf::Event::EventType::MouseButtonReleased)
                OnMouseEvent(event);
            if (event.type == sf::Event::EventType::MouseWheelScrolled)
                OnMouseEvent(event);
            if (event.type == sf::Event::EventType::MouseWheelScrolled)
                OnMouseEvent(event);
            if (event.type == sf::Event::EventType::MouseEntered)
                OnMouseEvent(event);
            if (event.type == sf::Event::EventType::MouseLeft)
                OnMouseEvent(event);
        }
    }

}