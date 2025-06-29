#include <iostream>
using namespace std;
void onesCompliment(int arr[], int size) {
    for (int i = 0;i < size;i++) {
        if (arr[i] == 0) {
            arr[i] = 1;
        }
        else {
            arr[i] = 0;
        }
    }
}

void twosCompliment(int arr[], int size) {
    for (int i = 0;i < size;i++) {
        if (arr[i] == 0) {
            arr[i] = 1;
        }
        else {
            arr[i] = 0;
        }
    }
    int carry = 1;
    for (int i = size - 1;i >= 0;i--) {
        if ((arr[i] == 0) && (carry == 1)) {
            arr[i] = 1;
            carry = 0;
        }
        else if ((arr[i] == 1) && (carry == 1)) {
            arr[i] = 0;
            carry = 1;
        }
    }
}
int main() {
    int arr[] = { 1,0,0,1,0 };
    int n = 5;
    //onesCompliment(arr, n);
    twosCompliment(arr, n);
    for (int i = 0;i < n;i++) {
        cout << arr[i] << " ";
    }
    return 0;
}