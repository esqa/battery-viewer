#ifndef UNTITLED_USER_INTERFACE_H
#define UNTITLED_USER_INTERFACE_H

#define ASK_USER_EXIT             "     Want to exit program?"
#define ASK_USER_OPTION_MAIN      "1 to enter the main menu"
#define ASK_USER_OPTION_SETTINGS  "2 to enter the settings menu"
#define ASK_USER_OPTION_DIRECTORY "3 to enter directory menu"

#define MINIMUM_WINDOW_WIDTH 250
#define MINIMUM_WINDOW_HEIGHT 100

#define EXIT_PROGRAM_HINT " Press 'CTRL' and '+' to exit"

enum Padding {
    padding_large = 700,
    padding_medium = 600,
    padding_small = 500,
    padding_smallest = 250,
    padding_count = 5
};

enum MenuOptions {
    menu_main = 1,
    menu_settings,
    menu_directory
};

class UserInterface {
    public:
        void DisplayMenu();

        bool window_resize_state;

    private:
        int m_window_width;
        int m_window_height;
        int m_window_center;

        Color m_input_color;

        std::string m_user_input;
        std::string m_window_padding;

        bool m_wants_to_exit_program;
        bool m_settings_menu;
        bool m_main_menu;
        bool m_input_mode;

        RECT m_previous_window_rect;

        void Padding();

        void SettingsMenu();

        void DirectoryMenu();

        void Navigation();

        void ExitNavigation();

        void ClearScreen();
};

#endif //UNTITLED_USER_INTERFACE_H
