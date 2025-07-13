#include <iostream>
#include <vector>

using namespace std;

// Helper function to merge two sorted sub-arrays and count inversions
long long merge(vector<int>& arr, int s, int mid, int e) {
    long long inversion_count = 0;
    vector<int> temp; // Temporary array to store the merged result

    int i = s;       // Starting index for the left sub-array
    int j = mid + 1; // Starting index for the right sub-array

    while (i <= mid && j <= e) {
        if (arr[i] <= arr[j]) {
            temp.push_back(arr[i++]);
        }
        else {
            // If arr[i] > arr[j], it's an inversion.
            // All remaining elements in the left sub-array (from arr[i] to arr[mid])
            // will also be greater than arr[j].
            temp.push_back(arr[j++]);
            inversion_count += (mid - i + 1);
        }
    }

    // Copy remaining elements from the left sub-array, if any
    while (i <= mid) {
        temp.push_back(arr[i++]);
    }

    // Copy remaining elements from the right sub-array, if any
    while (j <= e) {
        temp.push_back(arr[j++]);
    }

    // Copy the sorted elements from temp back to the original array
    for (int k = 0; k < temp.size(); ++k) {
        arr[s + k] = temp[k];
    }

    return inversion_count;
}

// Main recursive function to sort the array and count inversions
long long merge_sort(vector<int>& arr, int s, int e) {
    long long inversion_count = 0;
    if (s < e) {
        int mid = s + (e - s) / 2;
        // Count inversions in the left part
        inversion_count += merge_sort(arr, s, mid);
        // Count inversions in the right part
        inversion_count += merge_sort(arr, mid + 1, e);
        // Count inversions between the two parts while merging
        inversion_count += merge(arr, s, mid, e);
    }
    return inversion_count;
}


int main() {
    vector<int> arr = { 5, 3, 1, 6, 8, 2 };
    cout << "Original array: ";
    for (int val : arr) cout << val << " ";
    cout << endl;

    long long inversions = merge_sort(arr, 0, arr.size() - 1);

    cout << "Number of inversions: " << inversions << endl;

    cout << "Sorted array: ";
    for (int val : arr) cout << val << " ";
    cout << endl;

    return 0;
}
