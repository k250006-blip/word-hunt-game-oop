#ifndef BOARD_H
#define BOARD_H

#include <string>
using namespace std;

// ═══════════════════════════════════════════════════════
//  Board  –  Grid generation & display with colour GUI
// ═══════════════════════════════════════════════════════
class Board {
private:
    int  size;
    char grid[15][15];

    bool placeWordHorizontal(string word);
    bool placeWordVertical  (string word);
    bool placeWordDiagonal  (string word);

public:
    Board(int s);

    void generate (string words[], int wordCount,
                   bool allowDiagonal = false,
                   bool allowReverse  = false);

    void display  () const;
    bool checkWord(string word) const;
    int  getSize  () const;
};

#endif // BOARD_H
