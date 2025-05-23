#include <map>
#include <string>
#include "Node.h"

using namespace std;

//?????????? ??? ???????
struct CompareNodes {
    bool operator()(Node* a, Node* b) {
        return a->frequency > b->frequency;
    }
};

//?????????? ???????
Node* buildAlgorithm(string text);
void getCodes(Node* mainNode, string code, map<char, string>& codes);
void deleteTree(Node* root);
