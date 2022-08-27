#include <iostream>
#include <string>
using namespace std;

class TextEditor {
    // Больше 255 символов в память не влезает =/
public:
    char text[255]; // Тип String ещё не изобрели :(
    int textLength; // текущая длина текста в массиве text

    // Пустое место в этом массиве забито просто “пробелами”
    // Например если textLength = 3, и text = {‘ш’,’к’,’я’, … еще 252 символа ‘пробел’ .. }

    void insertCharacterAt(int position, char c) {
        // Эта функция должна вставлять символ в строку на позиции position
        // Например когда пользователь напечатал “При|ет мир!” (этот текст у нас в переменной text)
        // и его курсор находится между буквами “и” и “е”, и он нажимает “в”.
        // В этот момент вызывается функция insertCharacterAt(3, “в”), после чего в переменной text значение меняется на “Привет мир!”
    }

    void backspace(int position) {
        // “Привет Мм|ир!” => “Привет Мир!”
    }

    void print() {
        for (int i = 0; i < textLength; ++i) {
            cout << text[i];
        }
        cout << endl;
    }

    // Конструктор готов!
    TextEditor() {
        textLength = 0;
        for (int i = 0; i < 255; i++) {
            text[i] = ' ';
        }
    }
};

int main(void) {
    TextEditor editor;
    string s = "Hello, world";
    for (int i = 0; i < int(s.size()); ++i) {
        editor.insertCharacterAt(i, s[i]);
    }
    editor.insertCharacterAt(4, 'n');
    editor.insertCharacterAt(4, ' ');
    editor.backspace(10);
    editor.print();
    cout << "Add some more testing";
}