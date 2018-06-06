#include "CycleDelayCounter.h"

#if ARDUINO >= 100
#include "Arduino.h"
#else
extern "C" {
#include "WConstants.h"
}
#endif



// **********************************************************************
// ************** Class CycleDelayCounter *******************************
// **********************************************************************

CycleDelayCounter::CycleDelayCounter(     
            unsigned long _delay,       // definition of the delay length
            bool _repeat )            // if counting should be immediately restarted
{
    delayLength = _delay;
    repeat = _repeat;
    finishedCountdown = false;
    counterStart = millis();
}

// **********************************************************************
void CycleDelayCounter::setDelay(unsigned long _delay) {
    delayLength = _delay;
}

// **********************************************************************
void CycleDelayCounter::startCounter(unsigned long _delay) {
    if (_delay != 0) {
        delayLength = _delay;
    }
    counterStart = millis();
    finishedCountdown = false;
}

// **********************************************************************
bool CycleDelayCounter::finished() {

    if (finishedCountdown) {
        return true;
    }

    unsigned long currTime = millis();

    if (currTime > counterStart) { //normal case
        if (currTime - counterStart < delayLength) { // jeste osetrit overflow
            return false;
        }
    } else { // case of time overflow (each aprox. 55 days)
        if ( (0UL - counterStart) + (currTime) < delayLength) { // seems to be same, but it depends how processor it calculates
            return false;
        }
    }

    if (repeat) {                   // start new Delay cycle
        counterStart = millis();
        return true;    
    }
    
    finishedCountdown = true;       // stay in finished Countdown state
    return true;
}

