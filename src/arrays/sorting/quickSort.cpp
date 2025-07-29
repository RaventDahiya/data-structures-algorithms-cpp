#include <iostream>
#include <vector>
using namespace std;

vector<int> quick_sor(const vector<int>& arr, int s, int e) {

}

int main() {
    vector<int> arr = { 5,3,2,12,31,4 };
    // Store the result in a new vector, as this is not an in-place sort
    vector<int> sorted_arr = quick_sort(arr, 0, arr.size() - 1);
    for (int val : sorted_arr) {
        cout << val << " ";
    }
    cout << endl;
    return 0;
}
