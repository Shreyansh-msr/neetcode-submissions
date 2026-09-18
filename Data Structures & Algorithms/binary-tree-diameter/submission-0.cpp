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
    int depthOfBinaryTree(TreeNode* root) {
        if(!root) return -1;
        else return max({depthOfBinaryTree(root->left), depthOfBinaryTree(root->right)}) + 1;
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root) return -1;
        
        int depth = 2 + depthOfBinaryTree(root->left) + depthOfBinaryTree(root->right);

        return max({ depth, diameterOfBinaryTree(root->left), diameterOfBinaryTree(root->right)});
    }
};
