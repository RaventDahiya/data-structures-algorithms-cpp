#include <vector>
#include<iostream>
using namespace std;

void reverse(string& s, int i, int j) {
    if (j >= i) {
        return;
    }
    swap(s[i], s[j]);
    reverse(s, i + 1, j - 1);
}
int main() {
    string s = "abcdefg";
    cout << s << endl;
    reverse(s, 0, s.length());
    cout << s << endl;
    return 0;
}