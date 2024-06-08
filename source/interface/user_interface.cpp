#include <windows.h>

#include "../debugging/debug.h"
#include "../input_manager/input.h"
#include "../main/main.h"

#include "user_interface.h"

void UserInterface::DisplayMenu() { //NOLINT
    DebugPrint debug_start{};
    InputManager input_start{};

    HWND hwnd = GetConsoleWindow();
    RECT rect;

    GetWindowRect(hwnd, &rect);

    m_previous_window_rect = rect;
    m_wants_to_exit_program = false;

    m_main_menu = true;
    m_settings_menu = false;

    ExitNavigation();
    Navigation();

    debug_start.Print(m_window_padding + "Main menu", LIGHTCYAN);

    m_window_center = 1000;

    while (!m_wants_to_exit_program) {
        GetWindowRect(hwnd, &rect);

        window_resize_state = false;

        if (rect.right - rect.left != m_previous_window_rect.right - m_previous_window_rect.left ||
            rect.bottom - rect.top != m_previous_window_rect.bottom - m_previous_window_rect.top) {

            m_previous_window_rect = rect;
            window_resize_state = true;
        }

        m_window_width = std::abs(m_previous_window_rect.left - m_previous_window_rect.right);
        m_window_height = std::abs(m_previous_window_rect.top - m_previous_window_rect.bottom);

        m_window_center = std::abs(m_window_width / 2);

        Padding();

        if (m_window_width < MINIMUM_WINDOW_WIDTH || m_window_height < MINIMUM_WINDOW_HEIGHT) {
            DEBUG_ASSERT("Window is too small", "Window Size", MB_ICONERROR);
            SetWindowPos(hwnd, HWND_TOP, 0, 0, 800, 600, SWP_NOMOVE);
        }

        std::string width_string = std::to_string(m_window_width);
        std::string height_string = std::to_string(m_window_height);

        if (window_resize_state || input_start.IsKeyPressed(ONE)) {// window was resized
            ClearScreen();  // reset everything

            ExitNavigation();
            Navigation();

            debug_start.Print(m_window_padding + "Main menu", LIGHTCYAN);
        }

        if (input_start.MultipleKeyPressed(VK_CONTROL, VK_OEM_PLUS)) {
            m_wants_to_exit_program = true;
        }

        if (input_start.IsKeyPressed(TWO)) {
            SettingsMenu();
        }

        if (input_start.IsKeyPressed(THREE) && (!m_settings_menu || !m_main_menu)) {
            DirectoryMenu();
        }
    }
}

void UserInterface::SettingsMenu() { //NOLINT
    DebugPrint debug_start{};
    InputManager input_start{};

    ClearScreen();

    ExitNavigation();
    Navigation();

    m_main_menu = false;
    m_settings_menu = true;

    debug_start.Print(m_window_padding + "Settings Menu", LIGHTCYAN);
    debug_start.Blank();
    debug_start.Print(m_window_padding + "Enter input mode? (y/n)", RED);
    debug_start.Blank();

    std::string input_mode_selection;

    std::cin >> input_mode_selection;

    if (std::string_view {input_mode_selection}.contains("y")) {
        m_input_mode = true;
    } else {
        m_input_mode = false;
    }

    if (m_input_mode) {
        std::cout << m_window_padding + "Enter color: ";

        std::cin.clear();

        std::cin >> m_user_input;

        if (std::string_view{m_user_input}.contains("blue")) {
            debug_start.Blank();
            debug_start.Print(m_window_padding + "This is an example.", BLUE);
            debug_start.Blank();
            Sleep(500);
            ClearScreen();
            DisplayMenu(); // return to main menu
        } else {
            SettingsMenu(); // restart settings menu
        }
    }
}

void UserInterface::DirectoryMenu() {
    DebugPrint debug_start{};

    ClearScreen();

    ExitNavigation();
    Navigation();

    m_main_menu = false;
    m_settings_menu = false;

    debug_start.Print(m_window_padding + "Directory Menu", LIGHTCYAN);
    debug_start.Blank();
}

void UserInterface::Padding() { //NOLINT
    // I don't know how to use for loops properly, can't use switch case here, unfortunately.
    if (m_window_center > padding_large) {
        m_window_padding = "                                                                                    ";
    } else if (m_window_center > padding_medium) {
        m_window_padding = "                                                              ";
    } else if (m_window_center > padding_small) {
        m_window_padding = "                                                ";
    } else if (m_window_center > padding_smallest) {
        m_window_padding = "                                  ";
    } else {
        m_window_padding = "                ";
    }
}

void UserInterface::Navigation() {
    DebugPrint debug_start{};

    debug_start.Blank();
    debug_start.Print(m_window_padding + ASK_USER_OPTION_MAIN, DARKGRAY);
    debug_start.Print(m_window_padding + ASK_USER_OPTION_SETTINGS, DARKGRAY);
    debug_start.Print(m_window_padding + ASK_USER_OPTION_DIRECTORY, DARKGRAY);
    debug_start.Blank();
}

void UserInterface::ExitNavigation() {
    DebugPrint debug_start{};

    debug_start.Print(m_window_padding + ASK_USER_EXIT, LIGHTGRAY);
    debug_start.Print(m_window_padding + EXIT_PROGRAM_HINT, DARKGRAY);
}

void UserInterface::ClearScreen() { //NOLINT
    system("cls");
}
