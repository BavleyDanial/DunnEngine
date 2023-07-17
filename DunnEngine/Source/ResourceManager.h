#pragma once

// Auther: Bavley Danial
// Date: 7/14/2023
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

#include <vector>

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "Core.h"

namespace DunnEngine {

	enum class Buffers // Holds all buffer types
	{
		Unkown = 0,
		TextureBuffer,
		SoundBuffer,
		FontBuffer
	};

	struct DE_Texture // Holds the definition of a texture
	{
		std::string Name = "";  // The name of the texture
		std::string Path = "";	// The path where the texture exists. This is reserved for debugging.
		sf::Texture Texture;	// The actual sfml texture
	};
	struct DE_Sound // Holds the definition of a sound
	{
		std::string Name = "";  // The name of the font
		std::string Path = "";	// The path where the font exists. This is reserved for debugging.
		sf::SoundBuffer Sound;	// The actual sfml font
	};
	struct DE_Font // Holds the definition of a font
	{
		std::string Name = "";  // The name of the texture
		std::string Path = "";  // The path where the texture exists. This is reserved for debugging.
		sf::Font Font;			// The actual sfml texture
	};

	class ResourceManager
	{
	public:
		// The next set of functions are used to load textures, fonts, audio, and potentially other stuff.
		// They load them into their right buffers and sorts them.
		static void LoadTexture(const std::string& name, const std::string& path);
		static void LoadFont(const std::string& name, const std::string& path);
		static void LoadAudio(const std::string& name, const std::string& path);
		
		// These set of functions are used to retrieve the textures, fonts, audio and potentially other stuff that were loaded in memory previously.
		// They retrieve them by searching in the buffers using Binary search. This is used because it is faster than Linear search especially 
		// when there are hundreds of resources that are loaded in memory.
		static sf::Texture& GetTexture(const std::string& name, std::vector<DE_Texture*>& buffer = m_TextureBuffer);
		static sf::Font& GetFont(const std::string& name, std::vector<DE_Font*>& buffer = m_FontBuffer);
		static sf::SoundBuffer& GetSound(const std::string& name, std::vector<DE_Sound*>& buffer = m_SoundBuffer);
	private:
		// This function sorts the buffers using QuickSort. This is done because it is faster than other methods like selection sort especially
		// especially when there are hundreds of resources that are loaded in memory.
		static void SortBuffer(Buffers bufferType, int leftIndex, int rightIndex);
	private:
		static std::vector<DE_Texture*> m_TextureBuffer; // Holds loaded textures
		static std::vector<DE_Sound*> m_SoundBuffer;	 // Holds loaded sounds
		static std::vector<DE_Font*> m_FontBuffer;		 // Holds loaded fonts
	};

}