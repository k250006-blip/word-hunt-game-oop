#include "Hint.h"
#include "GUI.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

Hint::Hint() : hintsLeft(3) {}

int Hint::getHintsLeft() const     { return hintsLeft;    }
int Hint::getHintPenalty()         { return HINT_PENALTY; }

bool Hint::showHint(string words[], int wordCount) {
    if (hintsLeft <= 0) {
        GUI::printError("No hints remaining!");
        return false;
    }

    int i = rand() % wordCount;
    cout << "\n";
    GUI::setColor(GUI::DARK_CYAN);
    GUI::printBoxTop(46);
    GUI::printBoxSide(46, "HINT", GUI::YELLOW);
    GUI::printDivider(46);

    string line1 = "Starts with: '";
    line1 += words[i][0];
    line1 += "'";
    string line2 = "Length: ";
    line2 += to_string((int)words[i].length());
    line2 += " letters";
    string line3 = "Penalty: -" + to_string(HINT_PENALTY) + " points";

    GUI::printBoxSide(46, line1, GUI::GREEN);
    GUI::printBoxSide(46, line2, GUI::GREEN);
    GUI::printBoxSide(46, line3, GUI::RED);

    hintsLeft--;
    string rem = "Hints left: " + to_string(hintsLeft);
    GUI::printBoxSide(46, rem, GUI::YELLOW);
    GUI::printBoxBottom(46);
    GUI::resetColor();

    return true;
}
