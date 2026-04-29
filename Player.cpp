#include "Player.h"
#include "GUI.h"
using namespace std;

Player::Player(string n) : name(n), score(0), hintsUsed(0) {}

void Player::addScore(int s) {
    score += s;
}

void Player::deductScore(int s) {
    score -= s;
    if (score < 0) score = 0;
}

void Player::useHint() {
    hintsUsed++;
}

string Player::getName()     const { return name;      }
int    Player::getScore()    const { return score;     }
int    Player::getHintsUsed() const { return hintsUsed; }

// ── Operator<< ──────────────────────────────────────────
ostream& operator<<(ostream& os, const Player& p) {
    GUI::setColor(GUI::YELLOW);
    os << "  Player    : ";
    GUI::setColor(GUI::WHITE);
    os << p.name << "\n";

    GUI::setColor(GUI::YELLOW);
    os << "  Score     : ";
    GUI::setColor(GUI::GREEN);
    os << p.score << " pts\n";

    GUI::setColor(GUI::YELLOW);
    os << "  Hints Used: ";
    GUI::setColor(GUI::CYAN);
    os << p.hintsUsed << "\n";

    GUI::resetColor();
    return os;
}

// ── Operator> ───────────────────────────────────────────
bool Player::operator>(const Player& other) const {
    return score > other.score;
}

// ── Operator== ──────────────────────────────────────────
bool Player::operator==(const Player& other) const {
    return name == other.name;
}
