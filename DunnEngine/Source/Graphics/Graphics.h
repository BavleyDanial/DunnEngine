#pragma once

#include <glm/glm.hpp>

#include "Core/ResourceManager.h"
#include "Text.h"

namespace DunnEngine {

	class Graphics
	{
	public:
		static void DrawQuad(const glm::vec2& position, float rotationAngle, const glm::vec2& scale, const glm::vec4& color);
		static void DrawCircle(const glm::vec2& position, const glm::vec2& scale, const glm::vec4& color);
		static void DrawTriangle(const glm::vec2& position, float rotationAngle, const glm::vec2& scale, const glm::vec4& color);
		static void DrawSprite(DE_Texture* texture, const glm::vec2& position, float rotationAngle, const glm::vec2& scale);
		static void Print(Text& text, const glm::vec2& position, float rotationAngle, const glm::vec2& scale);
	};

}