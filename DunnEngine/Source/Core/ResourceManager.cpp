// Auther: Bavley Danial
// Date: 7/14/2023
//
// TDE - The Dunn Engine
//

#include "ResourceManager.h"

#include <sstream>
#include <fstream>

namespace DunnEngine {

	std::vector<DE_Texture*> ResourceManager::m_TextureBuffer;
	std::vector<DE_Sound*> ResourceManager::m_SoundBuffer;
	std::vector<DE_Font*> ResourceManager::m_FontBuffer;

	void ResourceManager::LoadTexture(const std::string& name, const std::string& path)
	{
		DE_CORE_ASSERT(!name.empty(), "Texture name is invalid!");
		DE_CORE_ASSERT(!path.empty(), "Texture Path is invalid!");
		DE_CORE_ASSERT(path.find(".png") != -1, "DunnEngine only supports .png files for textures for now!");

		DE_Texture* texture = new DE_Texture;  // holds a pointer to the new texture
		texture->Name = name;
		texture->Path = path;
		texture->Texture = new sf::Texture;
		bool status = texture->Texture->loadFromFile(path); // load the file and store the status to check later if it worked properly
		DE_CORE_ASSERT(status, "Could not load file\nName: " + texture->Name + "\nPath: " + texture->Path); // Stop program if status is false. This will be DELETED in release builds for performance reasons 

		m_TextureBuffer.push_back(texture);
		SortBuffer(Buffers::TextureBuffer, 0, m_TextureBuffer.size() - 1); // Sort the buffer supplying its type and first and last indicies
	}

	void ResourceManager::LoadFont(const std::string& name, const std::string& path)
	{
		DE_CORE_ASSERT(!name.empty(), "Font name is invalid!");
		DE_CORE_ASSERT(!path.empty(), "Font Path is invalid!");
		DE_CORE_ASSERT(path.find(".ttf") != -1, "DunnEngine only supports .ttf files for fonts for now!");

		DE_Font* font = new DE_Font;    // Holds a pointer to the new font
		font->Name = name;
		font->Path = path;
		font->Font = new sf::Font;
		bool status = font->Font->loadFromFile(path); // load the file and store the status to check later if it worked properly
		DE_CORE_ASSERT(status, "Could not load file\nName: " + font->Name + "\nPath: " + font->Path); // Stop program if status is false. This will be DELETED in release builds for performance reasons

		m_FontBuffer.push_back(font);
		SortBuffer(Buffers::FontBuffer, 0, m_FontBuffer.size() - 1); // Sort the buffer supplying its type and first and last indicies
	}

	void ResourceManager::LoadSound(const std::string& name, const std::string& path)
	{
		DE_CORE_ASSERT(!name.empty(), "Sound name is invalid!");
		DE_CORE_ASSERT(!path.empty(), "Sound Path is invalid!");
		DE_CORE_ASSERT(path.find(".wav") != -1, "DunnEngine only supports .wav files for sounds for now!");

		DE_Sound* sound = new DE_Sound;   // Holds a pointer to the new sound
		sound->Name = name;
		sound->Path = path;
		sound->Sound = new sf::SoundBuffer;
		bool status = sound->Sound->loadFromFile(path); // load the file and store the status to check later if it worked properly
		DE_CORE_ASSERT(status, "Could not load file\nName: " + sound->Name + "\nPath: " + sound->Path); // Stop program if status is false. This will be DELETED in release builds for performance reasons

		m_SoundBuffer.push_back(sound);
		SortBuffer(Buffers::SoundBuffer, 0, m_SoundBuffer.size() - 1); // Sort the buffer supplying its type and first and last indicies
	}

	void ResourceManager::LoadWithXML(const std::string& path)
	{
		DE_CORE_ASSERT(!path.empty(), "This XML path is invalid!");
		DE_CORE_ASSERT(path.find(".xml") != -1, "This DunnEngine feature only works with xml files!");		// If file is not an xml file then assert. This will be DELETED in release builds for performance reasons

		std::ifstream xmlFile;	// Holds the xmlFile provided
		xmlFile.open(path);
		DE_CORE_ASSERT(xmlFile.is_open(), "Could not open this XML file!");		// If file couldn't be opened properly assert. This will be DELETED in release builds for performance reasons 

		std::stringstream contents;	// Holds the string content of the file
		contents << xmlFile.rdbuf(); // reads the string from the file into the contents variable
		xmlFile.close();

		int textureOffset = contents.str().find("Textures");
		int fontOffset = contents.str().find("Fonts");
		int soundOffset = contents.str().find("Sounds");
		
		// Find all textures in the xml file and load them
		while (textureOffset != -1)
		{
			int nameStart = contents.str().find("name", textureOffset) + 5;	// find the start of the name of the texture

			std::string textureName;
			int offset = nameStart;
			// Iterate through until we meet the end of the name
			// in the xml file the names are defined by <name>the name</name> so finding the < after the name start indicates the end of the name
			while (contents.str()[offset] != '<')
			{
				textureName += contents.str()[offset];		// Add the character with this offset (from the nameStart) to the name
				offset++;
			}

			int locationStart = contents.str().find("location", textureOffset) + 9;	// find the start of the location of the texture

			std::string textureLocation;
			offset = locationStart;
			// Iterate through until we meet the end of the name
			// in the xml file the locations are defined by <location>the location</location> so finding the < after the location start indicates the end of the location
			while (contents.str()[offset] != '<')
			{
				textureLocation += contents.str()[offset];	// Add the character with this offset (from the locationStart) to the location
				offset++;
			}
			LoadTexture(textureName, textureLocation);
			textureOffset = contents.str().find("Textures", textureOffset + 9);		// Update the offset to not find the same Textures attribute
		}

		// Find all fonts in the xml file and load them
		while (fontOffset != -1)
		{
			int nameStart = contents.str().find("name", fontOffset) + 5; // find the start of the name of the font

			std::string fontName;
			int offset = nameStart;
			// Iterate through until we meet the end of the name
			// in the xml file the names are defined by <name>the name</name> so finding the < after the name start indicates the end of the name
			while (contents.str()[offset] != '<')
			{
				fontName += contents.str()[offset];		// Add the character with this offset (from the nameStart) to the name
				offset++;
			}

			int locationStart = contents.str().find("location", fontOffset) + 9; // find the start of the location of the font

			std::string fontLocation;
			offset = locationStart;
			// Iterate through until we meet the end of the name
			// in the xml file the locations are defined by <location>the location</location> so finding the < after the location start indicates the end of the location
			while (contents.str()[offset] != '<')
			{
				fontLocation += contents.str()[offset];	// Add the character with this offset (from the locationStart) to the location
				offset++;
			}
			LoadFont(fontName, fontLocation);
			fontOffset = contents.str().find("Fonts", fontOffset + 6);			// Update the offset to not find the same Fonts attribute
		}

		// Find all sounds in the xml file and load them
		while (soundOffset != -1)
		{
			int nameStart = contents.str().find("name", soundOffset) + 5; // find the start of the name of the sound

			std::string soundName;
			int offset = nameStart;
			// Iterate through until we meet the end of the name
			// in the xml file the names are defined by <name>the name</name> so finding the < after the name start indicates the end of the name
			while (contents.str()[offset] != '<')
			{
				soundName += contents.str()[offset];	// Add the character with this offset (from the nameStart) to the name
				offset++;
			}

			int locationStart = contents.str().find("location", soundOffset) + 9;	// find the start of the location of the sound

			std::string soundLocation;
			offset = locationStart;
			// Iterate through until we meet the end of the name
			// in the xml file the locations are defined by <location>the location</location> so finding the < after the location start indicates the end of the location
			while (contents.str()[offset] != '<')
			{
				soundLocation += contents.str()[offset]; // Add the character with this offset (from the locationStart) to the location
				offset++;
			}
			LoadSound(soundName, soundLocation);
			soundOffset = contents.str().find("Sounds", soundOffset + 8);			// Update the offset to not find the same Sounds attribute
		}
	}

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

				// Update the buffer elements with the new indicies representing their new slots in the buffer.
				if (lowIndex >= 0 && lowIndex < m_TextureBuffer.size())
					m_TextureBuffer[lowIndex]->index = lowIndex;
				if (rightIndex >= 0 && rightIndex < m_TextureBuffer.size())
					m_TextureBuffer[rightIndex]->index = rightIndex;
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

				// Update the buffer elements with the new indicies representing their new slots in the buffer.
				if (lowIndex >= 0 && lowIndex < m_SoundBuffer.size())
					m_SoundBuffer[lowIndex]->index = lowIndex;
				if (rightIndex >= 0 && rightIndex < m_SoundBuffer.size())
					m_SoundBuffer[rightIndex]->index = rightIndex;
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

				// Update the buffer elements with the new indicies representing their new slots in the buffer.
				if (lowIndex >= 0 && lowIndex < m_FontBuffer.size())
					m_FontBuffer[lowIndex]->index = lowIndex;
				if (rightIndex >= 0 && rightIndex < m_FontBuffer.size())
					m_FontBuffer[rightIndex]->index = rightIndex;
			}
			break;
		}
		default:
			LOG_CORE_ERROR("No buffer of this type has been found!"); // If the supplied buffer type is incorrect log an error
		}
	}

	DE_Texture* ResourceManager::GetTexture(const std::string& name, std::vector<DE_Texture*>& buffer)
	{
		int mid = buffer.size() / 2;

		// If there is only one element in the buffer check if it is the one we need and if so return it. Else log an error and return null.
		if (buffer.size() == 1)
		{
			if (buffer[0]->Name == name)
			{
				return buffer[0];
			}
			else
			{
				LOG_CORE_ERROR("Texture with name \"{0}\" not found!", name);
				return nullptr;
			}
		}

		// If the buffer is the middle term then return that.
		// If not then check if it is lower or higher than the needed element and check the lower or higher region respectively.
		if (buffer[mid]->Name == name)
			return buffer[mid];
		else if (buffer[mid]->Name[0] < name[0])
			return GetTexture(name, std::vector(buffer.begin() + mid, buffer.end()));
		else
			return GetTexture(name, std::vector(buffer.begin(), buffer.end() - mid));
	}

	DE_Font* ResourceManager::GetFont(const std::string& name, std::vector<DE_Font*>& buffer)
	{
		int mid = buffer.size() / 2;

		// If there is only one element in the buffer check if it is the one we need and if so return it. Else log an error and return null.
		if (buffer.size() == 1)
		{
			if (buffer[0]->Name == name)
			{
				return buffer[0];
			}
			else
			{
				LOG_CORE_ERROR("Font with name \"{0}\" not found!", name);
				return nullptr;
			}
		}

		// If the buffer is the middle term then return that.
		// If not then check if it is lower or higher than the needed element and check the lower or higher region respectively.
		if (buffer[mid]->Name == name)
			return buffer[mid];
		else if (buffer[mid]->Name[0] < name[0])
			return GetFont(name, std::vector(buffer.begin() + mid, buffer.end()));
		else
			return GetFont(name, std::vector(buffer.begin(), buffer.end() - mid));
	}

	DE_Sound* ResourceManager::GetSound(const std::string& name, std::vector<DE_Sound*>& buffer)
	{
		int mid = buffer.size() / 2;

		// If there is only one element in the buffer check if it is the one we need and if so return it. Else log an error and return null.
		if (buffer.size() == 1)
		{
			if (buffer[0]->Name == name)
			{
				return buffer[0];
			}
			else
			{
				LOG_CORE_ERROR("Sound with name \"{0}\" not found!", name);
				return nullptr;
			}
		}

		// If the buffer is the middle term then return that.
		// If not then check if it is lower or higher than the needed element and check the lower or higher region respectively.
		if (buffer[mid]->Name == name)
			return buffer[mid];
		else if (buffer[mid]->Name[0] < name[0])
			return GetSound(name, std::vector(buffer.begin() + mid, buffer.end()));
		else
			return GetSound(name, std::vector(buffer.begin(), buffer.end() - mid));
	}

	void ResourceManager::DeleteTexture(const std::string& name)
	{					
		DE_Texture* texture = GetTexture(name);
		if (!texture) // If texture not found return
		{
			LOG_CORE_ERROR("Texture with name \"{0}\" not found!", name);
			return;
		}
		m_TextureBuffer.erase(m_TextureBuffer.begin() + texture->index);
		delete texture->Texture;
		delete texture;
	}					
	void ResourceManager::DeleteFont(const std::string& name)
	{					
		DE_Font* font = GetFont(name);
		if (!font) // If texture not found return
		{
			LOG_CORE_ERROR("Font with name \"{0}\" not found!", name);
			return;
		}
		m_FontBuffer.erase(m_FontBuffer.begin() + font->index);
		delete font->Font;
		delete font;
	}					
	void ResourceManager::DeleteSound(const std::string& name)
	{					
		DE_Sound* sound = GetSound(name);
		if (!sound) // If texture not found return
		{
			LOG_CORE_ERROR("Sound with name \"{0}\" not found!", name);
			return;
		}
		m_SoundBuffer.erase(m_SoundBuffer.begin() + sound->index);
		delete sound->Sound;
		delete sound;
	}					
	void ResourceManager::DeleteAllResources()
	{
		// Loops through every texture in the texture buffer.
		for (int i = 0; i < m_TextureBuffer.size(); i++)
		{
			DE_Texture* texture = m_TextureBuffer[0];							// Get first texture in the buffer so that it can be deleted seperatly and not be lost.
			SortBuffer(Buffers::TextureBuffer, 0, m_TextureBuffer.size() - 1);  // Sort the buffer because buffer.erase() will change the order every iteration.
			m_TextureBuffer.erase(m_TextureBuffer.begin());
			delete texture->Texture;
			delete texture;
		}

		// Loops through every sound in the sound buffer.
		for (int i = 0; i < m_SoundBuffer.size(); i++)
		{
			DE_Sound* sound = m_SoundBuffer[0];									// Get first sound in the buffer so that it can be deleted seperatly and not be lost.
			SortBuffer(Buffers::SoundBuffer, 0, m_SoundBuffer.size() - 1);		// Sort the buffer because buffer.erase() will change the order every iteration.
			m_SoundBuffer.erase(m_SoundBuffer.begin());
			delete sound->Sound;
			delete sound;
		}

		// Loops through every font in the font buffer.
		for (int i = 0; i < m_FontBuffer.size(); i++)
		{
			DE_Font* font = m_FontBuffer[0];									// Get first font in the buffer so that it can be deleted seperatly and not be lost.
			SortBuffer(Buffers::FontBuffer, 0, m_FontBuffer.size() - 1);		// Sort the buffer because buffer.erase() will change the order every iteration.
			m_FontBuffer.erase(m_FontBuffer.begin());
			delete font->Font;
			delete font;
		}
	}

}