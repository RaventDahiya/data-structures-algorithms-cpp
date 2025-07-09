#include <iostream>
#include <vector>
using namespace std;

int max_profit(vector<int>& wt, vector<int>& price, int c, int i) {
    if (i == wt.size()) {
        return 0;
    }

    // Exclude the current item
    int exclude = max_profit(wt, price, c, i + 1);

    // Include the current item (only if within capacity)
    int include = 0;
    if (wt[i] <= c) {
        include = price[i] + max_profit(wt, price, c - wt[i], i + 1)
    }

    return max(include, exclude);
}

int main() {
    vector<int> wt = { 1, 2, 3, 4, 5 };
    vector<int> price = { 23, 56, 32, 12, 5 };
    int capacity = 6;
    cout << max_profit(wt, price, capacity, 0);
    return 0;
}
