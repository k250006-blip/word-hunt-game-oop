#ifndef TIMER_H
#define TIMER_H

#include <ctime>
using namespace std;

// ═══════════════════════════════════════════════════════
//  Timer  –  countdown with coloured display
// ═══════════════════════════════════════════════════════
class Timer {
private:
    time_t startTime;
    int    timeLimit;

public:
    Timer(int seconds);

    void start      ();
    int  getElapsed () const;
    int  getRemaining() const;
    bool isExpired  () const;
    void display    () const;
};

#endif // TIMER_H
