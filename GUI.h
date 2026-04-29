#ifndef GUI_H
#define GUI_H

#include <iostream>
#include <string>
#include <windows.h>
using namespace std;

// ═══════════════════════════════════════════════════════
//  GUI  –  Windows Console colour & box-drawing helpers
// ═══════════════════════════════════════════════════════

namespace GUI {

    enum Color {
        BLACK        = 0, DARK_BLUE    = 1, DARK_GREEN   = 2,
        DARK_CYAN    = 3, DARK_RED     = 4, DARK_MAGENTA = 5,
        DARK_YELLOW  = 6, LIGHT_GRAY   = 7, DARK_GRAY    = 8,
        BLUE         = 9, GREEN        = 10, CYAN         = 11,
        RED          = 12, MAGENTA     = 13, YELLOW       = 14,
        WHITE        = 15
    };

    inline void setColor(Color fg, Color bg = BLACK) {
        HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(h, (WORD)((bg << 4) | fg));
    }

    inline void resetColor() {
        GUI::setColor(GUI::WHITE, GUI::BLACK);
    }

    inline void clearScreen() { system("cls"); }

    inline void hideCursor() {
        HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
        CONSOLE_CURSOR_INFO ci;
        GetConsoleCursorInfo(h, &ci);
        ci.bVisible = FALSE;
        SetConsoleCursorInfo(h, &ci);
    }

    inline void showCursor() {
        HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
        CONSOLE_CURSOR_INFO ci;
        GetConsoleCursorInfo(h, &ci);
        ci.bVisible = TRUE;
        SetConsoleCursorInfo(h, &ci);
    }

    inline void printBoxTop(int width) {
        GUI::setColor(GUI::CYAN);
        cout << (char)201;
        for (int i = 0; i < width; i++) cout << (char)205;
        cout << (char)187 << "\n";
        GUI::resetColor();
    }

    inline void printBoxBottom(int width) {
        GUI::setColor(GUI::CYAN);
        cout << (char)200;
        for (int i = 0; i < width; i++) cout << (char)205;
        cout << (char)188 << "\n";
        GUI::resetColor();
    }

    inline void printBoxSide(int width, const string& text = "", Color fg = GUI::WHITE) {
        GUI::setColor(GUI::CYAN);
        cout << (char)186;
        int pad  = (width - (int)text.length()) / 2;
        int padR = width - (int)text.length() - pad;
        if (pad  < 0) pad  = 0;
        if (padR < 0) padR = 0;
        for (int i = 0; i < pad;  i++) cout << ' ';
        GUI::setColor(fg);
        cout << text;
        GUI::resetColor();
        GUI::setColor(GUI::CYAN);
        for (int i = 0; i < padR; i++) cout << ' ';
        cout << (char)186 << "\n";
        GUI::resetColor();
    }

    inline void printDivider(int width) {
        GUI::setColor(GUI::CYAN);
        cout << (char)204;
        for (int i = 0; i < width; i++) cout << (char)205;
        cout << (char)185 << "\n";
        GUI::resetColor();
    }

    inline void printSeparator(int width = 50) {
        GUI::setColor(GUI::DARK_CYAN);
        for (int i = 0; i < width; i++) cout << (char)196;
        cout << "\n";
        GUI::resetColor();
    }

    inline void printSuccess(const string& msg) {
        GUI::setColor(GUI::GREEN);
        cout << "  [+] " << msg << "\n";
        GUI::resetColor();
    }

    inline void printError(const string& msg) {
        GUI::setColor(GUI::RED);
        cout << "  [!] " << msg << "\n";
        GUI::resetColor();
    }

    inline void printInfo(const string& msg) {
        GUI::setColor(GUI::CYAN);
        cout << "  [i] " << msg << "\n";
        GUI::resetColor();
    }

    inline void printWarning(const string& msg) {
        GUI::setColor(GUI::YELLOW);
        cout << "  [~] " << msg << "\n";
        GUI::resetColor();
    }

} // namespace GUI

#endif // GUI_H
