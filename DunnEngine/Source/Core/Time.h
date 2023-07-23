#pragma once

#include <SFML/System.hpp>

namespace DunnEngine {
    class Time
    {
    public:
        void Restart();
        sf::Time GetElapsedTime() const;
        static void Update();
        static sf::Time GetDeltaTime();
        const sf::Time GetTime() const;
        void SetTime(float time);

        Time& operator-=(const sf::Time& rhs);
        Time& operator+=(const sf::Time& rhs);
        Time& operator=(const sf::Time& rhs);
    private:
        static sf::Clock m_DeltaClock;
        static sf::Time m_DeltaTime;
    private:
        sf::Clock m_Clock;
        sf::Time m_Time;
    };

}