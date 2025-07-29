#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter number of terms: ";
    cin >> n;

    if (n <= 0) {
        cout << "Please enter a positive integer." << endl;
        return 0;
    }

    int prev0 = 0, prev1 = 1;
    cout << "Fibonacci series: ";
    for (int i = 0; i < n; i++) {
        if (i == 0) {
            cout << prev0 << " ";
        }
        else if (i == 1) {
            cout << prev1 << " ";
        }
        else {
            int next = prev0 + prev1;
            cout << next << " ";
            prev0 = prev1;
            prev1 = next;
        }
    }
    cout << endl;

    return 0;
}
