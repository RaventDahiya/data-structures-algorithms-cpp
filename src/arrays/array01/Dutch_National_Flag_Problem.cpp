#include <iostream>
#include <algorithm>  // Corrected spelling
using namespace std;

void sortBinaryArray(int arr[], int size) {
    int zero = 0, one = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] == 0)
            zero++;
        else
            one++;
    }
    fill(arr, arr + zero, 0);
    fill(arr + zero, arr + zero + one, 1);
}

void sortBinaryArrayByPointers(int arr[], int size) {
    int l = 0;
    int h = size - 1;
    while (l <= h) {
        if (arr[l] == 0) {
            l++;
        }
        else if (arr[l] == 1) {
            swap(arr[l], arr[h]);
            h--;
        }
    }
}

void  Dutch_National_Flag_Problem(int arr[], int size) {
    int zero = 0, one = 0, two = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] == 0) {
            zero++;
        }
        else if (arr[i] == 1) {
            one++;
        }
        else {
            two++;
        }

    }
    fill(arr, arr + zero, 0);
    fill(arr + zero, arr + zero + one, 1);
    fill(arr + zero + one, arr + zero + one + two, 2);
}

void dutchNationalFlag(int arr[], int n) {
    int low = 0, mid = 0, high = n - 1;

    while (mid <= high) {
        if (arr[mid] == 0) {
            swap(arr[low], arr[mid]);
            low++;
            mid++;
        }
        else if (arr[mid] == 1) {
            mid++;
        }
        else { // arr[mid] == 2
            swap(arr[mid], arr[high]);
            high--;
        }
    }
}

int main() {
    int a[] = { 1, 1, 0, 0, 0 };
    int size = sizeof(a) / sizeof(a[0]);
    sortBinaryArrayByPointers(a, size);
    //sortBinaryArray(a, size);
    //Dutch_National_Flag_Problem(a, size);
    for (int i = 0; i < size; i++) {
        cout << a[i] << " ";
    }
    return 0;
}
