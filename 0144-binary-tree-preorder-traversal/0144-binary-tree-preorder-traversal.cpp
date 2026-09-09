/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> pre;
        TreeNode* curr = root;
        TreeNode* prev = nullptr;
        stack<TreeNode*>st;
        while (curr || !st.empty()) {
            while (curr) {
                pre.push_back(curr->val);
                st.push(curr);
                curr = curr->left;
            }
            curr = st.top();
            if(curr->right && curr->right!=prev){
                curr = curr->right;
            }else{
                st.pop();
                prev = curr;
                curr = nullptr;
            }
        }

        return pre;
    }
};