#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <iostream>
using namespace std;

// ═══════════════════════════════════════════════════════
//  Player  –  Encapsulation + Operator Overloading
// ═══════════════════════════════════════════════════════
class Player {
private:
    string name;
    int    score;
    int    hintsUsed;

public:
    Player(string n);

    void addScore   (int s);
    void deductScore(int s);
    void useHint    ();

    // ── Getters (encapsulation) ──────────────────────
    string getName    () const;
    int    getScore   () const;
    int    getHintsUsed() const;

    // ── Operator Overloading ─────────────────────────
    // << : pretty-print player summary
    friend ostream& operator<<(ostream& os, const Player& p);

    // > : compare by score (for leaderboard sorting)
    bool operator>(const Player& other) const;

    // == : same name  (duplicate-check)
    bool operator==(const Player& other) const;
};

#endif // PLAYER_H
