#pragma once

#include "Time.h"

namespace DunnEngine {

    sf::Clock Time::m_DeltaClock;
    sf::Time Time::m_DeltaTime;

    void Time::Restart()
    {
        m_Time = m_Clock.restart();
    }

    sf::Time Time::GetElapsedTime() const
    {
        return m_Clock.getElapsedTime();
    }

    void Time::Update()
    {

        m_DeltaTime = m_DeltaClock.restart();
    }

    sf::Time Time::GetDeltaTime()
    {
        return m_DeltaTime;
    }

    const sf::Time Time::GetTime() const
    {
        return m_Time;
    }

    void Time::SetTime(float time)
    {
        m_Time = sf::seconds(time);
    }

    Time& Time::operator-=(const sf::Time& rhs)
    {
        m_Time -= rhs;
        return *this;       // Return this time instance after the modification
    }

    Time& Time::operator+=(const sf::Time& rhs)
    {
        m_Time -= rhs;
        return *this;       // Return this time instance after the modification
    }

    Time& Time::operator=(const sf::Time& rhs)
    {
        m_Time = rhs;
        return *this;       // Return this time instance after the modification
    }
    
}