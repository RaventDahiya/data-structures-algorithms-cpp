#include <iostream>
#include <vector>
using namespace std;

void subArr(vector<int>& a, int start, int end) {
    if (start == a.size()) return;         // base case: all subarrays done
    if (end == a.size()) {
        subArr(a, start + 1, start + 1);    // move to next start index
        return;
    }

    // print subarray from start to end
    for (int i = start; i <= end; i++)
        cout << a[i] << " ";
    cout << endl;

    subArr(a, start, end + 1); // extend current subarray
}

int main() {
    vector<int> arr = { 1, 2, 3, 4, 5 };
    subArr(arr, 0, 0);
    return 0;
}

// TIME : 0(N!) SPACE : O(N)
