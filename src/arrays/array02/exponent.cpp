#include <iostream>
using namespace std;

int expo(int n, int p) {
    if (p == 1) return n;
    return n * expo(n, p - 1);
}


int main() {
    int n = 2;
    int p = 5;
    cout << expo(n, p);
    return 0;
}