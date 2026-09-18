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
        // usning iterative depth first search
        if(!root) return 0;

        int maxDepth = 0;
        stack<pair<TreeNode*, int>> pendingNodes;

        pendingNodes.push({root, 1});

        while(!pendingNodes.empty()){
            auto[currNode, currDepth] = pendingNodes.top();
            pendingNodes.pop();

            maxDepth = max({maxDepth, currDepth});

            if(currNode->left) pendingNodes.push({currNode->left, currDepth+1});
            if(currNode->right) pendingNodes.push({currNode->right, currDepth+1});
        }
        return maxDepth;
    }
};
