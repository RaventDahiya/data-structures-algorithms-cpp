#include <iostream>
#include<vector>
#include <algorithm>
#include <numeric>
using namespace std;

bool can_cut(vector<long long int>trees, long long int m, long long int mid) {
    long long int sum = 0;
    for (long long int i = 0;i < trees.size();i++) {
        if (mid <= trees[i]) {
            sum = sum + trees[i] - mid;
        }
    }
    return sum >= m;
}

long long int eko_eko(vector<long long int>trees, long long int m) {
    long long int s = 0;
    long long int e = *max_element(trees.begin(), trees.end());
    long long int ans = -1;
    while (s <= e) {
        long long int mid = s + (e - s) / 2;
        if (can_cut(trees, m, mid)) {
            ans = mid;
            s = mid + 1;
        }
        else {
            e = mid - 1;
        }
    }
    return ans;

}

int main() {

    long long int n, m;
    cin >> n >> m;
    vector<long long int>trees;
    while (n--) {
        long long int ht;
        cin >> ht;
        trees.push_back(ht);
    }
    cout << eko_eko(trees, m) << endl;

    return 0;
}