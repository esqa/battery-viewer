#include <windows.h>

#ifndef UNTITLED_INPUT_H
#define UNTITLED_INPUT_H

enum VirtualKeys {

    //A - Z
    A = 0x41,
    B = 0x42,
    C = 0x43,
    D = 0x44,
    E = 0x45,
    F = 0x46,
    G = 0x47,
    H = 0x48,
    I = 0x49,
    J = 0x4A,
    K = 0x4B,
    L = 0x4C,
    M = 0x4D,
    N = 0x4E,
    O = 0x4F,
    P = 0x50,
    Q = 0x51,
    R = 0x52,
    S = 0x53,
    T = 0x54,
    U = 0x55,
    V = 0x56,
    W = 0x57,
    X = 0x58,
    Y = 0x59,
    Z = 0x5A,

    //0 - 9
    ZERO = 0x30,
    ONE = 0x31,
    TWO = 0x32,
    THREE = 0x33,
    FOUR = 0x34,
    FIVE = 0x35,
    SIX = 0x36,
    SEVEN = 0x37,
    EIGHT = 0x38,
    NINE = 0x39
};

class InputManager {
    public:
        void GetKeyboardInput(int key);

        bool IsKeyPressed(int key);

        bool MultipleKeyPressed(int key1, int key2);
};


#endif//UNTITLED_INPUT_H
