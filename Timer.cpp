#include "Timer.h"
#include "GUI.h"
#include <iostream>
using namespace std;

Timer::Timer(int seconds) : startTime(0), timeLimit(seconds) {}

void Timer::start()              { startTime = time(0); }
int  Timer::getElapsed()  const  { return (int)difftime(time(0), startTime); }
int  Timer::getRemaining() const {
    int rem = timeLimit - getElapsed();
    return rem < 0 ? 0 : rem;
}
bool Timer::isExpired() const    { return getElapsed() >= timeLimit; }

void Timer::display() const {
    int rem = getRemaining();
    int pct = (timeLimit > 0) ? (rem * 100 / timeLimit) : 0;

    cout << "  ";
    if (pct > 50)       GUI::setColor(GUI::GREEN);
    else if (pct > 25)  GUI::setColor(GUI::YELLOW);
    else                GUI::setColor(GUI::RED);

    cout << (char)196 << " Time Remaining: " << rem << "s ";

    // Mini progress bar (20 chars wide)
    int filled = pct / 5;   // 0-20
    cout << "[";
    for (int i = 0; i < 20; i++) {
        if (i < filled) cout << (char)219;
        else            cout << ' ';
    }
    cout << "] " << pct << "% ";
    cout << (char)196 << "\n";

    GUI::resetColor();
}
