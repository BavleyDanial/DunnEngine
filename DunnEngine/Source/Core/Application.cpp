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
            OnEvent();

            Window::ClearWindow();
            OnUpdate();
            Window::UpdateWindow();

            Time::Update();
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