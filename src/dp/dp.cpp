#include <iostream>
#include <vector>
using namespace std;
//top to bottom 
// Function to compute Fibonacci using memoization
long long fib(int n, vector<long long>& dp) {
    if (n <= 1) return n;

    if (dp[n] != -1) return dp[n]; // If already computed, return it

    dp[n] = fib(n - 1, dp) + fib(n - 2, dp);
    return dp[n];
}

int main() {
    int n;
    cout << "Enter number of terms: ";
    cin >> n;

    if (n <= 0) {
        cout << "Please enter a positive integer." << endl;
        return 0;
    }

    vector<long long> dp(n + 1, -1); // Initialize DP table

    cout << "Fibonacci series: ";
    for (int i = 0; i < n; i++) {
        cout << fib(i, dp) << " ";
    }
    cout << endl;

    return 0;
}
