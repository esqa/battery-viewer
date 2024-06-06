#ifndef UNTITLED_DEBUG_H
#define UNTITLED_DEBUG_H

#include <Windows.h>
#include <iostream>
#include <string>

#define DEBUG_PRINT(message, color) DebugLog(message, color, __func__, __LINE__)

#define DEBUG_ASSERT(message, title, type) \
    DebugPrint::Assert(message, title, type, __func__, __LINE__)

enum Color {
    BLACK, BLUE, GREEN, CYAN, RED, MAGENTA, BROWN, LIGHTGRAY, DARKGRAY, LIGHTBLUE, LIGHTGREEN, LIGHTCYAN, LIGHTRED, LIGHTMAGENTA, YELLOW, WHITE
};

class DebugPrint {
    public:
        void DebugLog(std::string message, Color color, const char *function_name, int line_number);

        void Print(std::string message, Color color);

        static void Assert(std::string message, std::string title, UINT type, const char* calling_function, int calling_line);

        void Blank();

    private:
        void TextColor(Color color);
};

#endif//UNTITLED_DEBUG_H
