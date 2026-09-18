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
    bool isSameTree(TreeNode* p, TreeNode* q) { // using iterative depth first search
    // using breadth first search

    queue<pair<TreeNode*, TreeNode*>> nodeQueue;
    if(p && q) nodeQueue.push({p,q});
    else if(!p && !q) return true;
    else return false;

    while(!nodeQueue.empty()) {
        auto[n1, n2] = nodeQueue.front();
        if(n1->val != n2->val) return false;
        nodeQueue.pop();

        if(n1-> left && n2->left) nodeQueue.push({n1->left, n2->left});
        else if(!n1->left && !n2->left) {}
        else return false;

        if(n1->right && n2->right) nodeQueue.push({n1->right, n2->right});
        else if(!n1->right && !n2->right) {}
        else return false;
    }
        return true;
    }
};
