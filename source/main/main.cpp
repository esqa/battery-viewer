#include "../debugging/debug.h"
#include "../interface/user_interface.h"

#include "main.h"

int main() {
    SetConsoleTitleA("internal");

    UserInterface ui{};
    ui.DisplayMenu();

    return 0;
}