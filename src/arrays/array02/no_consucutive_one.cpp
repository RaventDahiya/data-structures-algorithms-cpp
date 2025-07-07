#include <iostream>
using namespace std;

int countBinary(int n, int lastDigit) {

    if (n == 0) return 1;

    if (lastDigit == 0) {
        return countBinary(n - 1, 0) + countBinary(n - 1, 1);
    }
    else {
        return countBinary(n - 1, 0);
    }
}


int main() {
    int n = 3;
    cout << "Total valid binary strings of length " << n << ": " << countBinary(n - 1, 0) + countBinary(n - 1, 1);
    return 0;
}
