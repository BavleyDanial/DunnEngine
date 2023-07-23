#include "Text.h"

namespace DunnEngine {

	Text::Text(const std::string& textString)
	{
		m_SfmlText = new sf::Text;
		m_SfmlText->setString(textString);
		m_SfmlText->setOrigin(m_SfmlText->getLocalBounds().getSize().x / 2, m_SfmlText->getLocalBounds().getSize().y / 2);
	}

	Text::~Text()
	{
		delete m_SfmlText;
	}

	void Text::SetString(const std::string& string)
	{
		m_SfmlText->setString(string);
		m_SfmlText->setOrigin(m_SfmlText->getLocalBounds().getSize().x / 2, m_SfmlText->getLocalBounds().getSize().y / 2);
	}
	void Text::SetFont(const DE_Font* font, uint32_t fontSize)
	{
		m_SfmlText->setFont(*font->Font);
		m_SfmlText->setCharacterSize(fontSize);
		m_SfmlText->setOrigin(m_SfmlText->getLocalBounds().getSize().x / 2, m_SfmlText->getLocalBounds().getSize().y / 2);
	}
	void Text::SetFontSize(uint32_t fontSize)
	{
		m_SfmlText->setCharacterSize(fontSize);
		m_SfmlText->setOrigin(m_SfmlText->getLocalBounds().getSize().x / 2, m_SfmlText->getLocalBounds().getSize().y / 2);
	}
	void Text::SetStyle(FontStyle fontStyle)
	{
		m_SfmlText->setStyle((uint32_t) fontStyle);
		m_SfmlText->setOrigin(m_SfmlText->getLocalBounds().getSize().x / 2, m_SfmlText->getLocalBounds().getSize().y / 2);
	}
	void Text::SetSmoothing(bool enabled)
	{
		sf::Font font = *m_SfmlText->getFont();
		font.setSmooth(enabled);
		m_SfmlText->setFont(font);
		m_SfmlText->setOrigin(m_SfmlText->getLocalBounds().getSize().x / 2, m_SfmlText->getLocalBounds().getSize().y / 2);
	}
	void Text::SetPosition(const glm::vec2& position)
	{
		m_SfmlText->setPosition(position.x, position.y);
	}	 
	void Text::SetRotation(float rotationAngle)
	{	 
		m_SfmlText->setRotation(rotationAngle);
	}	 
	void Text::SetScale(const glm::vec2& scale)
	{
		m_SfmlText->setScale(scale.x, scale.y);
	}
		
}