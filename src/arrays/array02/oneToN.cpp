#include <iostream>
using namespace std;

void printn(int n) {
    if (n == 0) return;
    printn(n - 1);
    cout << n << endl;
}

void printO(int n) {
    if (n == 0) return;
    cout << n << endl;
    printn(n - 1);

}

int main() {
    int n = 5;
    //printn(n);
    printO(n);
    return 0;
}
