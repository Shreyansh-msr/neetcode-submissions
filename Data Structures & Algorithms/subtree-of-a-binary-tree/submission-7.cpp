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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        /*
        bool curr = isEquivalent(root, subRoot);
        bool left = isSubTree(root->left, subRoot);
        bool right = isSubTree(root->right, subroot);
        */
        return isEquivalent(root, subRoot) ||  (root && isSubtree(root->left, subRoot)) || (root && isSubtree(root->right, subRoot));
    }

public:
    bool isEquivalent(TreeNode* p, TreeNode* q) {
        if(!p && !q) return true; //basecase
        else if(!p && q || p && !q) return false; //basecase
        else return (p->val==q->val) && isEquivalent(p->left, q->left) && isEquivalent(p->right, q->right);
    }
};
