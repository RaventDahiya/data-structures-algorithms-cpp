#include <iostream>
#include <string>
using namespace std;

int main() {
    int a;
    char l[100];
    cin >> a;
    cin.ignore();  // ✅ clear '\n' from buffer
    cin.getline(l, 100);  // ✅ read full line into l
    cout << a << endl;
    cout << l << endl;
    return 0;
}
