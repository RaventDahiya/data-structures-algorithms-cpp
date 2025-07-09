#include <iostream>
using namespace std;

void printAllBracket(int n, char* ans, int o, int c, int i) {
    if (i == 2 * n) {
        ans[i] = '\0';
        cout << ans << endl; // Print the valid sequence
        return;
    }

    if (o < n) {
        ans[i] = '(';
        printAllBracket(n, ans, o + 1, c, i + 1);
    }
    if (o > c) {
        ans[i] = ')';
        printAllBracket(n, ans, o, c + 1, i + 1);
    }
}

int main() {
    char ans[100];
    printAllBracket(2, ans, 0, 0, 0);
    return 0;
}