#ifndef NODE_H
#define NODE_H

struct Node {
    Node* left;
    Node* right;
    char symbol;
    int frequency;

    Node(char s, int f) {
        symbol = s;
        frequency = f;
        left = nullptr;
        right = nullptr;
    }
};

#endif