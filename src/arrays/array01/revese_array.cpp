#include <iostream>
using namespace std;

void revese_arr(int arr[], int size) {
    int s = 0, e = size - 1;
    while (s <= e) {
        swap(arr[s++], arr[e--]);
    }
}

int main() {
    int a[] = { 1, 2, 3, 4, 5, 6 };
    int size = 6;
    revese_arr(a, size);
    for (int i = 0;i < size;i++) {
        cout << a[i] << " ";
    }
    return 0;
}