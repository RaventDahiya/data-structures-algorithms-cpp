#include <iostream>
#include <vector>
using namespace std;

void fibonacci(int n) {
    if (n <= 0) {
        cout << "Please enter a positive integer." << endl;
        return;
    }

    vector<long long> dp(n);
    dp[0] = 0;
    if (n > 1) dp[1] = 1;

    for (int i = 2; i < n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    cout << "Fibonacci series: ";
    for (int i = 0; i < n; i++) {
        cout << dp[i] << " ";
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Enter number of terms: ";
    cin >> n;

    fibonacci(n);
    return 0;
}
