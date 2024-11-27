
#include <iostream>
#include <fstream>
#include <Windows.h>
using namespace std;


// Функція для створення початкового бінарного файлу
void createBinaryFile(const char* fileName) {
    ofstream outFile(fileName, ios::binary);
    if (!outFile.is_open()) {
        cout << "Не вдалося створити файл: " << fileName << endl;
        return;
    }

    cout << "Введіть символи для запису у файл (для завершення введіть '!'): ";
    char ch;
    while (true) {
        cin >> ch;
        if (ch == '!') break;
        outFile.write((char*)&ch, sizeof(char));
    }
    outFile.close();
}

// Перевірка, чи є символ латинською буквою
bool isLatinLetter(char ch) {
    return (ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z');
}

// Функція для копіювання латинських літер у новий файл
void copyLatinLetters(const char* inputFileName, const char* outputFileName) {
    ifstream inFile(inputFileName, ios::binary);
    if (!inFile.is_open()) {
        cout << "Не вдалося відкрити файл: " << inputFileName << endl;
        return;
    }

    ofstream outFile(outputFileName, ios::binary);
    if (!outFile.is_open()) {
        cout << "Не вдалося створити файл: " << outputFileName << endl;
        inFile.close();
        return;
    }

    char ch;
    while (inFile.read((char*)&ch, sizeof(char))) {
        if (isLatinLetter(ch)) {
            outFile.write((char*)&ch, sizeof(char));
        }
    }

    inFile.close();
    outFile.close();
}

// Функція для виведення вмісту файлу
void displayFileContent(const char* fileName) {
    ifstream inFile(fileName, ios::binary);
    if (!inFile.is_open()) {
        cout << "Не вдалося відкрити файл: " << fileName << endl;
        return;
    }

    cout << "Вміст файлу " << fileName << ": ";
    char ch;
    while (inFile.read((char*)&ch, sizeof(char))) {
        cout << ch;
    }
    cout << endl;
    inFile.close();
}

int main() {

    SetConsoleCP(1251);        // Налаштування кодування для вводу
    SetConsoleOutputCP(1251); // Налаштування кодування для виводу

    char sourceFileName[256], resultFileName[256];

    cout << "Введіть ім'я початкового файлу: ";
    cin >> sourceFileName;
    createBinaryFile(sourceFileName);

    cout << "Введіть ім'я результуючого файлу: ";
    cin >> resultFileName;

    copyLatinLetters(sourceFileName, resultFileName);

    displayFileContent(resultFileName);

    return 0;
}
