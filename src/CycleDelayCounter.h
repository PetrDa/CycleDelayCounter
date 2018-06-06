// ************* CycleDelayCounter.h ********************
#ifndef CYCLE_DELAY_COUNTER_H
#define CYCLE_DELAY_COUNTER_H

// **********************************************************************
// ************** Class CycleDelayCounter *******************************
// **********************************************************************

class CycleDelayCounter {
    public:
        CycleDelayCounter(              // Initializes a new object.
            unsigned long _delay,        // definition of the delay length
            bool _repeat=true       // if counting should be immediately restarted
        );
        
        void setDelay(unsigned long _delay);                     // redefinition of the delay length (of next next cycle)
        void startCounter(unsigned long _delay = 0);               // time measurement start
        bool finished();               // if the delay finished
    protected:
        unsigned long delayLength;      // delay length storage 
        unsigned long counterStart;     // time when counter was started
        bool repeat;                    // if counting should be immediately restarted
        bool finishedCountdown;         // countDown was finished (and stopped with no repeat)
};

#endif // CYCLE_DELAY_COUNTER_H
