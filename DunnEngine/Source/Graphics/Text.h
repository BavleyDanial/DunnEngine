#pragma once

#include <glm/glm.hpp>
#include <SFML/Graphics.hpp>
#include "Core/ResourceManager.h"

/// <summary>
/// 
/// This file includes the Text Class. This class should be used to create texts objects.
/// This class can set a string to be rendered, set a font, set a font size, set a style, set a smoothing look on the text.
/// From the engine side it can also set position, set rotation, set a scale.
/// These are protected methods that can only be accessed by graphics class.
/// 
/// </summary>

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
		//--------------------------------- CLIENT SIDE FUNCTIONS ---------------------------------\\

		// Constructs the class and can be used to create a string with it. If not provided the string is empty
		Text(const std::string& textString = "");
		// Deletes any heap allocated variables/objects
		~Text();

		// Set the string -that will be used to render- with the provided data
		void SetString(const std::string& textString);
		// Set the font -that will be used to render- with the provided data
		// It also can set a size if the data was provided. If not the default is 30
		void SetFont(DE_Font* font, uint32_t fontSize = 30);
		// Set the font size -that will be used to render- with the provided data
		void SetFontSize(uint32_t fontSize);
		// Set the text style -that will be used to render- with the provided data
		void SetStyle(FontStyle fontStyle);
		// Set the smoothing of the text on or off
		void SetSmoothing(bool enabled);
	protected:
		//--------------------------------- ENGINE SIDE FUNCTIONS ---------------------------------\\
		
		// Set the position of the text
		void SetPosition(const glm::vec2& position);
		// Set the rotation of the text
		void SetRotation(float rotationAngle);
		// Set the scale of the text
		void SetScale(const glm::vec2& scale);

		// Get the sfml text if needed. It should not be called unless absolutly needed.
		const sf::Text* GetSfmlText() { return m_SfmlText; }
	private:
		sf::Text* m_SfmlText = nullptr;		// Holds a pointer to the sfml text
		DE_Font* m_Font = nullptr;			// Holds a pointer to the font being used
	private:
		friend class Graphics;		// friends the Graphics class so that it can use the Text's protected methods.
	};
}