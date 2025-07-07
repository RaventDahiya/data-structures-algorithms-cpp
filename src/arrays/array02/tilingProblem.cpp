#include <iostream>
using namespace std;

void totalWays(int n, int& ans) {
    if (n < 0) return;
    if (n <= 3) {
        ans++;
        return;
    }
    if (n == 4) {
        ans = ans + 2;
        return;
    }

    totalWays(n - 1, ans);  // Take step of size 1
    totalWays(n - 4, ans);  // Take step of size 4
}

int main() {
    int ans = 0;
    int n = 6;
    totalWays(n, ans);
    cout << "Total ways: " << ans << endl;
    return 0;
}
