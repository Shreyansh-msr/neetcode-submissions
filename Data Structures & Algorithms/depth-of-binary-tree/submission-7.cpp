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
    int maxDepth(TreeNode* root) {
        if(!root) return 0;

        queue<TreeNode*> pendingNodes;
        pendingNodes.push(root);

        int depth = 0;

        while(!pendingNodes.empty()) {
            depth ++;
            int size = pendingNodes.size(); // capture the size of the current level
            for(int i=0; i<size; i++)
            {
                TreeNode * curr = pendingNodes.front();
                pendingNodes.pop();
                if(curr->left) pendingNodes.push(curr->left);
                if(curr->right) pendingNodes.push(curr->right);
            }
        }
        return depth;
    }
};
