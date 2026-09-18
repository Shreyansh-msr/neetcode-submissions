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
private:
    int DFS(TreeNode* root, bool* res){
        if(!root) return -1;

        int left_subtree_depth = DFS(root->left, res);
        int right_subtree_depth = DFS(root->right, res);

        *res = *res && abs(left_subtree_depth - right_subtree_depth) <= 1;

        return max(left_subtree_depth, right_subtree_depth) + 1;
    }
public:
    bool isBalanced(TreeNode* root) {
        bool res = true;
        DFS(root, &res);
        return res;
    }
};
