#ifndef SCORE_H
#define SCORE_H

#include "Player.h"
#include <string>
#include <fstream>
#include <stdexcept>
using namespace std;

// ═══════════════════════════════════════════════════════
//  WordList<T>  –  Generic container (Templates)
//  Replaces vectors throughout the project.
// ═══════════════════════════════════════════════════════
template <typename T>
class WordList {
private:
    T   data[100];
    int count;

public:
    WordList() : count(0) {}

    void add(const T& item) {
        if (count < 100) data[count++] = item;
    }

    T& operator[](int i)              { return data[i]; }
    const T& operator[](int i) const  { return data[i]; }

    int  size()  const { return count; }
    bool empty() const { return count == 0; }

    void clear() { count = 0; }

    // Simple insertion-sort (descending by int value for leaderboard)
    void sortDescending() {
        for (int i = 1; i < count; i++) {
            T key = data[i];
            int j = i - 1;
            while (j >= 0 && data[j] < key) {
                data[j + 1] = data[j];
                j--;
            }
            data[j + 1] = key;
        }
    }
};

// ── LeaderEntry: one row in the leaderboard ──────────────────────────────────
struct LeaderEntry {
    string name;
    int    score;

    // needed by WordList::sortDescending()
    bool operator<(const LeaderEntry& o) const { return score < o.score; }
};

// ═══════════════════════════════════════════════════════
//  Score  –  File handling + leaderboard display
// ═══════════════════════════════════════════════════════
class Score {
private:
    static const int MAX_DISPLAY = 10;   // static member

public:
    void save(const Player& p);
    void show();
};

#endif // SCORE_H
