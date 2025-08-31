// Sample code for demonstration

#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        this->data = val;
        left = NULL;
        right = NULL;
    }
};

Node* createTree() {
    cout << "enter the value for node (-1) for NULL" << endl;
    int val;
    cin >> val;

    if (val == -1) return NULL;
    else {
        Node* root = new Node(val);
        cout << "left child of " << val << endl;
        root->left = createTree();
        cout << "right child of " << val << endl;
        root->right = createTree();
        return root;
    }

}

int main() {
    Node* root;
    root = createTree();
    return 0;
}