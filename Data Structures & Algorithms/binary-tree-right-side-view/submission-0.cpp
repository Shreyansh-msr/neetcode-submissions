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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> sideView = {};
        queue<TreeNode*> nodes; //to implement BFS or level order Traversal

        if(root) nodes.push(root);

        while(!nodes.empty()) {
            int size = nodes.size(); // number of nodes in the current level
            for(int i=0; i<size; i++)
            {
                TreeNode* curr = nodes.front();
                nodes.pop();
                if(i==size-1) {
                    sideView.push_back(curr->val);
                }
                if(curr->left) nodes.push(curr->left);
                if(curr->right) nodes.push(curr->right);
            }
        }

        return sideView;
    }
};
