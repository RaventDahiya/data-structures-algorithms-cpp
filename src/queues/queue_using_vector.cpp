#include <iostream>
#include <vector>
using namespace std;

class MyQueue {
    vector<int> q;
    int front = -1;
    int rear = -1;

public:
    MyQueue() {
        front = rear = -1;
    }

    bool isEmpty() {
        return front == -1 || front > rear;
    }

    void enqueue(int data) {
        if (isEmpty()) {
            front = rear = 0;
            q.push_back(data);  // push here
            return;
        }
        rear++;
        q.push_back(data);
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return;
        }
        front++;
    }

    void printQueue() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return;
        }
        for (int i = front; i <= rear; i++) {
            cout << q[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    MyQueue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.printQueue();  // Output: 10 20 30
    q.dequeue();
    q.printQueue();  // Output: 20 30
}
