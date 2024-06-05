#include <windows.h>

#include "../debug/printing.h"
#include "../main/main.h"
#include "user_interface.h"

void UserInterface::DisplayMenu() {
    DebugPrint debug_start{};

    RECT rect;

    HWND hwnd = GetConsoleWindow();

    wants_to_exit_program = false;

    debug_start.Print("Want to exit program?", LIGHTGRAY);
    debug_start.Print("Press 'Y' to exit", DARKGRAY);

    if(GetWindowRect(hwnd, &rect))
    {
        int width = rect.right - rect.left;
        int height = rect.bottom - rect.top;

        std::string width_str = std::to_string(width);
        std::string height_str = std::to_string(height);

        debug_start.Print(width_str, LIGHTGREEN);
        debug_start.Print(height_str, LIGHTGREEN);
    }

    while (!wants_to_exit_program) {
        exit_state = false;

        if (GetAsyncKeyState('Y') & 0x8000) {
            wants_to_exit_program = true;
        }
    }
}
