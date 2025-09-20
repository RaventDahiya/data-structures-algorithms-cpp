vector<int>morrisTraversal(Node* root) {
    vector<int>inorder;
    Node* curr = root;
    while (curr) {
        if (!curr->left) {
            inorder.push_back(curr->data);
            curr = curr->right;
        }
        else {
            Node* pred = curr->left;
            while (pred->right && pred->right != curr) {
                pred = pred->right;
            }
            if (!pred->right) {
                pred->right = curr;
                curr = curr->left;
            }
            else {
                pred->right = nullptr;
                inorder.push_back(curr->data);
                curr = curr->right;
            }
        }
    }
    return inorder;
}