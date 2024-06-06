#include "input.h"

void InputManager::GetKeyboardInput(int key) // NOLINT
{
    GetAsyncKeyState(key);
}

bool InputManager::IsKeyPressed(int key) // NOLINT
{
    if (GetAsyncKeyState(key) & 0x8000) {
        return true;
    } else {
        return false;
    }
}
bool InputManager::MultipleKeyPressed(int key1, int key2) // NOLINT
{
    if (GetAsyncKeyState(key1) & 0x8000 && GetAsyncKeyState(key2) & 0x8000) {
        return true;
    } else {
        return false;
    }
}
