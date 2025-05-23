#include <iostream>
#include <map>
#include <string>
#include "HaffmanAlgorithm.h"

using namespace std;

int main() {
    string text;
    cout << "Введите текст:\n";
    getline(cin, text);

    Node* mainNode = buildAlgorithm(text);

    if (mainNode == nullptr) {
        cout << "Пустая строка!" << endl;
        return 0;
    }

    map<char, string> codes;
    getCodes(mainNode, "", codes);

    cout << "Коды Хаффмана:\n";
    for (auto pair : codes) {
        cout << pair.first << ": " << pair.second << endl;
    }

    string encoded = "";
    for (char c : text) {
        encoded += codes[c];
    }
    cout << "Полученная строка: " << encoded << endl;

    deleteTree(mainNode);

    return 0;
}