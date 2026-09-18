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

 // observation -> the inorder traversal divides the array into left and right subtree

class Solution {
    public:
    TreeNode* buildTree(vector<int>&preorder, vector<int>&inorder) {
        int index = 0;
        return buildSubTree(preorder, inorder, 0, inorder.size()-1, &index);
    };
    public:
    TreeNode* buildSubTree(vector<int>&preorder, vector<int>&inorder, int left, int right, int *index) {

        // find the root node in the inorder-subarray
        
        int i=left;
        int j = *index;
        *index = (*index) + 1;
        while(inorder[i] != preorder[j]) i++;

        TreeNode * root = new TreeNode(preorder[j]);
        
        root -> left = ( left <= i - 1) ? buildSubTree(preorder, inorder, left, i-1, index) : nullptr;
        root -> right = (right >= i + 1) ? buildSubTree(preorder, inorder, i+1, right, index) : nullptr;

        return root;
    }
};