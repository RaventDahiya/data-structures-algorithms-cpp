#include <iostream>
using namespace std;

class node {
public:
    int data;
    node* next;
    node(int data) {
        this->data = data;
        next = NULL;
    }
};

class queue {
public:
    node* front = NULL;
    node* rear = NULL;
    queue() {
        front = rear = NULL;
    }

    bool isEmpty() {
        return front == NULL;
    }

    void enqueue(int data) {
        node* newnode = new node(data);
        if (isEmpty()) {
            front = rear = newnode;
            return;
        }
        rear->next = newnode;
        rear = newnode;
    }

    void dequeue() {
        if (isEmpty()) {
            return;
        }
        node* temp = front;
        front = front->next;
        if (front == NULL) rear = NULL;
        delete temp;
    }

    void printqueue() {
        if (isEmpty()) {
            cout << "empty" << endl;
        }
        node* temp = front;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }
};

int main() {
    queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.printqueue();
    q.dequeue();
    q.printqueue();

}