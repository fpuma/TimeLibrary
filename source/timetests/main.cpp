#include <time/timers/countdowntimer.h>
#include <time/timers/timer.h>
#include <time/deltatime.h>
#include <time/syncedtimersreference.h>
#include <time/timestamp.h>
#include <time/timereference.h>
#include <chrono>

#include <iostream>
#include <thread>

using namespace puma;

int main( int argc, char* argv[] )
{
    TimeReference timeReference;

    {
        Timestamp timestamp;

        timestamp.setToCurrentLocalTime();

        std::cout << timestamp.toString().c_str() << std::endl;

        timestamp.setHour( timestamp.getHour() + 14 );

        std::cout << timestamp.toString().c_str() << std::endl;

        std::cout << std::endl;

        int count = 0;
        
        DeltaTime deltaTime;

        SyncedTimersReference syncedTimersReference;

        SyncedTimer syncedTimer = syncedTimersReference.getTimer();
        SyncedCountdownTimer syncedCountdownTimer = syncedTimersReference.getCountdownTimer();
        
        Timer timer;
        CountdownTimer countdownTimer;
        
        float timeLimit = 7.0f; 
        countdownTimer.setTimeLimit( timeLimit );
        syncedCountdownTimer.setTimeLimit( timeLimit );

        syncedTimer.play();
        syncedCountdownTimer.play();
        timer.play();
        countdownTimer.play();
        
        while ( count < 20 )
        {
            deltaTime.update();
            syncedTimersReference.update();

            std::cout << "============================================================" << std::endl;

            std::cout << "Count: " << count << std::endl;

            std::cout << "Deltatime: " << deltaTime.get() << std::endl ;

            std::cout << "Timer current time:       " << timer.getCurrentTime() << std::endl;
            std::cout << "SyncedTimer current time: " << syncedTimer.getCurrentTime() << std::endl;

            std::cout << "Countdown remaining time:            " << countdownTimer.getRemainingTime()       << "\t" << (countdownTimer.isFinished() ? "Finished" : "Ticking") << std::endl;
            std::cout << "SyncedCountdownTimer remaining time: " << syncedCountdownTimer.getRemainingTime() << "\t" << (syncedCountdownTimer.isFinished() ? "Finished" : "Ticking") << std::endl;

            std::cout << "Countdown current time:            " << countdownTimer.getCurrentTime()       << "\t" << (countdownTimer.isFinished() ? "Finished" : "Ticking") << std::endl;
            std::cout << "SyncedCountdownTimer current time: " << syncedCountdownTimer.getCurrentTime() << "\t" << (syncedCountdownTimer.isFinished() ? "Finished" : "Ticking") << std::endl;

            std::cout << std::endl;

            std::this_thread::sleep_for( std::chrono::duration<double, std::milli>( 2000 ) );
            std::cout << "------------------------------------------------------------" << std::endl;

            std::cout << "Deltatime: " << deltaTime.get() << std::endl;

            std::cout << "Timer current time:       " << timer.getCurrentTime() << std::endl;
            std::cout << "SyncedTimer current time: " << syncedTimer.getCurrentTime() << std::endl;

            std::cout << "Countdown remaining time:            " << countdownTimer.getRemainingTime() << "\t" << (countdownTimer.isFinished() ? "Finished" : "Ticking") << std::endl;
            std::cout << "SyncedCountdownTimer remaining time: " << syncedCountdownTimer.getRemainingTime() << "\t" << (syncedCountdownTimer.isFinished() ? "Finished" : "Ticking") << std::endl;

            std::cout << "Countdown current time:            " << countdownTimer.getCurrentTime() << "\t" << (countdownTimer.isFinished() ? "Finished" : "Ticking") << std::endl;
            std::cout << "SyncedCountdownTimer current time: " << syncedCountdownTimer.getCurrentTime() << "\t" << (syncedCountdownTimer.isFinished() ? "Finished" : "Ticking") << std::endl;

            ++count;
        }
    }
}