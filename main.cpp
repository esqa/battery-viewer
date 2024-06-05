#include <iostream>
#include <windows.h>

#include "main.h"



int main() {
    EntryPoint start{};

    start.Initialize();
}

void EntryPoint::Initialize() {
    DebugPrint("Hello, World!", GREEN);
}
void EntryPoint::TextColor(Color color) { // NOLINT
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}
void EntryPoint::DebugPrint(std::string message, Color color) { // NOLINT
    TextColor(color); // get color

    std::cout << message << std::endl;

    TextColor(WHITE); // restore color
}
