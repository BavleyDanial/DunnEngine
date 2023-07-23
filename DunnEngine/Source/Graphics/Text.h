#pragma once

#include <glm/glm.hpp>
#include <SFML/Graphics.hpp>
#include "Core/ResourceManager.h"

namespace DunnEngine {

	enum class FontStyle
	{
		// This is done this way so that it matches the sfml numbering scheme
		Regular = 0, Bold = 1 << 0, Italic = 1 << 1, Underlined = 1 << 2,
		StrikeThrough = 1 << 3
	};

	class Text
	{
	public:
		Text(const std::string& textString = "");
		~Text();

		void SetString(const std::string& textString);
		void SetFont(const DE_Font* font, uint32_t fontSize = 30);
		void SetFontSize(uint32_t fontSize);
		void SetStyle(FontStyle fontStyle);
		void SetSmoothing(bool enabled);
	protected:
		void SetPosition(const glm::vec2& position);
		void SetRotation(float rotationAngle);
		void SetScale(const glm::vec2& scale);

		const sf::Text* GetSfmlText() { return m_SfmlText; }
	private:
		sf::Text* m_SfmlText;
	private:
		friend class Graphics;
	};
}