#ifndef UNTITLED_USER_INTERFACE_H
#define UNTITLED_USER_INTERFACE_H

enum Padding {
    padding_large = 700,
    padding_medium = 600,
    padding_small = 500,
    padding_smallest = 250,
    padding_count = 5
};

class UserInterface {
    public:
        void DisplayMenu();

        void Padding();

    private:
        int m_window_width;
        int m_window_height;
        int m_window_center;

        std::string m_window_padding;

        bool m_wants_to_exit_program;
        bool m_resize_state;

        RECT m_previous_window_rect;

};

#endif//UNTITLED_USER_INTERFACE_H
