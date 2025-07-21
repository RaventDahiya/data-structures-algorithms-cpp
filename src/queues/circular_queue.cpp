#include <iostream>
using namespace std;

class FixedQueue {
    int* arr;
    int front;
    int rear;
    int size;
    int capacity;

public:
    FixedQueue(int cap) {
        capacity = cap;
        arr = new int[capacity];
        front = rear = -1;
        size = 0;
    }

    ~FixedQueue() {
        delete[] arr;
    }

    bool isEmpty() {
        return size == 0;
    }

    bool isFull() {
        return size == capacity;
    }

    void enqueue(int data) {
        if (isFull()) {
            cout << "Queue is full\n";
            return;
        }

        if (isEmpty()) {
            front = rear = 0;
        }
        else {
            rear = (rear + 1) % capacity;
        }

        arr[rear] = data;
        size++;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return;
        }

        if (front == rear) { // only one element
            front = rear = -1;
        }
        else {
            front = (front + 1) % capacity;
        }

        size--;
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

        int i = front;
        while (true) {
            cout << arr[i] << " ";
            if (i == rear) break;
            i = (i + 1) % capacity;
        }
        cout << endl;
    }
};

int main() {
    FixedQueue q(5);  // fixed size 5

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);

    q.printQueue();  // 10 20 30 40 50

    q.dequeue();
    q.dequeue();

    q.printQueue();  // 30 40 50

    q.enqueue(60);
    q.enqueue(70);   // fills the queue

    q.printQueue();  // 30 40 50 60 70

    q.enqueue(80);   // Queue is full
}
