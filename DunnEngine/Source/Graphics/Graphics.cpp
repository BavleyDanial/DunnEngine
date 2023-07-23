#include "Graphics.h"

#include "Window.h"

namespace DunnEngine {

	void Graphics::DrawQuad(const glm::vec2& position, float rotationAngle, const glm::vec2& scale, const glm::vec4& color)
	{
		sf::RectangleShape quad;
		quad.setSize({ 1, 1 });
		quad.setFillColor(sf::Color(color.r, color.g, color.b, color.a));
		quad.setOrigin(quad.getSize().x / 2, quad.getSize().y / 2);							// This is done because sfml by default uses the top left of a sprite as the origin not the center of the sprite.
		quad.setPosition(position.x, Window::GetHeight() - position.y);						// The position is relative to the top left of the window, meaning the coordinates of the top left is (0, 0) and buttom right is (window.width, window.height)
		quad.setScale(scale.x, scale.y);
		quad.setRotation(rotationAngle);

		Window::GetSFMLWindow()->draw(quad);
	}
	void Graphics::DrawCircle(const glm::vec2& position, const glm::vec2& scale, const glm::vec4& color)
	{
		sf::CircleShape circle;
		circle.setPointCount(200);
		circle.setRadius(0.5f);
		circle.setFillColor(sf::Color(color.r, color.g, color.b, color.a));
		circle.setOrigin(circle.getLocalBounds().getSize().x / 2, circle.getLocalBounds().getSize().x / 2); // This is done because sfml by default uses the top left of a sprite as the origin not the center of the sprite.
		circle.setPosition(position.x, Window::GetHeight() - position.y);						// The position is relative to the top left of the window, meaning the coordinates of the top left is (0, 0) and buttom right is (window.width, window.height)
		circle.setScale(scale.x, scale.y);

		Window::GetSFMLWindow()->draw(circle);
	}
	void Graphics::DrawTriangle(const glm::vec2& position, float rotationAngle, const glm::vec2& scale, const glm::vec4& color)
	{
		sf::CircleShape triangle;
		triangle.setPointCount(3);
		triangle.setRadius(1.0f);
		triangle.setFillColor(sf::Color(color.r, color.g, color.b, color.a));
		triangle.setOrigin(triangle.getLocalBounds().getSize().x / 2, triangle.getLocalBounds().getSize().y / 2); // This is done because sfml by default uses the top left of a sprite as the origin not the center of the sprite.
		triangle.setPosition(position.x, Window::GetHeight() - position.y);						// The position is relative to the top left of the window, meaning the coordinates of the top left is (0, 0) and buttom right is (window.width, window.height)
		triangle.setRotation(rotationAngle);
		triangle.setScale(scale.x, scale.y);

		Window::GetSFMLWindow()->draw(triangle);
	}
	void Graphics::DrawSprite(DE_Texture* texture, const glm::vec2& position, float rotationAngle, const glm::vec2& scale)
	{
		sf::Sprite sprite;
		sprite.setTexture(*texture->Texture);
		sprite.setOrigin(texture->Texture->getSize().x / 2, texture->Texture->getSize().y / 2); // This is done because sfml by default uses the top left of a sprite as the origin not the center of the sprite.
		sprite.setPosition(position.x, Window::GetHeight() - position.y);						// The position is relative to the top left of the window, meaning the coordinates of the top left is (0, 0) and buttom right is (window.width, window.height)
		sprite.setRotation(rotationAngle);
		sprite.setScale(scale.x, scale.y);
		
		Window::GetSFMLWindow()->draw(sprite);
	}
	void Graphics::Print(Text& text, const glm::vec2& position, float rotationAngle, const glm::vec2& scale)
	{
		text.SetPosition({ position.x, Window::GetHeight() - position.y });
		text.SetRotation(rotationAngle);
		text.SetScale(scale);

		Window::GetSFMLWindow()->draw(*text.GetSfmlText());
	}
}

