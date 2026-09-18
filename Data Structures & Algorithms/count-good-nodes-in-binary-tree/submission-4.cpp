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
    int goodNodes(TreeNode* root) {
        if(!root) return 0;
        
        return nGoodNode(root, root->val);
    }
public:
    int nGoodNode(TreeNode* root, int maxAncestor){
        if(!root) return 0;

        int add = 0;

        if(root->val >= maxAncestor) {
            add = 1;
        }

        maxAncestor = max(maxAncestor, root->val);
        return add + nGoodNode(root->left, maxAncestor) + nGoodNode(root->right, maxAncestor);
    }
};
// there is no backward link between a child node and parent node;
// no point of breadth first search..