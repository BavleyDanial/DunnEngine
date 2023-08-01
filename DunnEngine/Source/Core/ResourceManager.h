#pragma once

// Auther: Bavley Danial
// Date: 7/14/2023
//
// TDE - The Dunn Engine
//

/// <summary>
/// 
/// This file includes the ResourceManager class. This class is responsible for loading assets into memory
/// This class can load textures, load sounds, load fonts, get textures, get sounds, get fonts, delete each of them individually and delete them all at once
/// This class can not be instantiated as an object as there is only one instance of it.
/// 
/// </summary>

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
		std::string Name = "";				// The name of the texture
		std::string Path = "";				// The path where the texture exists. This is reserved for debugging.
		int index = 0;
		sf::Texture* Texture = nullptr;		// The actual sfml texture
	};
	struct DE_Sound // Holds the definition of a sound
	{
		std::string Name = "";				// The name of the font
		std::string Path = "";				// The path where the font exists. This is reserved for debugging.
		int index = 0;
		sf::SoundBuffer* Sound = nullptr;	// The actual sfml font
	};
	struct DE_Font // Holds the definition of a font
	{
		std::string Name = "";				// The name of the texture
		std::string Path = "";				// The path where the texture exists. This is reserved for debugging.
		int index = 0;
		sf::Font* Font = nullptr;			// The actual sfml texture
	};

	class ResourceManager
	{
	public:
		//--------------------------------- COMMON FUNCTIONS ---------------------------------\\

		// Loads the texture into memory for use later (When drawing a sprite for example). The path is relative to the DunnSandbox(Or equivilent) folder.
		// It loads the texture and then sorts it using QuickSort. Therefore it is not recommended to call this function in OnUpdate() and instead use it in OnInit() for performance reasons
		static void LoadTexture(const std::string& name, const std::string& path);
		// Loads the font into memory for use later (When drawing a sprite for example). The path is relative to the DunnSandbox(Or equivilent) folder.
		// It loads the font and then sorts it using QuickSort. Therefore it is not recommended to call this function in OnUpdate() and instead use it in OnInit() for performance reasons
		static void LoadFont(const std::string& name, const std::string& path);
		// Loads the sound into memory for use later (When drawing a sprite for example). The path is relative to the DunnSandbox(Or equivilent) folder.
		// It loads the sound and then sorts it using QuickSort. Therefore it is not recommended to call this function in OnUpdate() and instead use it in OnInit() for performance reasons
		static void LoadSound(const std::string& name, const std::string& path);

		// Returns a pointer to the texture using its name. It uses a binary search approach.
		// It will do an assert in the case that no texture with that name was found.
		static DE_Texture* GetTexture(const std::string& name, std::vector<DE_Texture*>& buffer = m_TextureBuffer);
		// Returns a pointer to the font using its name. It uses a binary search approach.
		// It will do an assert in the case that no font with that name was found.
		static DE_Font* GetFont(const std::string& name, std::vector<DE_Font*>& buffer = m_FontBuffer);
		// Returns a pointer to the sound using its name. It uses a binary search approach.
		// It will do an assert in the case that no sound with that name was found.
		static DE_Sound* GetSound(const std::string& name, std::vector<DE_Sound*>& buffer = m_SoundBuffer);

		// Deletes the texture with the name provided.
		// It will assert if no texture with that name was found.
		static void DeleteTexture(const std::string& name);
		// Deletes the font with the name provided.
		// It will assert if no font with that name was found.
		static void DeleteFont(const std::string& name);
		// Deletes the sound with the name provided.
		// It will assert if no sound with that name was found.
		static void DeleteSound(const std::string& name);
		// Deletes all resources (this includes textures, sounds, and fonts) form memory.
		// This is used if needed to transition to a different level with different assets or needed to load different quality assets if needed to change that dynamically
		static void DeleteAllResources();
	private:
		// This function sorts the buffers using QuickSort.
		// This is done to ensure maximum efficiency when retrieving any type of asset.
		static void SortBuffer(Buffers bufferType, int leftIndex, int rightIndex);
	private:
		static std::vector<DE_Texture*> m_TextureBuffer; // Holds loaded textures
		static std::vector<DE_Sound*> m_SoundBuffer;	 // Holds loaded sounds
		static std::vector<DE_Font*> m_FontBuffer;		 // Holds loaded fonts
	};

}