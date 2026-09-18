class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> subset;
        dfs(nums, 0, subset, res);
        return res;
    }
    void dfs(const vector<int>&nums, int index, vector<int>&subset, vector<vector<int>>&res) {
        if(index >= nums.size())
        {
            res.push_back(subset);
            return;
        }

        subset.push_back(nums[index]);
        dfs(nums, index+1, subset, res);
        subset.pop_back();
        dfs(nums, index+1, subset, res);
    }
};
