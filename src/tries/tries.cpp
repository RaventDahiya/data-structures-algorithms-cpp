#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
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
TrieNode* searchPrefix(TrieNode* root, string word) {
    if (word.empty()) return root;
    char ch = word[0];
    if (root->children.find(ch) == root->children.end()) {
        cout << "no prefix present" << endl;
        return nullptr;
    }
    return searchPrefix(root->children[ch], word.substr(1));
}

void suggested_words(TrieNode* prefixRoot, string prefix, vector<string>& ans) {
    if (prefixRoot->isTerminal) {
        ans.push_back(prefix);
    }
    for (auto p : prefixRoot->children) {
        suggested_words(p.second, prefix + p.first, ans);
    }

}

int main() {
    TrieNode* root = new TrieNode('-');
    insertTrie(root, "cover");
    cout << search(root, "cover");
    deleteWord(root, "cover");
    cout << search(root, "cover") << endl;

    insertTrie(root, "apple");
    insertTrie(root, "apply");
    insertTrie(root, "appiiiiiiii");
    insertTrie(root, "apricot");
    insertTrie(root, "aandu");
    insertTrie(root, "apoo");
    insertTrie(root, "appzi");

    vector<string> suggestions;
    suggested_words(searchPrefix(root, "a"), "a", suggestions);
    sort(suggestions.begin(), suggestions.end());
    for (const string& s : suggestions) {
        cout << s << endl;
    }


    return 0;
}
