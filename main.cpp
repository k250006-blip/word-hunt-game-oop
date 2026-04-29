#include "Game.h"
#include "Score.h"
#include "GUI.h"
#include<iostream>
#include<stdexcept>
#include<windows.h>
using namespace std;

// ── How-To-Play screen ───────────────────────────────────────────────────────
static void showHowToPlay() {
    GUI::clearScreen();
    GUI::setColor(GUI::CYAN);
    GUI::printBoxTop(54);
    GUI::printBoxSide(54, "HOW TO PLAY", GUI::YELLOW);
    GUI::printDivider(54);
    GUI::printBoxSide(54, "1. Choose difficulty & category",        GUI::WHITE);
    GUI::printBoxSide(54, "2. A grid of letters will appear",       GUI::WHITE);
    GUI::printBoxSide(54, "3. Type hidden words to find them",      GUI::WHITE);
    GUI::printBoxSide(54, "4. Words hide horizontally, vertically", GUI::WHITE);
    GUI::printBoxSide(54, "   and diagonally (Hard mode)",          GUI::WHITE);
    GUI::printDivider(54);
    GUI::printBoxSide(54, "Commands during game:",                  GUI::YELLOW);
    GUI::printBoxSide(54, "  'hint'  - reveal a clue (-5 pts)",    GUI::CYAN);
    GUI::printBoxSide(54, "  'board' - redisplay the grid",         GUI::CYAN);
    GUI::printBoxSide(54, "  'exit'  - quit current game",          GUI::CYAN);
    GUI::printDivider(54);
    GUI::printBoxSide(54, "Scoring:",                               GUI::YELLOW);
    GUI::printBoxSide(54, "  10 pts per letter in found word",      GUI::WHITE);
    GUI::printBoxSide(54, "  +20 Speed Bonus (first half of time)", GUI::GREEN);
    GUI::printBoxSide(54, "  -5  per hint used",                   GUI::RED);
    GUI::printBoxBottom(54);
    GUI::resetColor();
    cout << "\n  Press ENTER to return to menu...";
    cin.ignore();
    cin.get();
}

// ── Difficulty selection ─────────────────────────────────────────────────────
static Game* selectDifficulty() {
    GUI::clearScreen();
    GUI::setColor(GUI::CYAN);
    GUI::printBoxTop(46);
    GUI::printBoxSide(46, "SELECT DIFFICULTY", GUI::YELLOW);
    GUI::printDivider(46);
    GUI::printBoxSide(46, "1.  Easy    (8x8,  120s)",  GUI::GREEN);
    GUI::printBoxSide(46, "2.  Medium  (12x12, 90s)",  GUI::YELLOW);
    GUI::printBoxSide(46, "3.  Hard    (15x15, 60s,",  GUI::RED);
    GUI::printBoxSide(46, "            diagonal+reverse)", GUI::RED);
    GUI::printBoxBottom(46);
    GUI::resetColor();

    cout << "\n  Choice: ";
    int diff;
    cin >> diff;

    try {
        switch (diff) {
            case 1: return new EasyGame();
            case 2: return new MediumGame();
            case 3: return new HardGame();
            default:
                throw out_of_range("Invalid difficulty. Defaulting to Easy.");
        }
    }
    catch (const out_of_range& e) {
        GUI::printWarning(e.what());
        return new EasyGame();
    }
}

int main() {
    // Set console title and code-page for box-drawing chars
    SetConsoleTitle("Word Search Puzzle - FAST-NUCES");
    std::cout << "Game Started\n";

    GUI::hideCursor();

    int choice;

    do {
        // Polymorphism: EasyGame used only to call menu() via base pointer
        Game* menuObj = new EasyGame();
        menuObj->menu();
        delete menuObj;

        GUI::showCursor();
        cin >> choice;

        switch (choice) {
            case 1: {
                // Polymorphism via base pointer → virtual dispatch
                Game* game = selectDifficulty();
                game->startGame();
                delete game;
                break;
            }
            case 2: {
                Score sc;
                sc.show();
                cout << "\n  Press ENTER to return...";
                cin.ignore();
                cin.get();
                break;
            }
            case 3:
                showHowToPlay();
                break;
            case 4:
                GUI::clearScreen();
                GUI::setColor(GUI::YELLOW);
                GUI::printBoxTop(40);
                GUI::printBoxSide(40, "Thanks for playing!", GUI::GREEN);
                GUI::printBoxSide(40, "FAST-NUCES | OOP Spring 2026", GUI::CYAN);
                GUI::printBoxBottom(40);
                GUI::resetColor();
                break;
            default:
                GUI::printError("Invalid choice. Try again.");
                break;
        }

    } while (choice != 4);

    GUI::showCursor();
    return 0;
}
