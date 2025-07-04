#include <iostream>
using namespace std;

int GCD(int n, int m, int i, int& ans) {
    if (i > n || i > m) return ans;

    if (n % i == 0 && m % i == 0) {
        ans = max(i, ans);
    }
    return GCD(n, m, i + 1, ans);
}

int main() {
    int n = 12;
    int m = 18;
    int ans = 1; // GCD will always be >= 1
    cout << GCD(n, m, 1, ans);  // Start from 1, not 2 (1 might be the GCD in some cases)

    return 0;
}
