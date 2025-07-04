#include <iostream>
using namespace std;

int findFirstIndex(int a[], int n, int t, int i = 0) {
    if (i == n) return -1;      // Base case: reached end without finding
    if (a[i] == t) return i;    // Found target
    return findFirstIndex(a, n, t, i + 1);  // Recursive call with next index
}

int main() {
    int a[] = { 1, 2, 3, 4, 5, 6, 4, 7, 2 };
    int n = sizeof(a) / sizeof(int);
    int t = 2;
    cout << findFirstIndex(a, n, t) << endl;
    return 0;
}

