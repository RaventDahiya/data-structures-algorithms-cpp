#include <iostream>
using namespace std;

int total_ways(int n) {
    if (n == 0) return 1;
    if (n == 1) return 1;
    if (n == 2) return 2;
    if (n < 0) return 0;
    return total_ways(n - 1) + (n - 1) * total_ways(n - 2);
}


int main() {
    cout << total_ways(4);
    return 0;
}
