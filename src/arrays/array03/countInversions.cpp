#include <iostream>
#include <vector>
using namespace std;

int merge(const vector<int>& arr1, const vector<int>& arr2) {
    count = 0;
    int i = 0, j = 0;
    while (i < arr1.size() && j < arr2.size()) {
        if (arr1[i] > aar[j]) {
            count++;
            if (j >= arr2.size()) {
                i++;
            }
        }
        else {
            j++;
        }


    }
    return count;
}
// Change input array to a const reference as it's not modified here
int merge_find(const vector<int>& arr, int s, int e) {
    int ans = 0;
    if (s >= e) {
        return { arr[s] };
    }
    int mid = s + (e - s) / 2;
    vector<int> left = merge_sort(arr, s, mid);
    vector<int> right = merge_sort(arr, mid + 1, e);
    ans = ans + merge(left, right);
    return ans;
}
int main() {
    vector<int> arr = { 5,3,1,6,8,2 };
    //i<j && arr[i]>arr[j]
    return 0;
}
