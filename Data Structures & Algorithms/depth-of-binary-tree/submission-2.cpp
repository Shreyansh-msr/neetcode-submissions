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
    int Depth(TreeNode* root) {
        if(!root) return -1;
        else return max({Depth(root->left), Depth(root->right)}) + 1;
    }
    int maxDepth(TreeNode* root) {
        return Depth(root) + 1;
    }
};
