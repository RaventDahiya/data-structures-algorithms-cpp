#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
class comp {
public:
    bool operator()(int a, int b) {
        return a > b;
    }
};
int main() {

    vector<int>v = { 23,43,1,21,9,8 };
    sort(v.begin(), v.end(), comp());

    for (int a : v) {
        cout << a << " ";
    }
    return 0;
}