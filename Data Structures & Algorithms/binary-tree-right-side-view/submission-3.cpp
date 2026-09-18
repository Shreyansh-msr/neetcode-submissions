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

// now impelementing this using  DFS
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> sideViewNodes = {}; // elements of vector are stored in HEAP memory and not destroyed like local variables in a function
        DFS(root, 0, sideViewNodes);
        return sideViewNodes;
    }

    void DFS(TreeNode* root, int depth, vector<int> &sideViewNodes) {
        if(!root) return;

        if(sideViewNodes.size() == depth){
            sideViewNodes.push_back(root->val);
        }

        DFS(root->right, depth + 1, sideViewNodes);
        DFS(root->left, depth + 1, sideViewNodes);
    }
};
