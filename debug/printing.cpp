#include "printing.h"

void DebugPrint::TextColor(Color color) { // NOLINT
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}
void DebugPrint::Print(std::string message, Color color, const char* funcName, int lineNum) { // NOLINT
    TextColor(color); // get color

    std::cout << "[" << funcName << "@" << lineNum << "] " << message << std::endl;

    TextColor(WHITE); // restore color
}