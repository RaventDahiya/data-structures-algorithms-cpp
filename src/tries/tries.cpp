#include <iostream>
#include <unordered_map>
using namespace std;

class TrieNode {
public:
    char value;
    unordered_map<char, TrieNode*> children;
    bool isTerminal;

    TrieNode(char data) : value(data), isTerminal(false) {}
};

void insertTrie(TrieNode* root, string word) {
    // Base case: End of word
    if (word.empty()) {
        root->isTerminal = true;
        return;
    }
    char ch = word[0];
    TrieNode* child;
    if (root->children.count(ch)) {
        child = root->children[ch];
    }
    else {
        child = new TrieNode(ch);
        root->children[ch] = child;
    }
    insertTrie(child, word.substr(1));
}

bool search(TrieNode* root, string word) {
    if (word.empty()) {
        return root->isTerminal;
    }
    char ch = word[0];
    TrieNode* child;
    if (root->children.find(ch) != root->children.end()) {
        child = root->children[ch];
    }
    else {
        return false;
    }
    return search(child, word.substr(1));
}
void deleteWord(TrieNode* root, string word) {
    if (word.empty()) {
        if (root->isTerminal) {
            root->isTerminal = false;
        }
        return;
    }
    char ch = word[0];
    TrieNode* child;
    if (root->children.find(ch) != root->children.end()) {
        child = root->children[ch];
    }
    else {
        return;
    }
    deleteWord(child, word.substr(1));
}
int main() {
    TrieNode* root = new TrieNode('-');
    insertTrie(root, "cover");
    cout << search(root, "cover");
    deleteWord(root, "cover");
    cout << search(root, "cover");
    return 0;
}
