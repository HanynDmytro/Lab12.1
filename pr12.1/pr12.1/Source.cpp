
#include <iostream>
#include <fstream>
#include <Windows.h>
using namespace std;


// ������� ��� ��������� ����������� �������� �����
void createBinaryFile(const char* fileName) {
    ofstream outFile(fileName, ios::binary);
    if (!outFile.is_open()) {
        cout << "�� ������� �������� ����: " << fileName << endl;
        return;
    }

    cout << "������ ������� ��� ������ � ���� (��� ���������� ������ '!'): ";
    char ch;
    while (true) {
        cin >> ch;
        if (ch == '!') break;
        outFile.write((char*)&ch, sizeof(char));
    }
    outFile.close();
}

// ��������, �� � ������ ���������� ������
bool isLatinLetter(char ch) {
    return (ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z');
}

// ������� ��� ��������� ���������� ���� � ����� ����
void copyLatinLetters(const char* inputFileName, const char* outputFileName) {
    ifstream inFile(inputFileName, ios::binary);
    if (!inFile.is_open()) {
        cout << "�� ������� ������� ����: " << inputFileName << endl;
        return;
    }

    ofstream outFile(outputFileName, ios::binary);
    if (!outFile.is_open()) {
        cout << "�� ������� �������� ����: " << outputFileName << endl;
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

// ������� ��� ��������� ����� �����
void displayFileContent(const char* fileName) {
    ifstream inFile(fileName, ios::binary);
    if (!inFile.is_open()) {
        cout << "�� ������� ������� ����: " << fileName << endl;
        return;
    }

    cout << "���� ����� " << fileName << ": ";
    char ch;
    while (inFile.read((char*)&ch, sizeof(char))) {
        cout << ch;
    }
    cout << endl;
    inFile.close();
}

int main() {

    SetConsoleCP(1251);        // ������������ ��������� ��� �����
    SetConsoleOutputCP(1251); // ������������ ��������� ��� ������

    char sourceFileName[256], resultFileName[256];

    cout << "������ ��'� ����������� �����: ";
    cin >> sourceFileName;
    createBinaryFile(sourceFileName);

    cout << "������ ��'� ������������� �����: ";
    cin >> resultFileName;

    copyLatinLetters(sourceFileName, resultFileName);

    displayFileContent(resultFileName);

    return 0;
}
