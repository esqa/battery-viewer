#include "printing.h"

void DebugPrint::TextColor(Color color) // NOLINT
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void DebugPrint::DebugLog(std::string message, Color color, const char* function_name, int line_number) // NOLINT
{
    TextColor(color); // get color

    std::cout << "[" << function_name << "@" << line_number << "] " << message << std::endl;

    TextColor(WHITE); // restore color
}

void DebugPrint::Print(std::string message, Color color) // NOLINT
{
    TextColor(color); // get color

    std::cout << message << std::endl;

    TextColor(WHITE); // restore color
}