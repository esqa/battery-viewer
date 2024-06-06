#include <windows.h>

#include "../debugging/debug.h"
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

        m_window_center = std::abs(m_window_width / 2);

        Padding();

        if (!m_window_center) {
            debug_start.Assert("Center is 0", "Error", MB_ICONERROR);
        }

        std::string width_string = std::to_string(m_window_width);
        std::string height_string = std::to_string(m_window_height);

        if (m_resize_state) { // window was resized
            system("cls"); // reset everything

            debug_start.Print(m_window_padding + "Want to exit program?", LIGHTGRAY);
            debug_start.Print(m_window_padding + "  Press 'Y' to exit", DARKGRAY);
        }


        if (GetAsyncKeyState('Y') & 0x8000) {
            m_wants_to_exit_program = true;
        }
    }
}

void UserInterface::Padding() {
    // I don't know how to use for loops properly, can't use switch case here, unfortunately.
    if (m_window_center > padding_large) {
        m_window_padding = "                                                                                    ";
    } else if (m_window_center > padding_medium ) {
        m_window_padding = "                                                              ";
    } else if (m_window_center > padding_small) {
        m_window_padding = "                                                ";
    } else if (m_window_center > padding_smallest) {
        m_window_padding = "                                  ";
    } else {
        m_window_padding = "                ";
    }
}