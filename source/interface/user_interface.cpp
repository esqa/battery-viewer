#include <windows.h>

#include "../debug/printing.h"
#include "../main/main.h"
#include "user_interface.h"

void UserInterface::DisplayMenu() {
    DebugPrint debug_start{};

    HWND hwnd = GetConsoleWindow();
    RECT rect;

    GetWindowRect(hwnd, &rect);

    m_previous_window_rect = rect;
    m_wants_to_exit_program = false;

    debug_start.Print("Want to exit program?", LIGHTGRAY);
    debug_start.Print("  Press 'Y' to exit", DARKGRAY);

    while (!m_wants_to_exit_program) {
        GetWindowRect(hwnd, &rect);

        m_resize_state = false;

        if (rect.right - rect.left != m_previous_window_rect.right - m_previous_window_rect.left ||
            rect.bottom - rect.top != m_previous_window_rect.bottom - m_previous_window_rect.top) {

            m_previous_window_rect = rect;
            m_resize_state = true;
        }

        m_window_width = m_previous_window_rect.left - m_previous_window_rect.right;
        m_window_height = m_previous_window_rect.top - m_previous_window_rect.bottom;

        int center = std::abs(m_window_width / 2);

        std::string padding;

        // I don't know how to use for loops properly, can't use switch case here, unfortunately.
        if (center > padding_large) {
            padding = "                                                                                    ";
        } else if (center > padding_medium ) {
            padding = "                                                              ";
        } else if (center > padding_small) {
            padding = "                                                ";
        } else if (center > padding_smallest) {
            padding = "                                  ";
        } else {
            padding = "                ";
        }

        std::string width_string = std::to_string(m_window_width);
        std::string height_string = std::to_string(m_window_height);

        if (m_resize_state) { // window was resized
            system("cls"); // reset everything
            
            debug_start.Print(padding + "Want to exit program?", LIGHTGRAY);
            debug_start.Print(padding + "  Press 'Y' to exit", DARKGRAY);
        }

        if (GetAsyncKeyState('Y') & 0x8000) {
            m_wants_to_exit_program = true;
        }
    }
}