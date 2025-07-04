#include <iostream>
#include <vector>
using namespace std;

bool isPrime(int n) {
    if (n <= 1) return false;
    if (n <= 3) return true;

    if (n % 2 == 0 || n % 3 == 0) return false;

    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    }
    return true;
}

void primeFactorRecursive(int n, int i, vector<int>& ans) {
    if (n == 1) return;

    if (n % i == 0 && isPrime(i)) {
        ans.push_back(i);
        primeFactorRecursive(n / i, i, ans);
    }
    else {
        primeFactorRecursive(n, i + 1, ans);
    }
}

int main() {
    vector<int> ans;
    int n = 12;
    primeFactor(n, 2, ans);

    for (int x : ans) {
        cout << x << " ";
    }

    return 0;
}
