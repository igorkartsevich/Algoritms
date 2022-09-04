#include <iostream>
#include <string>

class TextEditor {
    // Больше 255 символов в память не влезает =/

public:
    // Пустое место в этом массиве забито просто “пробелами”
    // Например если textLength = 3, и text = {‘ш’,’к’,’я’, … еще 252 символа ‘пробел’ .. }
    TextEditor() {
        textLength = 0;
        for (int i = 0; i < 255; i++)
            text[i] = ' ';
    }

    void insertCharacterAt(int position, char c) {
        if (position > 254) {
            std::cerr << "ERROR! The number of positions is greater than the amount of memory";
            return;
        }

        text[position] = c;
        for (auto i = 254; i >= 0; --i) {
            if (text[i] != ' ') {
                textLength = i + 1;
                return;
            }
        }
    }

    void backspace(int position) {
        if (position < textLength)
            for (auto i = position + 1; i < textLength; ++i)
                text[i - 1] = text[i];

        text[textLength--] = ' ';
    }

    void print() {
        for (int i = 0; i < textLength; ++i)
            std::cout << text[i];

        std::cout << std::endl << "Text lenght: " << textLength << std::endl;
    }

private:
    char text[255]; // Тип String ещё не изобрели :(
    int textLength; // текущая длина текста в массиве text

};

int main(void) {
    TextEditor editor;
    std::string s = "Hello, world";
    for (int i = 0; i < int(s.size()); ++i) {
        editor.insertCharacterAt(i, s[i]);
    }
    editor.insertCharacterAt(4, 'n');
    editor.insertCharacterAt(4, ' ');
    editor.backspace(10);
    editor.print();

    TextEditor editor1;
    std::string s1 = "       aaa   ";
    for (int i = 0; i < int(s1.size()); ++i) {
        editor1.insertCharacterAt(i, s1[i]);
    }
    editor1.insertCharacterAt(3, 'b');
    editor1.insertCharacterAt(4, 'b');
    editor1.backspace(10);
    editor1.print();
}