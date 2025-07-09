#include <iostream>
#include <vector>
#include <string>
using namespace std;

void subSeq(vector<char>& given, string s, vector<string>& ans, int i) {
    if (i == given.size()) { // Fix: should be ==
        ans.push_back(s);
        return;
    }
    // Exclude current character
    subSeq(given, s, ans, i + 1);
    // Include current character
    subSeq(given, s + given[i], ans, i + 1);
}

int main() {
    vector<string> ans;
    vector<char> given = { 'a', 'b', 'c' }; // Fix: correct initialization
    subSeq(given, "", ans, 0);
    for (string i : ans) {
        cout << i << endl;
    }
    return 0;
}