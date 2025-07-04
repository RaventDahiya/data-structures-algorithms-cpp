#include <iostream>
using namespace std;

bool isSorted(int arr[], int i, int n) {
    if ((i + 1) == n) return 1;
    if (arr[i] > arr[i + 1]) return 0;
    return isSorted(arr, i + 1, n);
}

int main() {
    int arr[] = { 1,2,7,4,5 };
    int size = 5;
    cout << isSorted(arr, 0, size);
    return 0;
}
