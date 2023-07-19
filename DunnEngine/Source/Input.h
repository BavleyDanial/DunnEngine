#pragma once

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


#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Mouse.hpp>

#include <glm/glm.hpp>

namespace DunnEngine {

	class Input
	{
	public:
		static bool IsKeyPressed(int key)
		{
			return sf::Keyboard::isKeyPressed((sf::Keyboard::Scancode) key);
		}
		static bool IsMouseButtonPressed(int button)
		{
			return sf::Mouse::isButtonPressed((sf::Mouse::Button) button);
		}
		static glm::vec2 GetMousePosition()
		{
			return { (float)sf::Mouse::getPosition().x, (float)sf::Mouse::getPosition().y };
		}
		static void SetMousePoisiton(float x, float y)
		{
			sf::Mouse::setPosition(sf::Vector2i(x, y));
		}
		static void SetMousePoisiton(float x, float y, const sf::WindowBase& relativeWindow)
		{
			sf::Mouse::setPosition(sf::Vector2i(x, y), relativeWindow);
		}
	};

}