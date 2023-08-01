#include "AudioPlayer.h"

namespace DunnEngine {

	void SoundPlayer::SetSound(DE_Sound* sound)
	{
		DE_CORE_ASSERT(!m_SoundPlayer.getBuffer(), "There is a sound buffer already bound to this sound player object!");	// We do not support hot-changing a buffer bound to a sound. If needed to change sound you need to create a different object for now.
		m_SoundPlayer.setBuffer(*sound->Sound);
	}
	void SoundPlayer::Play()
	{
		DE_CORE_ASSERT(m_SoundPlayer.getBuffer(), "Sound buffer was not set before!");
		
		// If sound is playing and hasn't finished don't play the sound again if this function was called
		// This 'delay' is equal to the duration of the sound track
		if (m_SoundTimer.GetTime().asMicroseconds() <= 0)
		{
			m_SoundPlayer.play();
			m_SoundTimer = m_SoundPlayer.getBuffer()->getDuration();
		}
		else
		{
			m_SoundTimer -= Time::GetDeltaTime();
		}
	}
	void SoundPlayer::Pause()
	{
		DE_CORE_ASSERT(m_SoundPlayer.getBuffer(), "Sound buffer was not set before!");
		m_SoundPlayer.pause();
	}
	void SoundPlayer::Stop()
	{
		DE_CORE_ASSERT(m_SoundPlayer.getBuffer(), "Sound buffer was not set before!");
		m_SoundPlayer.stop();
	}
	void SoundPlayer::SetPlayOffset(Time timeOffset)
	{
		DE_CORE_ASSERT(m_SoundPlayer.getBuffer(), "Sound buffer was not set before!");
		m_SoundPlayer.setPlayingOffset(timeOffset.GetTime());
	}
	void SoundPlayer::SetPitch(float pitchValue)
	{
		DE_CORE_ASSERT(m_SoundPlayer.getBuffer(), "Sound buffer was not set before!");
		m_SoundPlayer.setPitch(pitchValue);
	}
	void SoundPlayer::SetVolume(float volumeValue)
	{
		DE_CORE_ASSERT(m_SoundPlayer.getBuffer(), "Sound buffer was not set before!");
		m_SoundPlayer.setVolume(volumeValue);
	}
	void SoundPlayer::SetLoop(bool enabled)
	{
		DE_CORE_ASSERT(m_SoundPlayer.getBuffer(), "Sound buffer was not set before!");
		m_SoundPlayer.setLoop(enabled);
	}

	sf::Time SoundPlayer::GetDuration() const
	{
		DE_CORE_ASSERT(m_SoundPlayer.getBuffer(), "Sound buffer was not set before!");
		return m_SoundPlayer.getBuffer()->getDuration();
	}
}