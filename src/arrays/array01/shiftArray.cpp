#include <iostream>
using namespace std;

int main() {
    int arr[] = { 1,2,3,4,5 };
    int n = 5;
    int temp[n];
    copy(arr, arr + 5, temp);

    for (int i = 0;i < n;i++) {
        arr[i + 2] = temp[i];
    }
    arr[0] = temp[n - 1];
    for (int i = 0;i < n;i++) {
        cout << arr[i] << " ";
    }
    return 0;
}