#include <iostream>
using namespace std;

class FixedQueue {
    int* arr;
    int front;
    int rear;
    int capacity;

public:
    FixedQueue(int cap) {
        capacity = cap;
        arr = new int[capacity];
        front = rear = -1;
    }

    ~FixedQueue() {
        delete[] arr;
    }

    bool isEmpty() {
        return front == -1 || front > rear;
    }

    bool isFull() {
        return rear == capacity - 1;
    }

    void enqueue(int data) {
        if (isFull()) {
            cout << "Queue is full\n";
            return;
        }

        if (isEmpty()) {
            front = 0;
        }

        rear++;
        arr[rear] = data;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return;
        }

        front++;

        // Optional: reset when queue becomes empty
        if (front > rear) {
            front = rear = -1;
        }
    }

    int getFront() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return -1;
        }
        return arr[front];
    }

    void printQueue() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return;
        }

        for (int i = front; i <= rear; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    FixedQueue q(5);

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.printQueue();  // Output: 10 20 30

    q.dequeue();
    q.printQueue();  // Output: 20 30

    q.enqueue(40);
    q.enqueue(50);
    q.enqueue(60);   // fills the queue
    q.printQueue();  // Output: 20 30 40 50 60

    q.enqueue(70);   // Output: Queue is full
}
