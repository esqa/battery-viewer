#ifndef UNTITLED_MAIN_H
#define UNTITLED_MAIN_H
#define DEBUGPRINT(x) std::cout << "[+] "<< x << std::endl

enum Color {
    BLACK, BLUE, GREEN, CYAN, RED, MAGENTA, BROWN, LIGHTGRAY, DARKGRAY, LIGHTBLUE, LIGHTGREEN, LIGHTCYAN, LIGHTRED, LIGHTMAGENTA, YELLOW, WHITE
};

class EntryPoint {
    public:
        void Initialize();

        void Constructor();

        void TextColor(Color color);

    private:
};

#endif//UNTITLED_MAIN_H