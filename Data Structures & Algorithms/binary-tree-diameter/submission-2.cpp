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
    int DFS(TreeNode* root, int* res) {
        if(!root) return 0;
        
        int left_depth = DFS(root->left, res);
        int right_depth = DFS(root->right, res);
        
        *res = max(*res, left_depth+right_depth);
        return max(left_depth, right_depth) + 1;

    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int res = 0;
        DFS(root, &res);
        return res;
    }
};
