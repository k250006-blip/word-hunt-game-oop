#include "Category.h"
#include "GUI.h"
#include <iostream>
using namespace std;

int Category::getWordCount() {
    return WORD_COUNT;
}

void Category::getWords(int choice, string words[], int& count) {
    count = WORD_COUNT;

    string animals[6]     = { "CAT",     "DOG",    "LION",   "TIGER",  "EAGLE",  "SHARK"  };
    string countries[6]   = { "PAKISTAN","INDIA",  "CHINA",  "CANADA", "JAPAN",  "FRANCE" };
    string programming[6] = { "JAVA",    "PYTHON", "CLASS",  "OBJECT", "ARRAY",  "LOOP"   };
    string fruits[6]      = { "APPLE",   "MANGO",  "GRAPE",  "BANANA", "PEACH",  "LEMON"  };
    string sports[6]      = { "CRICKET", "TENNIS", "HOCKEY", "BOXING", "GOLF",   "SWIM"   };

    for (int i = 0; i < count; i++) {
        switch (choice) {
            case 1:  words[i] = animals[i];     break;
            case 2:  words[i] = countries[i];   break;
            case 3:  words[i] = programming[i]; break;
            case 4:  words[i] = fruits[i];      break;
            case 5:  words[i] = sports[i];      break;
            default: words[i] = animals[i];     break;
        }
    }
}

void Category::displayMenu() const {
    GUI::setColor(GUI::CYAN);
    cout << "\n";
    GUI::printBoxTop(40);
    GUI::printBoxSide(40, "SELECT CATEGORY", GUI::YELLOW);
    GUI::printDivider(40);
    GUI::printBoxSide(40, "1.  Animals",       GUI::WHITE);
    GUI::printBoxSide(40, "2.  Countries",     GUI::WHITE);
    GUI::printBoxSide(40, "3.  Programming",   GUI::WHITE);
    GUI::printBoxSide(40, "4.  Fruits",        GUI::WHITE);
    GUI::printBoxSide(40, "5.  Sports",        GUI::WHITE);
    GUI::printBoxBottom(40);
    GUI::resetColor();
}
