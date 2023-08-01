#pragma once

/// <summary>
/// 
/// This file includes the Time class. This class is responsible for time management.
/// It can be used to create a timer or to get delta time.
/// This class can restart the time, get elapsed time since time had begun, get time, set time, and get delta time (there is only one instance of delta time)
/// 
/// </summary>

#include <SFML/System.hpp>

namespace DunnEngine {
    class Time
    {
    public:
        //--------------------------------- COMMON FUNCTION ---------------------------------\\

        // Restart the timer
        void Restart();
        // Get the time elapsed since timer had begun
        sf::Time GetElapsedTime() const;
       
        // Get the current time
        const sf::Time GetTime() const;
        // Set the time to a time in seconds
        void SetTime(float time);

        // Change the behaviour of -= for the client to be able to use it with a different time object
        Time& operator-=(const sf::Time& rhs);
        // Change the behavious of += for the client to be able to use it with a different time object
        Time& operator+=(const sf::Time& rhs);
        // Change the behavious of = for the client to be able to use it with a different time object
        Time& operator=(const sf::Time& rhs);
    public:
        // Get the current delta time
        static sf::Time GetDeltaTime();
    public:
        //--------------------------------- ENGINE SIDE FUNCTIONS ---------------------------------\\

        // Update the DeltaTime every frame
        // This MUST be called every frame
        static void Update();
    private:
        static sf::Clock m_DeltaClock;  // Holds the sfml clock that is used in the calculation of delta time
        static sf::Time m_DeltaTime;    // Holds the current value of the delta time
    private:
        sf::Clock m_Clock;              // Holds the sfml clock to hold the value of the time elapsed since the timer began
        sf::Time m_Time;                // Holds the sfml time
    };

}