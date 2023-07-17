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

#include "Application.h"

#include <SFML/Graphics.hpp>
#include <glm/glm.hpp>
#include "ResourceManager.h"
#include "Logger.h"
#include "Input.h"
#include "KeyCodes.h"
#include "MouseButtonCodes.h"

#include "Core.h"

namespace DunnEngine {

    Application* Application::s_Instance = nullptr;

	Application::Application()
	{
        Logger::Init();
        DE_CORE_ASSERT(!s_Instance, "Application already exists!");
        LOG_CORE_INFO("DunnEngine instanstiated!");
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

        //--Testing multiple files loading and sorting--//
        ResourceManager::LoadTexture("TextureTest", "Resources/TestTexture.png");
        // ResourceManager::LoadTexture("ATest", "Resources/TestTexture.png");
        // ResourceManager::LoadTexture("ZTest", "Resources/TestTexture.png");
        // ResourceManager::LoadTexture("FTest", "Resources/TestTexture.png");
        // ResourceManager::LoadTexture("ATest2", "Resources/TestTexture.png");
        // 
        ResourceManager::LoadAudio("AudioTest", "Resources/TestAudio.wav");
        // ResourceManager::LoadAudio("BAudioTest", "Resources/TestAudio.wav");
        // ResourceManager::LoadAudio("WAudioTest", "Resources/TestAudio.wav");
        // ResourceManager::LoadAudio("FAudioTest", "Resources/TestAudio.wav");
        // ResourceManager::LoadAudio("DAudioTest", "Resources/TestAudio.wav");
        // 
        // ResourceManager::LoadAudio("FontTest", "Resources/TestAudio.wav");
        // ResourceManager::LoadAudio("BFontTest", "Resources/TestAudio.wav");
        // ResourceManager::LoadAudio("WFontTest", "Resources/TestAudio.wav");
        // ResourceManager::LoadAudio("FFontTest", "Resources/TestAudio.wav");
        // ResourceManager::LoadAudio("DFontTest", "Resources/TestAudio.wav");

        //--Sfml testing stuff--//
        sf::Texture texture;
        sf::Sprite sprite;
        sf::Sound sound;
        sound.setBuffer(ResourceManager::GetSound("AudioTest"));
        sprite.setTexture(ResourceManager::GetTexture("TextureTest"));
        //texture.loadFromFile("Resources/Test.png");
        sprite.setPosition(m_Window->GetSFMLWindow()->getSize().x / 2, m_Window->GetSFMLWindow()->getSize().y / 2);

        while (m_IsRunning)
        {
            sf::Event event;
            while (m_Window->PollEvents(event))
            {
                if (event.type == sf::Event::Closed)
                {
                    m_Window->GetSFMLWindow()->close();
                    m_IsRunning = false;
                }

                if (Input::IsKeyPressed(TDE_KEY_F))
                    sound.play();

                if (event.type == sf::Event::Resized)
                {
                    // update the view to the new size of the window
                    sf::FloatRect visibleArea(0, 0, event.size.width, event.size.height);
                    m_Window->GetSFMLWindow()->setView(sf::View(visibleArea));
                }
                shape.setPosition(m_Window->GetSFMLWindow()->getSize().x / 2, m_Window->GetSFMLWindow()->getSize().y / 2);

            }

            OnUpdate();

            m_Window->ClearWindow();

            //--Test using SFML draw commands--//
            //m_Window->GetSFMLWindow()->draw(sprite);
            //m_Window->GetSFMLWindow()->draw(shape);

            m_Window->UpdateWindow();
        }
	}

}