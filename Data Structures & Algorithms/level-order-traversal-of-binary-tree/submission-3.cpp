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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> arr;
        queue<TreeNode*> nodeQueue;
        if(root) nodeQueue.push(root);
        
        while(!nodeQueue.empty()){
            int size = nodeQueue.size();
            vector<int> level;
            for(int i=0; i<size; i++) {

                TreeNode* curr = nodeQueue.front();
                nodeQueue.pop();

                level.push_back(curr->val);

                if(curr->left) nodeQueue.push(curr->left);
                if(curr->right) nodeQueue.push(curr->right);
            }
            arr.push_back(level);
        }
        return arr;
    }
};
