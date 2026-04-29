#ifndef CATEGORY_H
#define CATEGORY_H

#include <string>
using namespace std;

// ═══════════════════════════════════════════════════════
//  Category  –  Word bank for different themes
// ═══════════════════════════════════════════════════════
class Category {
private:
    static const int WORD_COUNT = 6;   // static member

public:
    void getWords(int choice, string words[], int& count);
    static int getWordCount();         // static member function
    void displayMenu() const;
};

#endif // CATEGORY_H
