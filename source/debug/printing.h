#ifndef UNTITLED_PRINTING_H
#define UNTITLED_PRINTING_H

#include <Windows.h>
#include <iostream>
#include <string>

#define DEBUG_PRINT(message, color) DebugLog(message, color, __func__, __LINE__)

enum Color {
    BLACK, BLUE, GREEN, CYAN, RED, MAGENTA, BROWN, LIGHTGRAY, DARKGRAY, LIGHTBLUE, LIGHTGREEN, LIGHTCYAN, LIGHTRED, LIGHTMAGENTA, YELLOW, WHITE
};

class DebugPrint {
    public:
        void DebugLog(std::string message, Color color, const char *funcName, int lineNum);

        void Print(std::string message, Color color);

    private:
        void TextColor(Color color);
};

#endif//UNTITLED_PRINTING_H
