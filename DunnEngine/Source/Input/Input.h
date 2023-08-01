#pragma once

// Auther: Bavley Danial
// Date: 7/11/2023
//
// TDE - The Dunn Engine
//

/// <summary>
/// 
/// This file includes the Input Class. This class is responsible for managing all inputs.
/// This class can. detect key presses, mouse button presses, getting mouse position and setting the mouse position.
/// This class can not be instantiated as an object as there is only one instance of it.
/// 
/// </summary>

#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Mouse.hpp>

#include <glm/glm.hpp>

namespace DunnEngine {

	class Input
	{
	public:
		//--------------------------------- COMMON FUNCTIONS ---------------------------------\\

		// Get the status of the provided key
		static bool IsKeyPressed(int key)
		{
			DE_CORE_ASSERT(!(key < 0 || key > 100), "Unkown key, this key is not in the range of supported keys");
			return sf::Keyboard::isKeyPressed((sf::Keyboard::Key) key);
		}
		// Get the status of the provided mouse button
		static bool IsMouseButtonPressed(int button)
		{
			DE_CORE_ASSERT(!(button < 0 || button > 4), "Unkown mouse button, this key is not in the range of supported buttons");
			return sf::Mouse::isButtonPressed((sf::Mouse::Button) button);
		}
		// Get the current position of the mouse cursor relative to the screen
		static glm::vec2 GetMousePosition()
		{
			return { (float)sf::Mouse::getPosition().x, Window::GetHeight() - (float)sf::Mouse::getPosition().y };
		}
		// Set the mouse position to a specific pixel
		static void SetMousePoisiton(float x, float y)
		{
			sf::Mouse::setPosition(sf::Vector2i(x, Window::GetHeight() - y));
		}
	};

}