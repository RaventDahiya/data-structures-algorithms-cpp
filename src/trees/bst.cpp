#include <iostream>
using namespace std;

// Tree node structure
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) {
        val = x;
        left = NULL;
        right = NULL;
    }
};

// Insert a node into BST
TreeNode* insert(TreeNode* root, int val) {
    if (root == NULL)
        return new TreeNode(val);

    if (val < root->val)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);

    return root;
}

// Build BST from user input
TreeNode* buildTree() {
    TreeNode* root = NULL;
    int n;
    cout << "Enter number of nodes to insert in BST: ";
    cin >> n;

    cout << "Enter " << n << " values: ";
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        root = insert(root, x);
    }
    return root;
}

// Inorder traversal
void inorder(TreeNode* root) {
    if (root == NULL) return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

int main() {
    TreeNode* root = buildTree();

    cout << "Inorder traversal of BST: ";
    inorder(root);
    cout << endl;

    return 0;
}
