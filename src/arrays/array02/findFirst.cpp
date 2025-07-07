#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int findfirst(int arr[], int s, int e, int t) {
    if (e - s < 0) return -1;
    if (arr[s] == t) {
        return s;
    }
    else {
        return findfirst(arr, s + 1, e, t);
    }
}

int findlast(int arr[], int s, int e, int t) {
    if (e < 0) return -1;
    if (arr[e] == t) {
        return e;
    }
    else {
        return findlast(arr, s, e - 1, t);
    }
}

int main() {
    int arr[] = { 1,2,6,7,4,2,3,4,4,3,2 };
    cout << findlast(arr, 0, 10, 4);
    return 0;
}