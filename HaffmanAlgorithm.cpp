#include <queue>
#include <map>
#include <string>
#include "HaffmanAlgorithm.h"

// построение дерева
Node* buildAlgorithm(string text) {
    map<char, int> freq;
    for (char c : text) {
        freq[c]++;
    }

    priority_queue<Node*, vector<Node*>, CompareNodes> pq;

    for (auto pair : freq) {
        Node* node = new Node(pair.first, pair.second);
        pq.push(node);
    }

    if (pq.empty()) {
        return nullptr;
    }

    while (pq.size() > 1) {
        Node* left = pq.top();
        pq.pop();
        Node* right = pq.top();
        pq.pop();

        Node* newNode = new Node('~', left->frequency + right->frequency);
        newNode->left = left;
        newNode->right = right;
        pq.push(newNode);
    }

    Node* mainNode = pq.top();
    return mainNode;
}

// возврат кодов
void getCodes(Node* mainNode, string code, map<char, string>& codes) {
    if (mainNode == nullptr) return;

    if (mainNode->left == nullptr && mainNode->right == nullptr) {
        codes[mainNode->symbol] = code.empty() ? "0" : code; // если код пустой то 0
        return;
    }

    getCodes(mainNode->left, code + "0", codes);
    getCodes(mainNode->right, code + "1", codes);
}

// удаление из памяти
void deleteTree(Node* root) {
    if (root == nullptr) return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}