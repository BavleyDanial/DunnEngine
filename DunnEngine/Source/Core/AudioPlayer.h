#pragma once

/// <summary>
/// 
/// This file includes the SoundPlayer class. This class manages the playing, stopping, pausing and other functionalities of sounds.
/// It can Set a sound to be played, pause it, stop it, set a playing offset, set a pitch, set a volume, set a loop, and get a duration of the currently set sound.
/// 
/// </summary>

#include <SFML/Audio.hpp>

#include "ResourceManager.h"
#include "Time.h"

namespace DunnEngine {
	
	class SoundPlayer
	{
	public:
		//--------------------------------- COMMON FUNCTIONS ---------------------------------\\

		// Set the sound object to be played.
		void SetSound(DE_Sound* sound);
		// Play the sound that was set before.
		// If there was not a sound object set before that it will do an assert.
		// When called it will play and won't allow itself to play again in the next frame if it has not finished yet.
		void Play();
		// Pauses the sound that was set before.
		// If there was not a sound object set before that it will do an assert.
		void Pause();
		// Stops the sound that was set before.
		// If there was not a sound object set before that it will do an assert.
		void Stop();
		// Set when in the track provided should the soundplayer start at.
		// If there was not a sound object set before that it will do an assert.
		void SetPlayOffset(Time timeOffset);
		// Set the pitch of the sound object provided.
		// If there was not a sound object set before that it will do an assert.
		void SetPitch(float pitchValue);
		// Set the volume of the sound object provided.
		// If there was not a sound object set before that it will do an assert.
		void SetVolume(float volumeValue);
		// Set the sound to play in a loop.
		// If there was not a sound object set before that it will do an assert.
		void SetLoop(bool enabled);
		// Get the duration of the sound object that was provided before.
		// If there was not a sound object set before that it will do an assert.
		sf::Time GetDuration() const;

	private:
		sf::Sound m_SoundPlayer; // The sfml sound player.
		Time m_SoundTimer;		 // A timer that is equal to the duration of the track. Used to not play the sound again while it is playing.
	};

}