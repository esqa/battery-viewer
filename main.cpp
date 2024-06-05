#include <WinBase.h>
#include <consoleapi2.h>
#include <iostream>
#include <windows.h>

#include "main.h"



int main() {
    EntryPoint start{};

    start.Initialize();

}

void EntryPoint::Initialize() {
    TextColor(LIGHTCYAN);
    DEBUGPRINT("hello from init");
}

void EntryPoint::Constructor() {

}
void EntryPoint::TextColor(Color color) { // NOLINT
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}
