#include <iostream>
#include <queue>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = NULL;
        right = NULL;
    }
};

// Build tree from user input using -1 for NULL
Node* buildTree() {
    int value;
    cin >> value;

    if (value == -1) return NULL;

    Node* root = new Node(value);
    cout << "Enter left child of " << value << ": ";
    root->left = buildTree();

    cout << "Enter right child of " << value << ": ";
    root->right = buildTree();

    return root;
}

// Inorder traversal
void inorder(Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
void preorder(Node* root) {
    if (root == NULL) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node* root) {
    if (root == NULL) return;

    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

int tree_height(Node* root) {
    if (root == NULL) return 0;
    int left_height = tree_height(root->left);
    int right_height = tree_height(root->right);
    return max(left_height, right_height) + 1;
}

void print_level(Node* root, int level) {
    if (root == NULL) return;
    if (level == 1) {
        cout << root->data << " ";
    }
    else {
        print_level(root->left, level - 1);
        print_level(root->right, level - 1);
    }
}

void level_wise(Node* root) {
    int h = tree_height(root);
    for (int i = 1; i <= h; i++) {
        print_level(root, i);
        cout << endl; // Optional: print each level on a new line
    }
}

void level_wise_using_queue(Node* root) {
    if (root == NULL) return;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();

        cout << temp->data << " ";

        if (temp->left != NULL)
            q.push(temp->left);

        if (temp->right != NULL)
            q.push(temp->right);
    }
}
int main() {
    cout << "Enter values to build the tree (-1 for NULL):\n";
    Node* root = buildTree();

    cout << "Inorder Traversal: ";
    inorder(root);
    cout << endl;
    cout << "preorder Traversal: ";
    preorder(root);
    cout << endl;
    cout << "postorder Traversal: ";
    postorder(root);
    cout << endl;
    cout << "hight" << tree_hight(root);

    return 0;
}
