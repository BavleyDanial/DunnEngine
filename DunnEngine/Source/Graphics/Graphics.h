#pragma once

/// <summary>
/// 
/// This file includes the Graphics class. This class manages all the rendering happening on the screen
/// This class can draw quads (rectangles/squares), circles, triangles, sprites, and texts.
/// This class can not be instantiated as an object as there is only one instance of it.
/// 
/// </summary>

#include <glm/glm.hpp>

#include "Core/ResourceManager.h"
#include "Text.h"

namespace DunnEngine {

	class Graphics
	{
	public:
		//--------------------------------- CLIENT SIDE FUNCTIONS ---------------------------------\\

		// Draw a quad with the specified position, rotation, scale, color
		// For now a quad can only be a square or a rectangle but for other shapes you could use DrawSprite instead
		static void DrawQuad(const glm::vec2& position, float rotationAngle, const glm::vec2& scale, const glm::vec4& color);
		// Draw a circle with the specified position, rotation, scale, color
		static void DrawCircle(const glm::vec2& position, const glm::vec2& scale, const glm::vec4& color);
		// Draw a triangle with the specified position, rotation, scale, color
		static void DrawTriangle(const glm::vec2& position, float rotationAngle, const glm::vec2& scale, const glm::vec4& color);
		// Draw a sprite with the specified position, rotation, scale, color
		static void DrawSprite(DE_Texture* texture, const glm::vec2& position, float rotationAngle, const glm::vec2& scale);
		// Draw a text with the specified position, rotation, scale, color
		// Unfortuntely it wasn't possible to use DrawText as the name as it was defined by an external library. Possible solutions might come up in the future
		static void Print(Text& text, const glm::vec2& position, float rotationAngle, const glm::vec2& scale);
	};

}