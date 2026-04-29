#ifndef HINT_H
#define HINT_H

#include <string>
using namespace std;

// ═══════════════════════════════════════════════════════
//  Hint  –  3 hints per game; static penalty constant
// ═══════════════════════════════════════════════════════
class Hint {
private:
    int hintsLeft;
    static const int HINT_PENALTY = 5;   // static member

public:
    Hint();

    bool showHint   (string words[], int wordCount);
    int  getHintsLeft() const;
    static int getHintPenalty();          // static accessor
};

#endif // HINT_H
