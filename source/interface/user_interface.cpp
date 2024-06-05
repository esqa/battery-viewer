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

        int center = m_window_width / 10;

        std::string width_string = std::to_string(m_window_width);
        std::string height_string = std::to_string(m_window_height);

        if (m_resize_state) { // window was resized
            system("cls"); // reset everything

            //add a blank before the text using center

            int values[] = {1, 2, 3, 4, 5};
            int n = sizeof(values) / sizeof(values[0]);

            for (int i = 0; i < n; ++i) {
                std::cout << values[i] << " ";
            }

            debug_start.Print("Want to exit program?", LIGHTGRAY);
            debug_start.Print("Press 'Y' to exit", DARKGRAY);
            debug_start.Print(std::to_string(center), LIGHTRED);

            debug_start.DEBUG_PRINT(width_string + " " + height_string, LIGHTRED); // NOLINT
        }

        if (GetAsyncKeyState('Y') & 0x8000) {
            m_wants_to_exit_program = true;
        }
    }
}
