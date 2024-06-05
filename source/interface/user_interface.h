#ifndef UNTITLED_USER_INTERFACE_H
#define UNTITLED_USER_INTERFACE_H

class UserInterface {
    public:
        void DisplayMenu();

    private:
        int m_window_width;
        int m_window_height;

        bool m_wants_to_exit_program;
        bool m_resize_state;

        RECT m_previous_window_rect;

};

#endif//UNTITLED_USER_INTERFACE_H
