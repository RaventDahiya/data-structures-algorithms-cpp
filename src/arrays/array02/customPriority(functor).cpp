#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <string>
using namespace std;

class student {
    int marks;
    string name;
public:
    student(int m, string n) : marks(m), name(n) {}
    int getMarks() const { return marks; }
    string getName() const { return name; }
};
class comp {
public:
    bool operator()(const student& a, const student& b) {
        return a.getMarks() > b.getMarks();
    }
};

int main() {

    // priority_queue<int> pq; //max heap -> priority_queue<int, vector<int>, less<int>> pq; //max heap
    // priority_queue<int, vector<int>, greater<int>> minHeap; //min heap

    priority_queue<student, vector<student>, comp> pq;
    pq.push(student(23, "Alice"));
    pq.push(student(43, "Bob"));
    pq.push(student(1, "Charlie"));
    pq.push(student(21, "David"));

    while (!pq.empty()) {
        const student& a = pq.top();
        cout << a.getName() << " " << a.getMarks() << endl;
        pq.pop();
    }
    return 0;
}