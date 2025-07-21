#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* prev;
    Node* next;

    Node(int value) {
        data = value;
        prev = NULL;
        next = NULL;
    }
};

// Print DLL from head to end
void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Insert at beginning
void insertAtStart(Node*& head, int data) {
    Node* newNode = new Node(data);
    newNode->next = head;
    if (head != NULL)
        head->prev = newNode;
    head = newNode;
}

// Insert at end
void insertAtLast(Node*& head, int data) {
    Node* newNode = new Node(data);
    if (head == NULL) {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->prev = temp;
}

// Delete from front
void deleteFromFront(Node*& head) {
    if (head == NULL) return;

    Node* temp = head;
    head = head->next;
    if (head != NULL)
        head->prev = NULL;
    delete temp;
}

// Reverse the DLL
void reverseList(Node*& head) {
    Node* curr = head;
    Node* prevNode = NULL;

    while (curr != NULL) {
        Node* nextNode = curr->next;
        curr->next = prevNode;
        curr->prev = nextNode;
        prevNode = curr;
        curr = nextNode;
    }

    head = prevNode;
}

// Find middle node
Node* findMidNode(Node* head) {
    Node* slow = head;
    Node* fast = head;

    while (fast != NULL && fast->next != NULL) {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}

// Get length
int getLength(Node* head) {
    int len = 0;
    while (head != NULL) {
        len++;
        head = head->next;
    }
    return len;
}
