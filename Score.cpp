#include "Score.h"
#include "GUI.h"
#include <iostream>
using namespace std;

// ── save ─────────────────────────────────────────────────────────────────────
void Score::save(const Player& p) {
    try {
        ofstream file("scores.txt", ios::app);
        if (!file.is_open())
            throw runtime_error("Cannot open scores.txt for writing.");

        file << p.getName() << " " << p.getScore() << "\n";
        file.close();

        GUI::printSuccess("Score saved to leaderboard!");
    }
    catch (const runtime_error& e) {
        GUI::printError(string("File Error: ") + e.what());
    }
}

// ── show ─────────────────────────────────────────────────────────────────────
void Score::show() {
    // Read all entries using WordList<LeaderEntry> (template in action)
    WordList<LeaderEntry> entries;

    try {
        ifstream file("scores.txt");
        if (!file.is_open())
            throw runtime_error("scores.txt not found.");

        string name;
        int    score;
        while (file >> name >> score) {
            LeaderEntry e;
            e.name  = name;
            e.score = score;
            entries.add(e);
        }
        file.close();
    }
    catch (const runtime_error& e) {
        GUI::printWarning(string("Leaderboard: ") + e.what());
        return;
    }

    if (entries.empty()) {
        GUI::printInfo("No scores recorded yet.");
        return;
    }

    // Sort descending
    entries.sortDescending();

    // ── Display ──────────────────────────────────────
    cout << "\n";
    GUI::setColor(GUI::CYAN);
    GUI::printBoxTop(44);
    GUI::printBoxSide(44, "  LEADERBOARD  ", GUI::YELLOW);
    GUI::printDivider(44);

    int limit = (entries.size() < MAX_DISPLAY) ? entries.size() : MAX_DISPLAY;
    for (int i = 0; i < limit; i++) {
        string rank = "#" + to_string(i + 1) + "  " +
                      entries[i].name + "  :  " +
                      to_string(entries[i].score) + " pts";

        if      (i == 0) GUI::printBoxSide(44, rank, GUI::YELLOW);
        else if (i == 1) GUI::printBoxSide(44, rank, GUI::LIGHT_GRAY);
        else if (i == 2) GUI::printBoxSide(44, rank, GUI::DARK_YELLOW);
        else             GUI::printBoxSide(44, rank, GUI::WHITE);
    }

    GUI::printBoxBottom(44);
    GUI::resetColor();
}
