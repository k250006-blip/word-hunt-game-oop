#ifndef GAME_H
#define GAME_H

#include <string>
#include <iostream>
using namespace std;

// ═══════════════════════════════════════════════════════
//  Game (Abstract Base Class)   –  Abstraction + Inheritance
//
//  Demonstrates:
//    • Abstraction  – pure virtual functions
//    • Inheritance  – EasyGame / MediumGame / HardGame
//    • Polymorphism – virtual dispatch via base pointer
// ═══════════════════════════════════════════════════════
class Game {
protected:
    string foundWords[50];
    int    foundCount;


public:
    Game();

    // ── Pure virtual (abstract) ──────────────────────
    virtual void   startGame        () = 0;
    virtual int    getGridSize      () const = 0;
    virtual int    getTimeLimit     () const = 0;
    virtual bool   allowDiagonal    () const = 0;
    virtual bool   allowReverse     () const = 0;
    virtual string getDifficultyName() const = 0;

    // ── Concrete helpers ─────────────────────────────
    void menu() const;
    bool alreadyFound(const string& word) const;

    static int totalGamesPlayed;        // static member
    static int getTotalGamesPlayed();

    virtual ~Game() {}
};

// ─────────────────────────────────────────────────────
//  Derived: EasyGame   (8×8, 120 s, no diag/rev)
// ─────────────────────────────────────────────────────
class EasyGame : public Game {
public:
    void   startGame        () override;
    int    getGridSize      () const override { return 8;     }
    int    getTimeLimit     () const override { return 120;   }
    bool   allowDiagonal    () const override { return false; }
    bool   allowReverse     () const override { return false; }
    string getDifficultyName() const override { return "Easy"; }
};

// ─────────────────────────────────────────────────────
//  Derived: MediumGame (12×12, 90 s, no diag/rev)
// ─────────────────────────────────────────────────────
class MediumGame : public Game {
public:
    void   startGame        () override;
    int    getGridSize      () const override { return 12;    }
    int    getTimeLimit     () const override { return 90;    }
    bool   allowDiagonal    () const override { return false; }
    bool   allowReverse     () const override { return false; }
    string getDifficultyName() const override { return "Medium"; }
};

// ─────────────────────────────────────────────────────
//  Derived: HardGame   (15×15, 60 s, diagonal+reverse)
// ─────────────────────────────────────────────────────
class HardGame : public Game {
public:
    void   startGame        () override;
    int    getGridSize      () const override { return 15;   }
    int    getTimeLimit     () const override { return 60;   }
    bool   allowDiagonal    () const override { return true; }
    bool   allowReverse     () const override { return true; }
    string getDifficultyName() const override { return "Hard"; }
};

#endif // GAME_H
