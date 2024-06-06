#include "debug.h"

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

void DebugPrint::Assert(std::string message, std::string title, UINT type, const char* calling_function, int calling_line) //NOLINT
{
    std::string message_box_message = "Assert triggered\n" + std::string(calling_function) + "@" + std::to_string(calling_line) + "\n" + message;

    MessageBoxA(nullptr, message_box_message.c_str(), title.c_str(), type);
}

void DebugPrint::Blank() //NOLINT
{
    std::cout << std::endl;
}

