#pragma once

#include <time/timereference.h>

#include <array>
#include <chrono>
#include <numeric>
#include <time.h>

namespace puma
{

    constexpr unsigned int kAverageFpsSampleCount = 30;

    class DeltaTime
    {

    public:

        DeltaTime()
            : m_timeReference()
            , m_previousExecutionSeconds( m_timeReference.getElapsedSeconds() )
            , m_dtSamples()
        {}

        virtual ~DeltaTime() = default;
     
        float get() const { return m_dtSamples[m_currentDtIndex]; }

        float getAverage() const
        {
            float dtSum = std::accumulate( m_dtSamples.begin(), m_dtSamples.end(), 0.0f );
            return dtSum / (float)m_dtSamples.size();
        }

        void update()
        {
            m_currentDtIndex = ++m_currentDtIndex < m_dtSamples.size() ? m_currentDtIndex : 0 ;
            float elapsedSeconds = (float)m_timeReference.getElapsedSeconds();
            m_dtSamples[m_currentDtIndex] = (float)(elapsedSeconds - m_previousExecutionSeconds);
            m_previousExecutionSeconds = elapsedSeconds;
        }

    private:

        TimeReference m_timeReference;
        double m_previousExecutionSeconds = 0.0;
        std::array<float, kAverageFpsSampleCount> m_dtSamples;
        unsigned int m_currentDtIndex = 0;
    };

}
