#include <iostream>
#include <cstring>

using namespace std;

// Рекурсивна функція для перевірки наявності всіх букв "while"
bool containsAllLetters(const char* str, const char* letters) {
    // Базовий випадок: якщо всі літери знайдені
    if (*letters == '\0') return true;

    // Перевірка, чи символ є частиною "while"
    if (strchr(str, *letters)) {
        return containsAllLetters(str, letters + 1); // Перевірити наступну букву
    }

    return false; // Якщо символ не знайдено
}

// Рекурсивна функція для заміни "while" на ""
void replaceWhileWithStars(char* str, int index = 0) {
    const char* target = "while";
    size_t targetLength = strlen(target);

    // Базовий випадок: досягнуто кінець рядка
    if (str[index] == '\0') return;

    // Перевірка наявності "while" у рядку
    if (strncmp(&str[index], target, targetLength) == 0) {
        // Заміна на ""
        str[index] = '*';
        str[index + 1] = '*';

        // Переміщення решти рядка
        strcpy_s(&str[index + 2], strlen(&str[index + 2]) + 1, &str[index + targetLength]);

        // Рекурсивний виклик з оновленим індексом
        replaceWhileWithStars(str, index + 2);
    }
    else {
        // Продовження рекурсії
        replaceWhileWithStars(str, index + 1);
    }
}

int main() {
    const char* letters = "while";
    char input[256];

    cout << "Enter a string: ";
    cin.getline(input, 256);

    if (containsAllLetters(input, letters)) {
        cout << "The string contains all letters from 'while'." << endl;
    }
    else {
        cout << "The string does not contain all letters from 'while'." << endl;
    }

    replaceWhileWithStars(input);
    cout << "Modified string: " << input << endl;

    return 0;
}