#include <iostream>
#include <vector>
using namespace std;

// Change parameters to const references to accept temporary values
vector<int> merge(const vector<int>& arr1, const vector<int>& arr2) {
    int i = 0, j = 0;
    vector<int> temp;
    while (i < arr1.size() && j < arr2.size()) {
        if (arr1[i] < arr2[j]) {
            temp.push_back(arr1[i]);
            i++;
        }
        else {
            temp.push_back(arr2[j]);
            j++;
        }
    }
    while (i < arr1.size()) {
        temp.push_back(arr1[i]);
        i++;
    }
    while (j < arr2.size()) {
        temp.push_back(arr2[j]);
        j++;
    }
    return temp;

}

// Change input array to a const reference as it's not modified here
vector<int> merge_sort(const vector<int>& arr, int s, int e) {
    if (s >= e) {
        return { arr[s] };
    }
    int mid = s + (e - s) / 2; // Safer way to calculate mid
    // This line now works because merge accepts const references
    return merge(merge_sort(arr, s, mid), merge_sort(arr, mid + 1, e));
}

int main() {
    vector<int> arr = { 5,3,2,12,31,4 };
    // Store the result in a new vector, as this is not an in-place sort
    vector<int> sorted_arr = merge_sort(arr, 0, arr.size() - 1);
    for (int val : sorted_arr) {
        cout << val << " ";
    }
    cout << endl;
    return 0;
}
