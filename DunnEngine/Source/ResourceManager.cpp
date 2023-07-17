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

#include "ResourceManager.h"

namespace DunnEngine {

	std::vector<DE_Texture*> ResourceManager::m_TextureBuffer;
	std::vector<DE_Sound*> ResourceManager::m_SoundBuffer;
	std::vector<DE_Font*> ResourceManager::m_FontBuffer;

	/* Will be better to implement it as a templated function instead of making multiple versions of it with different resources */
	void ResourceManager::LoadTexture(const std::string& name, const std::string& path)
	{
		DE_Texture* texture = new DE_Texture;
		texture->Name = name;
		texture->Path = path;
		bool status = texture->Texture.loadFromFile(path); // load the file and store the status to check later if it worked properly
		DE_CORE_ASSERT(status, "Could not load file\nName: " + texture->Name + "\nPath: " + texture->Path); // Stop program if status is false. This will be DELETED in release builds for performance reasons 

		m_TextureBuffer.push_back(texture);
		SortBuffer(Buffers::TextureBuffer, 0, m_TextureBuffer.size() - 1); // Sort the buffer supplying its type and first and last indicies
	}

	/* Will be better to implement it as a templated function instead of making multiple versions of it with different resources */
	void ResourceManager::LoadFont(const std::string& name, const std::string& path)
	{
		DE_Font* font = new DE_Font;
		font->Name = name;
		font->Path = path;
		bool status = font->Font.loadFromFile(path); // load the file and store the status to check later if it worked properly
		DE_CORE_ASSERT(status, "Could not load file\nName: " + font->Name + "\nPath: " + font->Path); // Stop program if status is false. This will be DELETED in release builds for performance reasons

		m_FontBuffer.push_back(font);
		SortBuffer(Buffers::FontBuffer, 0, m_FontBuffer.size() - 1); // Sort the buffer supplying its type and first and last indicies
	}

	/* Will be better to implement it as a templated function instead of making multiple versions of it with different resources */
	void ResourceManager::LoadAudio(const std::string& name, const std::string& path)
	{
		DE_Sound* sound = new DE_Sound;
		sound->Name = name;
		sound->Path = path;
		bool status = sound->Sound.loadFromFile(path); // load the file and store the status to check later if it worked properly
		DE_CORE_ASSERT(status, "Could not load file\nName: " + sound->Name + "\nPath: " + sound->Path); // Stop program if status is false. This will be DELETED in release builds for performance reasons

		m_SoundBuffer.push_back(sound);
		SortBuffer(Buffers::SoundBuffer, 0, m_SoundBuffer.size() - 1); // Sort the buffer supplying its type and first and last indicies
	}

	/* Will be better to implement it as a templated function instead of making checks for what buffer to sort everytime it is called */
	void ResourceManager::SortBuffer(Buffers bufferType, int leftIndex, int rightIndex)
	{
		switch (bufferType)
		{
		case Buffers::TextureBuffer:
		{
			if (leftIndex < rightIndex)
			{
				std::string pivot = m_TextureBuffer[rightIndex]->Name;
				int lowIndex = leftIndex;

				// Loop through each file in the buffer within the left index and right index
				for (int i = leftIndex; i <= rightIndex; i++)
				{
					// If the first character in the pivot we chose is higher than the first character in the current file's name then swap them
					if (m_TextureBuffer[i]->Name[0] > pivot[0])
					{
						DE_Texture* tmp = m_TextureBuffer[i];
						m_TextureBuffer[i] = m_TextureBuffer[rightIndex];
						m_TextureBuffer[rightIndex] = tmp;
						lowIndex++;
					}
				}

				SortBuffer(Buffers::TextureBuffer, leftIndex, lowIndex - 1);  // Sort lower part
				SortBuffer(Buffers::TextureBuffer, lowIndex + 1, rightIndex); // Sort higher part
			}
			break;
		}
		case Buffers::SoundBuffer:
		{
			if (leftIndex < rightIndex)
			{
				std::string pivot = m_SoundBuffer[rightIndex]->Name;
				int lowIndex = leftIndex;

				// Loop through each file in the buffer within the left index and right index
				for (int i = leftIndex; i <= rightIndex; i++)
				{
					// If the first character in the pivot we chose is higher than the first character in the current file's name then swap them
					if (m_SoundBuffer[i]->Name[0] > pivot[0])
					{
						DE_Sound* tmp = m_SoundBuffer[i];
						m_SoundBuffer[i] = m_SoundBuffer[rightIndex];
						m_SoundBuffer[rightIndex] = tmp;
						lowIndex++;
					}
				}

				SortBuffer(Buffers::SoundBuffer, leftIndex, lowIndex - 1);  // Sort lower part
				SortBuffer(Buffers::SoundBuffer, lowIndex + 1, rightIndex); // Sort higher part
			}
			break;
		}
		case Buffers::FontBuffer:
		{
			if (leftIndex < rightIndex)
			{
				std::string pivot = m_FontBuffer[rightIndex]->Name;
				int lowIndex = leftIndex;

				// Loop through each file in the buffer within the left index and right index
				for (int i = leftIndex; i <= rightIndex; i++)
				{
					// If the first character in the pivot we chose is higher than the first character in the current file's name then swap them
					if (m_FontBuffer[i]->Name[0] > pivot[0])
					{
						DE_Font* tmp = m_FontBuffer[i];
						m_FontBuffer[i] = m_FontBuffer[rightIndex];
						m_FontBuffer[rightIndex] = tmp;
						lowIndex++;
					}
				}

				SortBuffer(Buffers::FontBuffer, leftIndex, lowIndex - 1);  // Sort lower part
				SortBuffer(Buffers::FontBuffer, lowIndex + 1, rightIndex); // Sort higher part
			}
			break;
		}
		default:
			LOG_CORE_ERROR("No buffer of this type has been found!"); // If the supplied buffer type is incorrect log an error
		}
	}

	/* Will be better to implement it as a templated function instead of making multiple versions of it with different resources */
	sf::Texture& ResourceManager::GetTexture(const std::string& name, std::vector<DE_Texture*>& buffer)
	{
		int mid = buffer.size() / 2;

		// If there is only one element in the buffer check if it is the one we need and if so return it. Else log an error.
		if (buffer.size() == 1)
		{
			if (buffer[0]->Name == name)
				return buffer[0]->Texture;
			else
				LOG_CORE_ERROR("Texture not found!");
		}

		// If the buffer is the middle term then return that.
		// If not then check if it is lower or higher than the needed element and check the lower or higher region respectively.
		if (buffer[mid]->Name == name)
			return buffer[mid]->Texture;
		else if (buffer[mid]->Name[0] < name[0])
			return GetTexture(name, std::vector(buffer.begin() + mid, buffer.end()));
		else
			return GetTexture(name, std::vector(buffer.begin(), buffer.end() - mid));
	}

	/* Will be better to implement it as a templated function instead of making multiple versions of it with different resources */
	sf::Font& ResourceManager::GetFont(const std::string& name, std::vector<DE_Font*>& buffer)
	{
		int mid = buffer.size() / 2;

		// If there is only one element in the buffer check if it is the one we need and if so return it. Else log an error.
		if (buffer.size() == 1)
		{
			if (buffer[0]->Name == name)
				return buffer[0]->Font;
			else
				LOG_CORE_ERROR("Font not found!");
		}

		// If the buffer is the middle term then return that. If not then check if it is lower or higher than the needed element and check the lower or higher region respectively.
		if (buffer[mid]->Name == name)
			return buffer[mid]->Font;
		else if (buffer[mid]->Name[0] < name[0])
			return GetFont(name, std::vector(buffer.begin() + mid, buffer.end()));
		else
			return GetFont(name, std::vector(buffer.begin(), buffer.end() - mid));
	}
	/* Will be better to implement it as a templated function instead of making multiple versions of it with different resources */
	sf::SoundBuffer& ResourceManager::GetSound(const std::string& name, std::vector<DE_Sound*>& buffer)
	{
		int mid = buffer.size() / 2;

		// If there is only one element in the buffer check if it is the one we need and if so return it. Else log an error.
		if (buffer.size() == 1)
		{
			if (buffer[0]->Name == name)
				return buffer[0]->Sound;
			else
				LOG_CORE_ERROR("Sound not found!");
		}

		// If the buffer is the middle term then return that. If not then check if it is lower or higher than the needed element and check the lower or higher region respectively.
		if (buffer[mid]->Name == name)
			return buffer[mid]->Sound;
		else if (buffer[mid]->Name[0] < name[0])
			return GetSound(name, std::vector(buffer.begin() + mid, buffer.end()));
		else
			return GetSound(name, std::vector(buffer.begin(), buffer.end() - mid));
	}

}