#include <iostream>
using namespace std;

class node {
public:
    int data;
    node* next;
    node(int value) {
        data = value;
        next = NULL;
    }
};

int nodeLen(node* temp) {
    int count = 0;
    while (temp != NULL) {
        // cout << temp->data << " "; // don't print here
        temp = temp->next;
        count++;
    }
    return count;
}

node* insertAtHead(node*& head, node*& tail, int data) {
    node* newNode = new node(data);
    if (head == NULL && tail == NULL) {
        head = newNode;
        tail = newNode;
        return head;
    }
    newNode->next = head;
    head = newNode;
    return head;
}

node* insertAtTail(node*& head, node*& tail, int data) {
    node* newNode = new node(data);
    if (head == NULL && tail == NULL) {
        head = newNode;
        tail = newNode;
        return head;
    }
    tail->next = newNode;
    tail = newNode;
    return head;
}

node* insertAtPosition(node*& head, node*& tail, int data, int pos) {
    int len = nodeLen(head);
    if (pos < 1 || pos > len + 1) {
        cout << "Invalid position!" << endl;
        return head;
    }
    if (pos == 1) {
        return insertAtHead(head, tail, data);
    }
    if (pos == len + 1) {
        return insertAtTail(head, tail, data);
    }
    node* temp = head;
    int i = 1;
    while (i != pos - 1) {
        i++;
        temp = temp->next;
    }
    node* newNode = new node(data);
    newNode->next = temp->next;
    temp->next = newNode;
    return head;
}

bool linearSearch(node* head, int target) {
    node* temp = head;
    while (temp != NULL) {
        if (temp->data == target) {
            return true;
        }
        temp = temp->next;
    }
    return false;
}
void printList(node* head) {
    node* temp = head;
    while (temp != NULL) {
        cout << temp->data << "-> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}
void deleteAtPosition(node*& head, node*& tail, int pos) {
    if (head == NULL) {
        cout << "List is empty. Nothing to delete." << endl;
        return;
    }

    int len = nodeLen(head);

    if (pos < 1 || pos > len) {
        cout << "Invalid position!" << endl;
        return;
    }

    // Deleting the head node
    if (pos == 1) {
        node* delNode = head;
        head = head->next;
        // If list had only one node
        if (head == NULL) {
            tail = NULL;
        }
        delete delNode;
        return;
    }

    // Deleting node at position > 1
    node* temp = head;
    int count = 1;
    // Move to the node just before the target position
    while (count < pos - 1) {
        temp = temp->next;
        count++;
    }

    node* delNode = temp->next;
    temp->next = delNode->next;

    // If deleted node was tail, update tail
    if (delNode == tail) {
        tail = temp;
    }

    delete delNode;
}

int main() {
    node* head = NULL;
    node* tail = NULL;
    head = insertAtHead(head, tail, 0);
    head = insertAtHead(head, tail, 1);
    head = insertAtHead(head, tail, 2);
    head = insertAtPosition(head, tail, 12, 3);
    head = insertAtPosition(head, tail, 122, 1);
    head = insertAtPosition(head, tail, 1223, 6);
    printList(head);
    int searchVal = 12;
    if (linearSearch(head, searchVal))
        cout << searchVal << " found in list\n";
    else
        cout << searchVal << " not found in list\n";
    return 0;
}
