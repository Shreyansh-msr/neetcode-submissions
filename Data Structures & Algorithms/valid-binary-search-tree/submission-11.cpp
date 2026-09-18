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
    bool isValidBST(TreeNode* root) {
        return isValidSUB(root, INT_MIN, INT_MAX);
    }

    bool isValidSUB(TreeNode* root, int left_limit, int right_limit)
    {
        if(!root) return true;
        return left_limit < root->val && right_limit > root->val && isValidSUB(root->left, left_limit, root->val) && isValidSUB(root->right, root->val, right_limit);
    }
};
