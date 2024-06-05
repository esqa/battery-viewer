#ifndef UNTITLED_PRINTING_H
#define UNTITLED_PRINTING_H

#define DEBUG_PRINT(message, color) Print(message, color, __func__, __LINE__)

#include <iostream>
#include <string>
#include <windows.h>

enum Color {
    BLACK, BLUE, GREEN, CYAN, RED, MAGENTA, BROWN, LIGHTGRAY, DARKGRAY, LIGHTBLUE, LIGHTGREEN, LIGHTCYAN, LIGHTRED, LIGHTMAGENTA, YELLOW, WHITE
};

class DebugPrint {
public:
    void Initialize();

    void TextColor(Color color);

    void Print(std::string message, Color color, const char *funcName, int lineNum);

private:
};

#endif//UNTITLED_PRINTING_H
