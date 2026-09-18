class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> permutation;
        vector<bool> available(nums.size(), true);
        backtrack(nums, available, permutation, res);
        return res;
    }
    void backtrack(const vector<int>& nums, vector<bool>& available, vector<int>& permutation, vector<vector<int>>& res) {
        if (permutation.size() == nums.size()) {
            res.push_back(permutation);
            return; 
        }

        for (int i = 0; i < nums.size(); i++) {
            if (available[i]) {
                available[i] = false; 
                permutation.push_back(nums[i]);
                backtrack(nums, available, permutation, res);
                permutation.pop_back();
                available[i] = true;
            }
        }
    }
};