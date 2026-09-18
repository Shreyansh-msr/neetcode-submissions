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

            TreeNode* curr = nodes.front();
            sideView.push_back(curr->val);

            int size = nodes.size(); 
            for(int i=0; i<size; i++)
            {
                curr = nodes.front();
                nodes.pop();
                if(curr->right) nodes.push(curr->right);
                if(curr->left) nodes.push(curr->left);
            }
        }

        return sideView;
    }
};
