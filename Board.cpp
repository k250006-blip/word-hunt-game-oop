#include "Board.h"
#include "GUI.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
using namespace std;

Board::Board(int s) : size(s) {
    srand((unsigned int)time(0));
    for (int i = 0; i < 15; i++)
        for (int j = 0; j < 15; j++)
            grid[i][j] = '.';
}

int Board::getSize() const { return size; }

// ── Private placement helpers ────────────────────────────────────────────────

bool Board::placeWordHorizontal(string word) {
    int len = (int)word.length();
    if (len > size) return false;
    for (int attempt = 0; attempt < 100; attempt++) {
        int row = rand() % size;
        int col = rand() % (size - len + 1);
        bool fits = true;
        for (int i = 0; i < len; i++)
            if (grid[row][col + i] != '.' && grid[row][col + i] != word[i])
                { fits = false; break; }
        if (fits) {
            for (int i = 0; i < len; i++)
                grid[row][col + i] = word[i];
            return true;
        }
    }
    return false;
}

bool Board::placeWordVertical(string word) {
    int len = (int)word.length();
    if (len > size) return false;
    for (int attempt = 0; attempt < 100; attempt++) {
        int row = rand() % (size - len + 1);
        int col = rand() % size;
        bool fits = true;
        for (int i = 0; i < len; i++)
            if (grid[row + i][col] != '.' && grid[row + i][col] != word[i])
                { fits = false; break; }
        if (fits) {
            for (int i = 0; i < len; i++)
                grid[row + i][col] = word[i];
            return true;
        }
    }
    return false;
}

bool Board::placeWordDiagonal(string word) {
    int len = (int)word.length();
    if (len > size) return false;
    for (int attempt = 0; attempt < 100; attempt++) {
        int row = rand() % (size - len + 1);
        int col = rand() % (size - len + 1);
        bool fits = true;
        for (int i = 0; i < len; i++)
            if (grid[row + i][col + i] != '.' && grid[row + i][col + i] != word[i])
                { fits = false; break; }
        if (fits) {
            for (int i = 0; i < len; i++)
                grid[row + i][col + i] = word[i];
            return true;
        }
    }
    return false;
}

// ── Public interface ─────────────────────────────────────────────────────────

void Board::generate(string words[], int wordCount, bool diag, bool rev) {
    // Reset grid
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            grid[i][j] = '.';

    for (int k = 0; k < wordCount; k++) {
        string word = words[k];
        if (rev && rand() % 2 == 0)
            reverse(word.begin(), word.end());

        int direction = rand() % (diag ? 3 : 2);
        bool placed = false;

        if      (direction == 0) placed = placeWordHorizontal(word);
        else if (direction == 1) placed = placeWordVertical(word);
        else                     placed = placeWordDiagonal(word);

        if (!placed) placed = placeWordHorizontal(word);
        if (!placed)         placeWordVertical(word);
    }

    // Fill empty cells with random capital letters
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            if (grid[i][j] == '.')
                grid[i][j] = 'A' + rand() % 26;
}

void Board::display() const {
    // ── Column header ──────────────────────────────────
    cout << "\n";
    GUI::setColor(GUI::DARK_CYAN);
    cout << "    ";
    for (int j = 0; j < size; j++) {
        if (j < 9) cout << " " << (j + 1) << " ";
        else       cout << (j + 1) << " ";
    }
    cout << "\n";

    GUI::setColor(GUI::DARK_GRAY);
    cout << "   +";
    for (int j = 0; j < size; j++) cout << "---";
    cout << "+\n";

    // ── Grid rows ──────────────────────────────────────
    for (int i = 0; i < size; i++) {
        GUI::setColor(GUI::DARK_CYAN);
        if (i < 9) cout << " " << (i + 1) << " ";
        else       cout << (i + 1) << " ";

        GUI::setColor(GUI::DARK_GRAY);
        cout << "|";

        for (int j = 0; j < size; j++) {
            char c = grid[i][j];
            // Alternate colours for readability
            if ((i + j) % 2 == 0) GUI::setColor(GUI::WHITE);
            else                   GUI::setColor(GUI::LIGHT_GRAY);
            cout << " " << c << " ";
        }

        GUI::setColor(GUI::DARK_GRAY);
        cout << "|\n";
    }

    GUI::setColor(GUI::DARK_GRAY);
    cout << "   +";
    for (int j = 0; j < size; j++) cout << "---";
    cout << "+\n";
    GUI::resetColor();
}

bool Board::checkWord(string word) const {
    int len = (int)word.length();

    // ── Horizontal ────────────────────────────────────
    for (int i = 0; i < size; i++) {
        string row = "";
        for (int j = 0; j < size; j++) row += grid[i][j];
        if (row.find(word) != string::npos) return true;
        string rev = row;
        reverse(rev.begin(), rev.end());
        if (rev.find(word) != string::npos) return true;
    }

    // ── Vertical ──────────────────────────────────────
    for (int j = 0; j < size; j++) {
        string col = "";
        for (int i = 0; i < size; i++) col += grid[i][j];
        if (col.find(word) != string::npos) return true;
        string rev = col;
        reverse(rev.begin(), rev.end());
        if (rev.find(word) != string::npos) return true;
    }

    // ── Diagonal (top-left → bottom-right) ────────────
    for (int r = 0; r <= size - len; r++) {
        for (int c = 0; c <= size - len; c++) {
            string diag = "";
            for (int k = 0; k < len; k++)
                diag += grid[r + k][c + k];
            if (diag == word) return true;
        }
    }

    // ── Diagonal (top-right → bottom-left) ────────────
    for (int r = 0; r <= size - len; r++) {
        for (int c = len - 1; c < size; c++) {
            string diag = "";
            for (int k = 0; k < len; k++)
                diag += grid[r + k][c - k];
            if (diag == word) return true;
        }
    }

    return false;
}
