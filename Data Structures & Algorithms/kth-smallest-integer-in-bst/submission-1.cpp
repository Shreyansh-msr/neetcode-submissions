/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        stack<int> st;
        buildStack(root, st);
        for(int i=1; i<k; i++){
            st.pop();
        }
        return st.top();
    }

    void buildStack(TreeNode* root, stack<int> &st){
        if(!root) return;
        buildStack(root->right, st);
        st.push(root->val);
        buildStack(root->left, st);
    }
};
