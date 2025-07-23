#include <iostream>
#include <queue>
#include <vector>

using namespace std;

void demoPriorityQueue() {
    // Max Heap (default)
    priority_queue<int> maxHeap;
    maxHeap.push(10);
    maxHeap.push(5);
    maxHeap.push(15);
    maxHeap.push(20);

    cout << "Max-Heap (Largest to Smallest): ";
    while (!maxHeap.empty()) {
        cout << maxHeap.top() << " ";
        maxHeap.pop();
    }
    cout << endl;

    // Min Heap
    priority_queue<int, vector<int>, greater<int>> minHeap;
    minHeap.push(10);
    minHeap.push(5);
    minHeap.push(15);
    minHeap.push(20);

    cout << "Min-Heap (Smallest to Largest): ";
    while (!minHeap.empty()) {
        cout << minHeap.top() << " ";
        minHeap.pop();
    }
    cout << endl;
}

int main() {
    demoPriorityQueue();
    return 0;
}
