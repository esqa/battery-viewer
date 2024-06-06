#include <windows.h>

#ifndef UNTITLED_INPUT_H
#define UNTITLED_INPUT_H


class InputManager {
    public:
        void GetKeyboardInput(int key);

        bool IsKeyPressed(int key);

        bool MultipleKeyPressed(int key1, int key2);
};


#endif//UNTITLED_INPUT_H
