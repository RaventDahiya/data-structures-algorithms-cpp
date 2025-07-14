// Sample code for demonstration

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

void printLinkList(node* temp) {
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void insertAtStart(node*& temp, int newData) {
    node* newNode = new node(newData);
    newNode->next = temp;
    temp = newNode;
}

void insertAtLast(node*& head, int newData) {
    node* newNode = new node(newData);
    if (head == NULL) {
        head = newNode;
        return;
    }
    node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

int nodeLen(node*& temp) {
    int count = 0;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
        count++;
    }
    return count;
}

void deleteNodeFromFront(node*& head) {
    node* temp = head->next;
    head = temp;
}

void reverseLinkList(node*& head) {
    node* prev = NULL;
    node* curr = head;
    node* next = NULL;

    while (curr != NULL) {
        next = curr->next;     // Save next node
        curr->next = prev;     // Reverse current node's link
        prev = curr;           // Move prev one step forward
        curr = next;           // Move curr one step forward
    }

    head = prev;  // Update head to new first node
}

node* findMidNode(node*& head) {
    node* slow = head;
    node* fast = head;
    while (fast->next != NULL && fast->next->next != NULL) {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}

int main() {
    cout << "Sample code for this data structure." << endl;
    node* n1 = new node(5);
    node* n2 = new node(10);
    node* n3 = new node(15);
    node* head = n1;
    n1->next = n2;
    n2->next = n3;
    printLinkList(head);
    insertAtStart(head, 0);
    insertAtStart(head, -1);
    printLinkList(head);
    insertAtLast(head, 20);
    printLinkList(head);
    //cout<<nodeLen(head);
    deleteNodeFromFront(head);
    printLinkList(head);
    reverseLinkList(head);
    printLinkList(head);
    node* mid = findMidNode(head);
    cout << mid->data;
    return 0;
}